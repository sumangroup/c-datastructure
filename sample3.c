#include<stdio.h>

int main(){
    int a[3][3];
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            a[i][j]=i+j;
            //scanf("%d",&a[i][j]);
            printf("a[%d][%d]:%d\n",i,j,a[i][j]);
        }
    }
}