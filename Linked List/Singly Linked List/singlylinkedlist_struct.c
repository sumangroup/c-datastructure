#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void printList();
// insert operation
void insertAtBeginning(int data);
void insertAtEnding(int data);
void insertAfterLocation(int loc, int data);
void insertBeforeLocation(int loc, int data);
void insertAfterData(int searchData, int data);
void insertBeforeData(int searchData,int data);
void deleteAtBeginning();
void deleteAtEnding();
void deleteAfterLocation(int loc);
// delete operation

int countList();
int main()
{
    int data;
    int searchData;
    int loc;
    int choice;
    do
    {
        printf("\n 0: exit");
        printf("\n 1: print list");
        printf("\n insert operation");
        printf("\n 2: insert at beginning");
        printf("\n 3: insert at ending");
        printf("\n 4: insert after location");
        printf("\n 5: insert before location");
        printf("\n 6: insert after Data");
        printf("\n 7: insert before Data");
        printf("\n delete operation");
        printf("\n 8: delete at beginning");
        printf("\n 9: delete at ending");
        printf("\n 10: delete after location");
        printf("\n Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            printList();
            break;

        case 2:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;

        case 3:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAtEnding(data);
            break;

        case 4:
            printf("\n Enter the location: ");
            scanf("%d", &loc);

            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterLocation(loc, data);
            break;

        case 5:
            printf("\n Enter the location: ");
            scanf("%d", &loc);

            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeLocation(loc, data);
            break;

        case 6:
            printf("\n Enter the search data: ");
            scanf("%d", &searchData);

            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertAfterData(searchData, data);
            break;
        
        case 7:
            printf("\n Enter the search data: ");
            scanf("%d", &searchData);

            printf("\n Enter the data: ");
            scanf("%d", &data);
            insertBeforeData(searchData, data);
            break;

        case 8:
            deleteAtBeginning();
            break;
        
        case 9:
            deleteAtEnding();
            break;

        case 10:
            printf("\n Enter the location: ");
            scanf("%d",&loc);
            deleteAfterLocation(loc);
            break;

        default:
            break;
        }
    } while (choice != 0);
    return 0;
}
void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n unable to allocate memory");
    }
    else
    {
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
}
void printList()
{
    if (head == NULL)
    {
        printf("\n List is empty");
    }
    else
    {
        struct Node *temp = head;
        int i = 1;
        printf("\n Signly Link List");
        printf("\n Start:%x", temp);
        printf("\n Address\t No\t Data\t nextAddress");
        while (temp != NULL)
        {
            printf("\n %x\t\t %d\t %d\t %x\t", temp, i, temp->data, temp->next);
            temp = temp->next;
            i = i + 1;
        }
        printf("\n");
    }
}
void insertAtEnding(int data)
{
    if (head == NULL)
    {
        insertAtBeginning(data);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n unable to allocate memory");
        }
        else
        {
            newNode->data = data;
            struct Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            newNode->next = NULL;
            temp->next = newNode;
        }
    }
}
void insertAfterLocation(int loc, int data)
{
    if (head == NULL)
    {
        insertAtBeginning(data);
    }
    else if (loc > countList())
    {
        insertAtEnding(data);
        printf("\n You have exceed the linked list and number has been at the end");
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n Enable to allocate the memory");
        }
        else
        {
            int i = 1;
            struct Node *temp = head;
            for (i = 1; i < loc; i++)
            {
                temp = temp->next;
            }
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
int countList()
{
    if (head == NULL)
    {
        return -1;
    }
    else
    {
        int count=0;
        struct Node *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count = count + 1;
        }
        printf("%d",count);
        return count;
    }
}
void insertBeforeLocation(int loc, int data)
{
    if (head == NULL)
    {
        insertAtBeginning(data);
    }
    else if (loc == 1)
    {
        insertAtBeginning(data);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n unable to alloate the memory");
        }
        else
        {
            int i;
            struct Node *temp = head;
            for (i = 1; i < loc - 1; i++)
            {
                temp = temp->next;
            }
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void insertAfterData(int searchData, int data)
{
    if (head == NULL)
    {
        insertAtBeginning(data);
    }
    else if ((head->data == data) || (head->next == NULL))
    {
        insertAtEnding(data);
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n unable to allocate memory");
        }
        else
        {
            struct Node *temp = head;
            while (temp->data != searchData && temp->next != NULL)
            {
              temp = temp->next;
            }
            newNode->data = data;
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}
void insertBeforeData(int searchData,int data){
    if(head==NULL){
        insertAtBeginning(data);
    }
    else if((head->data==data) || (head->next==NULL)){
        insertAtBeginning(data);
    }
    else{
        struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
        if(newNode==NULL){
            printf("\n unable to allocate the memory");
        }
        else{
            struct Node *temp=head;
            while((temp->next->data!=searchData)&&(temp->next->next!=NULL)){
                temp=temp->next;
            }
            if(temp->next->data==searchData){
                newNode->data=data;
                newNode->next=temp->next;
                temp->next=newNode;
            }
            else{
               insertAtEnding(data);
            }

        }
    }
}
void deleteAtBeginning(){
    if(head==NULL){
        printf("\n list is empty");
    }
    else{
        struct Node *temp=head;
        printf("Data: %d is delete",temp->data);
        head=temp->next;
        free(temp);

    }
}
void deleteAtEnding(){
    if(head==NULL){
        printf("\n list is empty");
    }
    else if(head->next==NULL){
        struct Node *temp=head;
        printf("Data: %d is delete",temp->data);
        free(temp);
        head=NULL;
    }
    else{
        struct Node *temp=head,*temp1;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        printf("Data: %d is delete",temp->next->data);
        temp1=temp;
        free(temp->next);
        temp1->next=NULL;
    }
}
void deleteAfterLocation(int loc){
    int a=countList();
    printf("%d",a);
    if(head==NULL){
        printf("\n list is empty");
    }
    else if(loc>=countList()){
        printf("\n Location is out of list range");
    }
    else{
        struct Node *temp=head,*temp1;
        int i;
        for(i=1;i<loc;i++){
            temp=temp->next;
        }
        //printf("Data: %d is delete",temp->next->data);
        temp1=temp->next;
        temp->next=temp->next->next;
        free(temp1);

    }
}