#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct EdgeList *edgeList;
};
struct EdgeList
{
    struct Node *dest;
    struct EdgeList *nextEdge;
};

struct Stack
{
    struct Node *node;
    struct Stack *next;
};
struct VisitedNode
{
    int data;
    struct VisitedNode *next;
};

struct Node *root = NULL;
struct Stack *S_head = NULL;
struct VisitedNode *V_head = NULL;

void insertVertex(int data);
void insertEdge(int source, int dest);
void display();
void DepthFirstSearch(struct Node *root, struct Node *nodeAddress);
struct Node *searchNodeAddress(int node);

void push(struct Node *nodeAddress);
void pop(struct Stack *temp);
struct Stack *peek(struct Stack *S_head);


void Visited_Node(int data);
void display_Visited_Node(struct VisitedNode *V_head);
int is_nodeVisited(int data);
void delete_visited_Node(struct VisitedNode *V_head);
int main()
{
    int data, choice, source, dest, node;
    do
    {
        printf("\n 0: Exit");
        printf("\n 1: insert vertex");
        printf("\n 2: insert edge");
        printf("\n 3: display");
        printf("\n 4: DFS");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 0:
            exit(0);
        case 1:
            printf("\n Enter data: ");
            scanf("%d", &data);
            insertVertex(data);
            break;

        case 2:
            printf("\n Enter source: ");
            scanf("%d", &source);
            printf("\n Enter dest: ");
            scanf("%d", &dest);
            insertEdge(source, dest);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\n Enter the node: ");
            scanf("%d", &node);
            struct Node *nodeAddress = searchNodeAddress(node);
            DepthFirstSearch(root, nodeAddress);
            break;
            ;

        default:
            printf("\n invalid input");
            break;
        }
    } while (choice != 0);
    return 0;
}
void insertVertex(int data)
{
    if (root == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("%x", newNode);
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            newNode->data = data;
            newNode->next = NULL;
            newNode->edgeList = NULL;
            root = newNode;
        }
    }
    else
    {
        struct Node *temp = root;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            newNode->data = data;
            newNode->next = NULL;
            newNode->edgeList = NULL;
            temp->next = newNode;
        }
    }
}
void insertEdge(int source, int dest)
{
    struct Node *temp = root, *temp1, *temp2;

    while (temp != NULL)
    {
        if (temp->data == source)
            temp1 = temp;

        if (temp->data == dest)
            temp2 = temp;

        temp = temp->next;
    }

    if (temp1 == NULL || temp2 == NULL)
    {
        printf("\n Either source or dest not create");
    }
    else
    {
        if (temp1->edgeList == NULL)
        {
            struct EdgeList *newEdgeList = (struct EdgeList *)malloc(sizeof(struct EdgeList));
            if (newEdgeList == NULL)
            {
                printf("\n Unable to allocate the memory");
            }
            else
            {
                newEdgeList->dest = temp2;
                newEdgeList->nextEdge = NULL;
                temp1->edgeList = newEdgeList;
            }
        }
        else
        {
            struct EdgeList *temp3 = temp1->edgeList;
            while (temp3->nextEdge != NULL)
            {
                temp3 = temp3->nextEdge;
            }
            struct EdgeList *newEdgeList = (struct EdgeList *)malloc(sizeof(struct EdgeList));
            if (newEdgeList == NULL)
            {
                printf("\n Unable to allocate the memory");
            }
            else
            {
                newEdgeList->dest = temp2;
                newEdgeList->nextEdge = NULL;
                temp3->nextEdge = newEdgeList;
            }
        }
    }
}

void display()
{
    struct Node *temp1 = root, *temp2;
    struct EdgeList *temp3;
    while (temp1 != NULL)
    {
        temp2 = temp1;
        printf("%d\t", temp1->data);
        temp3 = temp1->edgeList;
        while (temp3 != NULL)
        {
            printf("%d \t ", temp3->dest->data);
            temp3 = temp3->nextEdge;
        }
        printf("\n");
        temp1 = temp2->next;
    }
}
void DepthFirstSearch(struct Node *root, struct Node *nodeAddress)
{
    struct Node *temp;
    // 1. create a stack
    push(nodeAddress);
   // Visited_Node(nodeAddress->data);
    while (stackEmpty(S_head))
    {
      
        struct Stack *temp1 = peek(S_head);
        //printf("%x",temp1->node->data);
        printf("%x\n",temp1);
        Visited_Node(temp1->node->data);
        struct Node *temp2 = temp1->node;
        struct EdgeList *temp3 = temp2->edgeList;
        while (temp3 != NULL)
        {
            if (is_nodeVisited(temp3->dest->data))
            {
                push(temp3->dest);
                //Visited_Node(temp3->dest->data);
            }
            temp3 = temp3->nextEdge;
        }
        printf("%x\n",temp1);
        pop(temp1);
        
        
    }
    display_Visited_Node(V_head);
}
struct Node *searchNodeAddress(int node)
{
    struct Node *temp1 = root;
    while (temp1 != NULL)
    {
        if (temp1->data == node)
        {
            return temp1;
        }
        temp1 = temp1->next;
    }
}
int stackEmpty(struct Stack *S_head)
{
    if (S_head == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void push(struct Node *nodeAddress)
{
    if (S_head == NULL)
    {
        struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            newNode->node = nodeAddress;
            newNode->next = NULL;
            S_head=newNode;
        }
    }
    else
    {
        struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }

        struct Stack *temp1 = S_head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }

        newNode->node = nodeAddress;
        newNode->next = NULL;
        temp1->next = newNode;
    }
}

void Visited_Node(int data)
{
    if (V_head == NULL)
    {
        struct VisitedNode *newVisitedNode = (struct VisitedNode *)malloc(sizeof(struct VisitedNode));
        if (newVisitedNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            newVisitedNode->data = data;
            newVisitedNode->next = NULL;
            V_head = newVisitedNode;
        }
    }
    else
    {
        struct VisitedNode *newVisitedNode = (struct VisitedNode *)malloc(sizeof(struct VisitedNode));
        if (newVisitedNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            struct VisitedNode *temp = V_head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newVisitedNode->data = data;
            newVisitedNode->next = NULL;
            temp->next = newVisitedNode;
        }
    }
}
void pop(struct Stack *temp)
{
    if (S_head == NULL)
    {
        printf("\n Stack is empty");
    }
    else if(S_head==temp){
        struct Stack *temp1=S_head;
        S_head=temp1->next;
        free(temp1);
        //S_head=NULL;
    }
    else
    {
        struct Stack *temp1 = S_head, *temp2 = NULL;
        while (temp1->next != temp)
        {
            temp2 = temp1;
            temp1 = temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);

        printf("%x\n",temp1->next);
       // printf("%x\n",temp2->next);
        /*
        if (temp1 != NULL && temp2 == NULL)
        {
            printf("%d\n", temp1->next);
            free(temp1);
            S_head = NULL;
            
        }
        else
        {
            printf("%d\n", temp1->next);
            free(temp1);
            temp2->next = NULL;
        }*/
    }
}
void display_Visited_Node(struct VisitedNode *V_head)
{
    if (V_head == NULL)
    {
        printf("\n Visited list is empty");
    }
    else
    {
        struct VisitedNode *temp1 = V_head;
        while (temp1 != NULL)
        {
            printf("%d", temp1->data);
            printf(" -> ");
            temp1 = temp1->next;
        }
    }
    delete_visited_Node(V_head);
}

int is_nodeVisited(int data)
{
    struct VisitedNode *temp = V_head;
    int flag = 1;
    while (temp->next != NULL)
    {
        if (temp->data == data)
        {
            flag = 0;
            break;
        }

        temp = temp->next;
    }
    return flag;
}

void delete_visited_Node(struct VisitedNode *V_head)
{
    
    if (V_head == NULL)
    {
        printf("\n List is empty");
    }
    else
    {
        struct VisitedNode *temp1 = V_head, *temp2;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            temp1 = temp1->next;
            free(temp2);
        }
        V_head = NULL;
    }
}

struct Stack *peek(struct Stack *S_head){
    if(S_head==NULL){
        return NULL;
    }
    else{
        struct Stack *temp1=S_head;
        while(temp1->next!=NULL){
            temp1=temp1->next;
        }
        return temp1;
    }
}