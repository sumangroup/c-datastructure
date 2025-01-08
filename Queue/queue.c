#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL,*rear=NULL;
void enqueue(int data);
void dequeue();
void display();
void display_front_rear();
int main(){
    int data,choice;
    do
    {
        printf("\n 0: exit");   
        printf("\n 1: display");
        printf("\n 2: enqueue");
        printf("\n 3: enqueue");
        printf("\n 4: display front and rear");
        printf("\n Enter the choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            exit(0);
        
        case 1:
            display();
            break;

        case 2:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            enqueue(data);
            break;

        case 3:
            dequeue();
            break;
        
        case 4:
            display_front_rear();
        default:
            break;
        }
    } while (choice!=0);
    
    return 0;
}
void enqueue(int data){
    if(front==NULL){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            front=newNode;
            rear=newNode;
           
        }
    }
    else{
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        newNode->data=data;
        newNode->next=NULL;
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue(){
    if(front==NULL){
        printf("\n Underflow");
    }
    else{
        struct Node *temp=front;
        front=front->next;
        free(temp);
    }
}

void display(){
    if(front==NULL){
        printf("\n Queue is empty");
    }
    else{
        struct Node *temp=front;
        while(temp!=NULL){
            printf("%d\t ",temp->data);
            temp=temp->next;
        }
    }
}

void display_front_rear(){
    printf("\nfront: %x: ",front);
    printf("\rear: %x: ",rear);
}