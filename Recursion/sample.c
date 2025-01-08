#include<stdio.h>

void display(int n){
    if(n<=10){
        printf("%d\n",n);
    }
    display(++n);
    
}
int main(){
    display(1);
    return 0;
}