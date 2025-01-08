#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct BinarySearchTree{
    struct Node *root;
};

struct Node *createNode(int data);

void insert(struct BinarySearchTree *BST);

int main(){
    int data,choice;

}