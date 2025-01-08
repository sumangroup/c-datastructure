#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void push(int data);
void pop();
void display();
int isEmpty();

int main()
{
    int data, choice;
    do
    {
        printf("\n 0: exit ");
        printf("\n 1: push ");
        printf("\n 2: pop ");
        printf("\n 3: display ");

        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);

        case 1:
            printf("\n Enter the data: ");
            scanf("%d", &data);
            push(data);
            break;

        case 2:
           pop();
            

            break;

        case 3:
            display();
            break;

        default:
            printf("\n Invalid input");
            break;
        }
    } while (choice != 0);
}

void push(int data)
{
    if (head == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        if (newNode == NULL)
        {
            printf("\n Unable to allocate the memory");
        }
        else
        {
            newNode->data = data;
            newNode->next = NULL;
            head = newNode;
        }
    }
    else
    {
        struct Node *temp = head;
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
            temp->next = newNode;
        }
    }
}

void display()
{
    if (head == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
void pop()
{
    /*
    if (head == NULL)
    {
        return -1;
    }
    else if (head->next == NULL)
    {
        struct Node *temp = head;
        int data;
        data=temp->data;
        //printf("Data: %d is delete", temp->data);
        free(temp);
        head = NULL;
        return data;
    }
    else
    {
        struct Node *temp = head, *temp1;
        int data;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        //printf("Data: %d is delete", temp->next->data);
        data=temp->next->data;
        temp1 = temp;
        free(temp->next);
        temp1->next = NULL;
        return data;
    }
*/

    if (head == NULL)
    {
        printf("\n Stack is empty");
    }
    else
    {
        struct Node *temp1=head,*temp2=NULL;
        while(temp1->next!=NULL){
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1!=NULL&&temp2==NULL){
            printf("%d\n",temp1->data);
            free(temp1);
            head=NULL;
        }
        else{
            printf("%d\n",temp1->data);
            free(temp1);
            temp2->next=NULL;
        }
    }
}