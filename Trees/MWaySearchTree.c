#include <stdio.h>
#include <stdlib.h>
#define M 5
struct Node
{
    int keys[M - 1];
    int *children[M];
    int count;
};
struct Node *root = NULL;
void insertNonFull(struct Node *root, int data)
{
    struct Node *temp = root;
    int i, j, k;
    for (i = 0; i < temp->count; i++)
    {
        if (data < temp->keys[i])
        {
            break;
        }
    }
    k = i;
    j = temp->count - 1;
    while (j >= i)
    {
        temp->keys[j + 1] = temp->keys[j];
        temp->children[j + 1] = temp->children[j];
        j = j - 1;
    }
    temp->keys[k] = data;
    temp->children[k] = NULL;
    temp->count++;
}
void insert(struct Node *root, int data)
{
    if (root == NULL)
    {
        int i;
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n unable to allocate memory");
        }
        else
        {
            newNode->keys[0] = data;
            for (i = 0; i < M; i++)
            {
                newNode->children[i] = NULL;
            }
            newNode->count++;
            root = newNode;
        }
    }
    else
    {
        struct Node *temp = root;
        if (temp->count == M - 1)
        {
            int i = 0;
            for (i = 0; i < temp->count + 1; i++)
            {
                if (data < temp->keys[i] && temp->children[i] == NULL)
                {
                    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                    if (newNode == NULL)
                    {
                        printf("\n unable to allocate the memory");
                    }
                    else
                    {
                        int j = 0;
                        newNode->keys[0] = data;
                        for (j = 0; j < M; j++)
                        {
                            newNode->children[j] = NULL;
                        }
                        newNode->count++;
                        temp->children[i] = newNode;
                        break;
                    }
                } // 1. condition
                else if (data < temp->keys[i] && temp->children[i] != NULL)
                {
                    temp = temp->children[i];
                    if (temp->count != M - 1)
                    {
                        insertNonFull(temp, data);
                        break;
                    }
                    i = 0;
                    continue;
                }
                else if (i == M - 1)
                {
                    if (temp->children[i] == NULL)
                    {
                        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
                        if (newNode == NULL)
                        {
                            printf("\n unable to allocate the memory");
                        }
                        else
                        {
                            int j = 0;
                            newNode->keys[0] = data;
                            for (j = 0; j < M; j++)
                            {
                                newNode->children[j] = NULL;
                            }
                            newNode->count++;
                            temp->children[i] = newNode;
                            break;
                        }
                    }
                    else if (temp->children[i] != NULL)
                    {
                        temp = temp->children[i];
                        if (temp->count != M - 1)
                        {
                            insertNonFull(temp, data);
                            break;
                        }
                        i = 0;
                        continue;
                    }
                }
            } // for loop
        }
        else
        {
            insertNonFull(root, data);
        }
    }
}
int main()
{
    insert(root, 18);
    return 0;
}