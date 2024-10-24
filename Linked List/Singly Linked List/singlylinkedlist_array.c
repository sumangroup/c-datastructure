#include<stdio.h>
#define MAX 100
void createList(int INFO[],int LINK[],int *START,int *AVAIL);
void insertAtBeginning(int INFO[],int LINK[],int *START,int *AVAIL,int data);
void printList(int INFO[],int LINK[],int *START,int *AVAIL);
int main(){
    int data;
    int INFO[MAX];
    int LINK[MAX];
    int START;
    int AVAIL;
    int choice;
    createList(INFO,LINK,&START,&AVAIL);
    printf("\n SINGLY LINKED LIST USING ARRAY");
    do
    {
        printf("\n 0: exit");
        printf("\n 1: print list");
        printf("\n 2: insert at beginning");

        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        
        case 1:
            printf("\n Enter the data: ");
            scanf("%d",&data);
            insertAtBeginning(INFO,LINK,&START,&AVAIL,data);

        default:
            printf("\n invalid input");
            break;
        }
    } while (choice!=0);
    
    

    return 0;
}
void createList(int INFO[],int LINK[],int *START,int *AVAIL){
    *START=-1;
    *AVAIL=0;
    int i;
    for(i=0;i<MAX;i++){
        if(i==MAX-1){
            LINK[i]=-1;
        }
        else{
            LINK[i]=i+1;
        }
    }
}

void insertAtBeginning(int INFO[],int LINK[],int *START,int *AVAIL,int data){
    int new;
    new=AVAIL;
    
}