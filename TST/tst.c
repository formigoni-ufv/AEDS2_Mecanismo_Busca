#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tst.h"

// A utility function to create a new ternary search tree node
Pointer newNode(char data)
{
    Pointer temp = (Pointer) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = NULL;
    return temp;
}

// Function to insert a new word in a Ternary Search Tree
void insertTST(Pointer* root, char *word)
{
    // Base Case: Tree is empty
    if (!(*root))
        *root = newNode(*word);

    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if ((*word) < (*root)->data)
        insertTST(&( (*root)->left ), word);

    // If current character of word is greate than root's character,
    // then insert this word in right subtree of root
    else if ((*word) > (*root)->data)
        insertTST(&( (*root)->right ), word);

    // If current character of word is same as root's character,
    else
    {
        if (*(word+1))
            insertTST(&( (*root)->eq ), word+1);

        // the last character of the word
        else
            (*root)->isEndOfString = 1;
    }
}

// A recursive function to traverse Ternary Search Tree
void autoCompleteUtil(Pointer root, char* buffer, int depth, char *word)
{
    int cont = 0, i = 0, size = 0;
    size = strlen(word);

    if (root)
    {
        // First traverse the left subtree
        autoCompleteUtil(root->left, buffer, depth, word);

        // Store the character of this node
        buffer[depth] = root->data;

        // Verify if the node is a string and compare with the input (prefix)
        // informed, if true, the algorithm print the string
        if (root->isEndOfString){
            for(i = 0; i < size; i++){
                if(word[i] == buffer[i])
                    cont++;
            }
            buffer[depth+1] = '\0';
            if(cont == size)
                printf( "%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        autoCompleteUtil(root->eq, buffer, depth + 1, word);

        // Finally Traverse the right subtree
        autoCompleteUtil(root->right, buffer, depth, word);
    }
}

// The main function to traverse a Ternary Search Tree.
// It mainly uses traverseTSTUtil()
void autoComplete(Pointer root, char *word)
{
    char buffer[MAX];
    autoCompleteUtil(root, buffer, 0, word);
}

/*
// Function to search a given word in TST
int searchTST(Pointer root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->data)
        return searchTST(root->left, word);

    else if (*word > (root)->data)
        return searchTST(root->right, word);

    else
    {
        if (*(word+1) == '\0')
            return root->isEndOfString;

        return searchTST(root->eq, word+1);
    }
}*/
