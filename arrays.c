#include<stdio.h>
#define size 5
int insert(int LA[],int N,int k,int value);
int delete(int LA[],int N,int K);
void display(int LA[],int N);
int linearsearch(int LA[],int N,int value);
int main(){
    // define an array
    int LA[size];
    // number of elements present in an array
    int N=0;
    // position
    int K;
    // value
    int value;

    int choice;
    do{
        printf("\n 1:insert");
        printf("\n 2:delete");
        printf("\n 3:display");
        printf("\n 4:search");
        printf("\n 5:exit");
        printf("\n Enter your choices: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\n Enter the position: ");
                scanf("%d",&K);
                printf("\n Enter the value: ");
                scanf("%d",&value);
                N=insert(LA,N,K,value);
                printf("\n Total Number of elements:%d",N);
                printf("\n Inserted Element Sucessfully");
            break;

            case 2:
                printf("\n Enter the position: ");
                scanf("%d",&K);
                N=delete(LA,N,K);
                printf("\n Total Number of elements:%d",N);
                printf("\n Deleted Element Sucessfully");
            break;

            case 3:
                display(LA,N);
            break;

            case 4:
            printf("\n Enter the value: ");
            scanf("%d",&value);
            K=linearsearch(LA,N,value);
            
            if(K>N){
                printf("\nthe elements not present and it is added at this location %d",K-1);
                N=N+1;
            }
            else{
                 printf("\nthe elements %d, present at this location %d",value,K);
            }
            break;
            case 5:
            exit(0);

            default:
            printf("\n Invalid input");
            break;
        }
       
    }while(choice!=5);
    return 0;
}
int insert(int LA[],int N,int K,int value){

    // check the overflow condition
    if(N==size){
        printf("\nOverflow");
    }
    else{
        if(N==0){
            LA[N]=value;
            N=N+1;
        }
        else if(K>N-1){
             LA[N]=value;
            N=N+1;
        }
        else{
            int J=N-1;
            while(J>=K){
                LA[J+1]=LA[J];
                J=J-1;
            }
            LA[K]=value;
            N=N+1;
        }
    }
    return N;
}

int delete(int LA[],int N,int K){
    if(N==0){
        printf("\nUnderflow");
    }
    else{
        if(K>N-1){
            printf("\nElements Not present");
        }
        else{
            printf("\n%d this element is deleted",LA[K]);
            int J=K;
            while(J<=N-1){
                LA[J]=LA[J+1];
                J=J+1;
            }
            N=N-1;
        }
    }
    return N;
}

void display(int LA[],int N){
    if(N==0){
        printf("\nArray is empty");
    }
    else{
        printf("\nElements in Array");
        int J=0;
        while(J<N){
            printf("\nLA[%d]:%d",J,LA[J]);
            J=J+1;
        }
    }
}
int linearsearch(int LA[],int N,int value){
    int K=0;
    while(LA[K]!=value && K++<N);
    if(N==K-1){
        LA[K-1]=value;
        printf("%d",LA[K-1]);
        return N+1;
    }
    else{
        return K;
    }
    
}