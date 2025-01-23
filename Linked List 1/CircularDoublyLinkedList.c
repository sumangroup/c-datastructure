#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head=NULL;
static int count=0;
void insertAtBeginning(struct Node *temp,int data);
void insertAtEnding(struct Node *temp,int data);
void insertAfterLocation(struct Node *temp,int loc,int i,int data);
void insertBeforeLocation(struct Node *temp,int loc,int i,int data);
void insertAfterData(struct Node *temp,int searchData,int data);
void insertBeforeData(struct Node *temp,int searchData,int data);
void createHeadNode(int data);
struct Node *createNode(struct Node *prev,int data,struct Node *next);
void display(struct Node *temp);
void totalNode();
int main()
{
    int data,choice,loc,searchData;

    do
    {
       printf("\n 0: exit");
       printf("\n 1: display");
       printf("\n 2: insert at beginning");
       printf("\n 3: insert at ending");
       printf("\n 4: total node");
       printf("\n 5: insert atfter location");
       printf("\n 6: insert before location");
       printf("\n 7: insert after data");
       printf("\n 8: insert before data");
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
            insertAtBeginning(head,data);
            break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertAtEnding(head,data);
            break;

        case 4:
            totalNode();
            break;

        case 5:
            printf("\n Enter the location: ");
            scanf("%d",&loc);
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertAfterLocation(head,loc,1,data);
            break;

        case 6:
            printf("\n Enter the location: ");
            scanf("%d",&loc);
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertBeforeLocation(head,loc,1,data);
            break;
        
        case 7:
            printf("\n Enter the searchData: ");
            scanf("%d",&searchData);
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertAfterData(head,searchData,data);
            break;

        case 8:
            printf("\n Enter the searchData: ");
            scanf("%d",&searchData);
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertBeforeData(head,searchData,data);
            break;
       default:
        break;
       }
    } while (choice!=0);
    
    return 0;
}

void insertAtBeginning(struct Node *temp,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(temp->next==head){
        struct Node *temp1=temp->next;
        struct Node *newNode=createNode(temp1,data,temp1);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            /*newNode->prev=temp1;
            newNode->next=temp1;*/
            temp1->prev=newNode;
            temp->next=newNode;
            head=newNode;
            count++;
        }
    }
    else{
        insertAtBeginning(temp->next,data);
    }
}

void createHeadNode(int data){
    struct Node *newNode=createNode(NULL,data,NULL);
    if(newNode==NULL){
        printf("\n Unable to allocate the memory");
    }
    else{
        newNode->prev=newNode;
        newNode->next=newNode;
        head=newNode;
        count++;
       
    }

}
struct Node *createNode(struct Node *prev,int data,struct Node *next){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    if(newNode!=NULL){
        newNode->prev=prev;
        newNode->data=data;
        newNode->next=next;
    }
    return newNode;
}
void display(struct Node *temp){
    if(head==NULL){
        printf("\n Doubly circular linked list empty");
    }
    else if(temp->next==head){
        printf("%d\t",temp->data);
    }   
    else{
        printf("%d\t",temp->data);
        display(temp->next);
    }
}
void insertAtEnding(struct Node *temp,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(temp->next==head){
        struct Node *temp1=temp->next;
        struct Node *newNode=createNode(temp,data,temp1);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            temp->next=newNode;
            temp1->prev=newNode;
            count++;
        }
    }
    else{
        insertAtEnding(temp->next,data);
    }
}

void totalNode(){
    if(count==0){
        printf("\n Circular doubly linked list empty");
    }
    else{
    printf("\n Total Node is:%d",count);
    }
    
}
void insertAfterLocation(struct Node *temp,int loc,int i,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(loc>count){
        //do nothing
    }
    else if(loc==count){
        insertAtEnding(temp,data);
    }
    else if(i<loc){
        insertAfterLocation(temp->next,loc,++i,data);
    }
    else{
        struct Node *temp1=temp->next;
        struct Node *newNode=createNode(temp,data,temp1);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            temp->next=newNode;
            temp1->prev=newNode;
            count++;
        }
    }

}
void insertBeforeLocation(struct Node *temp,int loc,int i,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(loc==1){
        insertAtBeginning(temp,data);
    }
    else if(loc>count){
        // do nothing
    }
    else if(i<loc){
        insertBeforeLocation(temp->next,loc,++i,data);
    }
    else{
        struct Node *temp1=temp->prev;
        struct Node *newNode=createNode(temp1,data,temp);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            temp1->next=newNode;
            temp->prev=newNode;
            count++;
        }
    }
}
void insertAfterData(struct Node *temp,int searchData,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(temp->data==searchData && temp->next==head){
        insertAtEnding(temp,data);
    }
    else if(temp->data!=searchData && temp->next==head){
        printf("\n Data not found");
    }
    else if(temp->data==searchData){
        struct Node *temp1=temp->next;
        struct Node *newNode=createNode(temp,data,temp1);
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            temp->next=newNode;
            temp1->prev=newNode;
            count++;
        }
    }   
    else{
        insertAfterData(temp->next,searchData,data);
    }
}

void insertBeforeData(struct Node *temp,int searchData,int data){
    if(head==NULL){
        createHeadNode(data);
    }
    else if(temp->data==searchData && temp->next==head && count==1){
        insertAtBeginning(temp,data);
    }
    else if(temp->data!=searchData && temp->next==head){
        printf("\n data not found");
    }
    else if(temp->data==searchData){
            struct Node *temp1=temp->prev;
            struct Node *newNode=createNode(temp1,data,temp);
            if(newNode==NULL){
                printf("\n unable to allocate the memory");
            }
            else{
                temp1->next=newNode;
                temp->prev=newNode;
                count++;
            }
    }
    else{
        insertBeforeData(temp->next,searchData,data);
    }
}