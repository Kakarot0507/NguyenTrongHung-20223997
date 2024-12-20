#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100

typedef struct Node {
    char title[MAX_TITLE_LEN];
    char type[20]; // Chapter, Section, ...
    int startPage;
    int endPage;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

//Node* createNode(char* title, char* type, int startPage, int endPage) { //tao node moi
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    strcpy(newNode->type, type);
    newNode->startPage = startPage;
    newNode->endPage = endPage;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}
//int countChapters(Node* root) // dem so chuong
    if (root == NULL) return 0;
    int count = (strcmp(root->type, "Chapter") == 0) ? 1 : 0;
    for (Node* child = root->firstChild; child != NULL; child = child->nextSibling) {
        count += countChapters(child);
    }
    return count;
}
//Node* findLongestChapter(Node* root) {// tim chuong dai nhat
    if (root == NULL) return NULL;
    Node* longest = NULL;
    int maxPages = 0;
    if (strcmp(root->type, "Chapter") == 0 && root->endPage - root->startPage + 1 > maxPages) {
        longest = root;
        maxPages = root->endPage - root->startPage + 1;
    }
    for (Node* child = root->firstChild; child != NULL; child = child->nextSibling) {
        Node* temp = findLongestChapter(child);
        if (temp != NULL && temp->endPage - temp->startPage + 1 > maxPages) {
            longest = temp;
            maxPages = temp->endPage - temp->startPage + 1;
        }
    }
    return longest;
}
