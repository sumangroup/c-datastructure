#include<stdio.h>

void main(){
    int i,j;
    for(i=1;i<11;i++){
        for(j=1;j<11;j++){
            printf("%d*%d:%d\n",i,j,i*j);
        }
        printf("\n");
    }
}