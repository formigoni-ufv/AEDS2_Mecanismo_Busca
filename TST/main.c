// C program to suggest words stored based in prefix inputs
#include <stdio.h>
#include <stdlib.h>
#include "tst.h"
#include "tst.c"

// Driver program to test above functions
int main()
{
    struct Node *root = NULL;

    insertTST(&root, "cat");
    insertTST(&root, "cats");
    insertTST(&root, "cast");
    insertTST(&root, "cavalo");
    insertTST(&root, "catene");
    insertTST(&root, "up");
    insertTST(&root, "bug");

    printf("Suggested words with the prefix\n");
    autoComplete(root, "cat");

    /*
    printf("\nFollowing are search results for cats, bu and cat respectively\n");
    searchTST(root, "cats")?    printf("Found\n"):  printf("Not Found\n");
    searchTST(root, "bu")?      printf("Found\n"):  printf("Not Found\n");
    searchTST(root, "cat")?     printf("Found\n"):  printf("Not Found\n");
    */
    return 0;
}
