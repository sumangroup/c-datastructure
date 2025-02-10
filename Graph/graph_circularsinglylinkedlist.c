#include<stdio.h>
#include<stdlib.h>

struct EdgeList{
    struct Node *node;
    struct EdgeList *nextedge;
};
struct Node
{
    int data;
    struct Node *next;
    struct EdgeList *edgelist;
};

static int count = 0;
struct Node *head=NULL;
struct Node *createNode(int data, struct Node *next,struct EdgeList *headedgelist);
void createHeadNode(int data);

void display(struct Node *temp);
void insertAtEnding(struct Node *temp, int data);
void addNode(struct Node *temp, int data);
struct Node *searchNode(struct Node *temp,int searchData);

void addEdge(struct Node *startNode,struct Node *endNode,struct EdgeList *edgelist);
struct EdgeList *createEdgelist(struct Node *endNode,struct EdgeList *next);
void createHeadNode_edgelist(struct Node *startNode,struct Node *endNode);
void display_edgelist(struct Node *startNode,struct EdgeList *temp);

int main(){
    int data,choice,start,end;
    struct Node *startNode,*endNode;
    do
    {
        printf("\n 0: exit");
        printf("\n 1: display");
        printf("\n 2: insert node");
        printf("\n 3: insert edge");
        printf("\n Enter the choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 0:
            exit(0);
            break;
        
        case 1:
            display(head);
            break;

        case 2:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            addNode(head,data);
            break;
        
        case 3:
            printf("\n Enter the start node: ");
            scanf("%d",&start);
            startNode=searchNode(head,start);
            printf("startnode: %x",startNode);
            printf("\n Enter the end node: ");
            scanf("%d",&end);
            endNode=searchNode(head,end);
            printf("endnode: %x",endNode);
            addEdge(startNode,endNode,startNode->edgelist);
            break;
        default:
            break;
        }
    } while (choice!=0);
    
    return 0;
}

void display(struct Node *temp)
{
    if (head == NULL)
    {
        printf("\n Graph is empty");
    }
    else if (head == temp->next)
    {
        printf("\n%d: ",temp->data);
        display_edgelist(temp,temp->edgelist);
    }
    else
    {
        printf("\n%d: ", temp->data);
        display_edgelist(temp,temp->edgelist);
        display(temp->next);
    }
}

void display_edgelist(struct Node *startNode,struct EdgeList *temp){
    if(temp==NULL){
         //printf("\n edge list is empty");
    }
    else if(startNode->edgelist==temp->nextedge){
        printf("\t%d",temp->node->data);
    }
    else{
        printf("\t%d",temp->node->data);
        display_edgelist(startNode,temp->nextedge);
    }

}
struct Node *createNode(int data, struct Node *next,struct EdgeList *headedgelist)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->next = next;
        newNode->edgelist=NULL;
    }
    return newNode;
}



void createHeadNode(int data)
{
    struct Node *newNode = createNode(data, NULL,NULL);
    if (newNode == NULL)
    {
        printf("\n unable to allocate the memory");
    }
    else
    {
        head = newNode;
        newNode->next = newNode;
        newNode->edgelist=NULL;
        count++;
    }
}

void insertAtEnding(struct Node *temp, int data)
{
    if (head == NULL)
    {
        createHeadNode(data);
    }
    else if (head == temp->next)
    {
        struct Node *newNode = createNode(data, head,NULL);
        if (newNode == NULL)
        {
            printf("\n unable to allocate the memory");
        }
        else
        {
            temp->next = newNode;
            count++;
        }
    }
    else
    {
        insertAtEnding(temp->next, data);
    }
}

void addNode(struct Node *temp, int data){
    insertAtEnding(temp,data);
}



struct Node *searchNode(struct Node *temp,int searchData){
     if(head==NULL){
        printf("\n Graph is empty");
    }
    else if((temp->data==searchData) ){
        return temp;
    }
    else if(temp->next==head){

    }
    else{
        searchNode(temp->next,searchData);
    }
}


void addEdge(struct Node *startNode,struct Node *endNode,struct EdgeList *edgelist){
    if(edgelist==NULL){
        createHeadNode_edgelist(startNode,endNode);
    }
    else if(startNode->edgelist==edgelist->nextedge){
        struct EdgeList *newedge=createEdgelist(endNode,startNode->edgelist);
        if(newedge==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            edgelist->nextedge=newedge;
        }
    }
    else{
        addEdge(startNode,endNode,edgelist->nextedge);
    }
    
}

void createHeadNode_edgelist(struct Node *startNode,struct Node *endNode){
    struct EdgeList *newedge=createEdgelist(endNode,NULL);
    if(newedge==NULL){
        printf("\n unable to allocate the memory");
    }
    else{
        newedge->nextedge=newedge;
        startNode->edgelist=newedge;
    }
}

struct EdgeList *createEdgelist(struct Node *endNode,struct EdgeList *next){
    struct EdgeList *newEdge=(struct EdgeList*)malloc(sizeof(struct EdgeList));
    if(newEdge!=NULL){
        newEdge->node=endNode;
        newEdge->nextedge=next;
    }
}