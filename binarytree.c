#include <stdio.h>
#include <stdlib.h>
typedef struct bnode
{
    struct bnode *left;
    int info;
    struct bonde *right;
} bnode;
void insert_in_bst(bnode **r, int item)
{
    bnode *temp;
    temp = (bnode *)malloc(sizeof(bnode));
    if (temp == NULL)
    {
        printf("memory is full");
        return;
    }
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;
    if (*r == NULL)
    {
        *r = temp;
        return;
    }
    bnode *current, *parent;
    for (current = *r, parent = NULL; current != NULL;)
    {
        parent = current;
        if (item < current->info)
            current = current->left;
        else
            current = current->right;
    }

    if (item < parent->info)
        parent->left = temp;
    else
        parent->right = temp;
}