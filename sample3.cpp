#include<iostream>


class Item{
    int number;
    float cost;
    public:
    void getData(int a,float b);
    void display(void){
        std::cout<<"number:"<<number<<"\n";
        std::cout<<"cost:"<<cost<<"\n";
    }
};
void Item::getData(int a,float b){
    number=a;
    cost=b;
}

int main(){
    Item x;
    x.getData(1,10.23);
    x.display();
}
