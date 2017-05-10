#ifndef TST_H_INCLUDED
#define TST_H_INCLUDED
#define MAX 50

typedef struct Node* Pointer;

// A node of ternary search tree
typedef struct Node {
    char data;
    // True if this character is last character of one of the words
    unsigned isEndOfString: 1;
    Pointer left, eq, right;
}Node;

Pointer newNode(char data);
void insertTST(Pointer* root, char *word);
void autoCompleteUtil(Pointer root, char* buffer, int depth, char *word);
void autoComplete(Pointer root, char *word);
//int searchTST(Pointer root, char *word);

#endif // TST_H_INCLUDED
