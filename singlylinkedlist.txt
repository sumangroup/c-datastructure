#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *head=NULL;
void display();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfterLocation(int loc,int data);
void insertBeforeLocation(int loc,int data);
void insertAfterData(int searchData,int data);
void insertBeforeData(int searchData,int data);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAfterLocation(int loc);
void deleteBeforeLocation(int loc);
void deleteAfterData(int searchData);
void deleteBeforeData(int searchData);
int main(){
    int data,searchData,choice,loc;
    do
    {
        printf("\n0: exit");
        printf("\n1: display");
        printf("\n2: insert at beginning");
        printf("\n3: insert at ending");
        printf("\n4: insert after location");
        printf("\n5: insert before location");
        printf("\n6: insert after data");
        printf("\n7: insert before data");
        printf("\n8: delete at beginning");
        printf("\n9: delete at ending");
        printf("\n10: delete after location");
        printf("\n11: delete before location");
        printf("\n12: delete after data");
        printf("\n13: delete before data");
        printf("\n Enter the choice: ");
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
            insertAtBeginning(data);
            break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertAtEnd(data);
            break;

        case 4:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            printf("\n Enter the location: ");
            scanf("%d",&loc);
            insertAfterLocation(loc,data);
            break;

        case 5:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            printf("\n Enter the location: ");
            scanf("%d",&loc);
            insertBeforeLocation(loc,data);
            break;

        case 6:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            printf("\n Enter the search data: ");
            scanf("%d",&searchData);
            insertAfterData(searchData,data);
            break;

        case 7:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            printf("\n Enter the search data: ");
            scanf("%d",&searchData);
            insertBeforeData(searchData,data);
            break;

        case 8:
            deleteAtBeginning();
            break;
        
        case 9:
            deleteAtEnd();
            break;
        
        case 10:
            printf("\n Enter the location: ");
            scanf("%d",&loc);
            deleteAfterLocation(loc);
            break;
        
        case 11:
            printf("\n Enter the location: location must be greater than 1: ");
            scanf("%d",&loc);
            deleteBeforeLocation(loc);
            break;
        
        case 12:
            printf("\n Enter the search data: ");
            scanf("%d",&searchData);
            deleteAfterData(searchData);
            break;

        case 13:
            printf("\n Enter the search data: ");
            scanf("%d",&searchData);
            deleteBeforeData(searchData);
            break;
        default:
            break;
        }
    } while (choice!=0);
    
}
void insertAtBeginning(int data){
    if(head==NULL){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            head=newNode;
        }
    }
    else{
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=head;
            head=newNode;
        }
    }
}

void display(){
    if(head==NULL){
        printf("\n list is empty");
    }
    else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%d\t ",temp->data);
            temp=temp->next;
        }
    }
}

void insertAtEnd(int data){
    if(head==NULL){
        struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n Unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            head=newNode;
        }
    }
    else{
        struct Node *temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n Unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            temp->next=newNode;
        }
        
    }
}
void insertAfterLocation(int loc,int data){
    if(head==NULL){
        struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n Unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            head=newNode;
        }
    }
    else{
        struct Node *temp=head;
        int i=1;
        for(i=1;i<loc;i++){
            temp=temp->next;
        }
        struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n Unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=temp->next;
            temp->next=newNode;
        }

    }
}
void insertBeforeLocation(int loc,int data){
    if(head==NULL){
        struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n Unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            head=newNode;
        }
    }
    else if(loc==1){
        insertAtBeginning(data);
    }
    else{
        struct Node *temp=head;
        int i=1;
        for(i=1;i<loc-1;i++){
            temp=temp->next;
        }
        struct Node *newNode=(struct Node*) malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n Unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=temp->next;
            temp->next=newNode;
        }
    }
}
void insertAfterData(int searchData,int data){
    if(head==NULL){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            head=newNode;
        }
    }
    else if((head->data==data) || (head->next==NULL)){
        insertAtEnd(data);
    }
    else{
        struct Node *temp=head;
        while(temp->data!=searchData && temp->next!=NULL){
            temp=temp->next;
        }
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=temp->next;
            temp->next=newNode;
        }

    }
}
void insertBeforeData(int searchData,int data){
    if(head==NULL){
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            newNode->data=data;
            newNode->next=NULL;
            head=newNode;
        }
    }
    else if(head->data==data || head->next==NULL){
        insertAtBeginning(data);
    }// else if close
    else{
        struct Node *temp=head;
        while(temp->next->data!=searchData && temp->next->next!=NULL){
            temp=temp->next;
        }
        if(temp->next->data==searchData){
            struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
            if(newNode==NULL){
                printf("\n unable to allocate the memory");
            }
            else{
                newNode->data=data;
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
        else{
            insertAtEnd(data);
        }
    }
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("underflow: list is empty");
    }
    else{
        struct Node *temp=head;
        head=temp->next;
        free(temp);
    }
}
void deleteAtEnd(){
    if(head==NULL){
        printf("underflow: list is empty");
    }
    else{
        struct Node *temp1=head,*temp2=NULL;
        while(temp1->next!=NULL){
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp2==NULL){
            head=NULL;
            free(temp1);
        }
        else{
            temp2->next=NULL;
            free(temp1);
        }
    }
}
void deleteAfterLocation(int loc){
    if(head==NULL){
        printf("\n underflow: list is empty");
    }
    else{
        struct Node *temp1=head,*temp2=NULL;
        int i=1;
        for(i=1;i<loc;i++){
            temp1=temp1->next;
        }
        if(temp1==head){
            head=temp1->next;
            free(temp1);
        }
        else{
            temp2=temp1->next;
            temp1->next=temp2->next;
            free(temp2);
        }
    }
}
void deleteBeforeLocation(int loc){
    if(head==NULL){
        printf("\n underflow: list is empty");
    }
    else if(loc==2){
        struct Node *temp=head;
        head=temp->next;
        free(temp);
    }
    else{
        struct Node *temp1=head,*temp2=NULL;
        int i=1;
        for(i=1;i<loc-2;i++){
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
    }
}

/*
void deleteBeforeLocation(int loc){
    if(head==NULL){
        printf("\n underflow: list is empty");
    }
    else if(loc==2){
        struct Node *temp=head;
        head=temp->next;
        free(temp);
    }
    else{
        struct Node *temp1=head,*temp2=NULL;
        int i=1;
        for(i=1;i<loc-2;i++){
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
    }
}
*/
void deleteAfterData(int searchData){
    if(head==NULL){
        printf("\n unable to allocate the memory");
    }
    else{
        struct Node *temp1=head,*temp2=NULL;
        while(temp1->data!=searchData){
            temp1=temp1->next;
        }
        temp2=temp1->next;
        if(temp2!=NULL){
            temp1->next=temp2->next;
            free(temp2);
        }
    }
}

void deleteBeforeData(int searchData){
    struct Node *temp1=head,*temp2=NULL;
    if(head==NULL){
        printf("\n unable to allocate the memory");
    }
    else if(temp1->data==searchData){
        
    }
    else if(temp1->next->data==searchData){
        head=temp1->next;
        free(temp1);
    }
    else{
        while((temp1->next!=NULL) && (temp1->next->data!=searchData)){
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1->next!=NULL){
            temp2->next=temp1->next;
            free(temp1);
        }
    }
}