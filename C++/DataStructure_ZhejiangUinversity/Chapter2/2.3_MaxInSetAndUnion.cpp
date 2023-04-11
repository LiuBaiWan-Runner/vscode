#include <iostream>

using namespace std;

typedef int ElementType;

int main()
{
    cout<<"Hello world!"<<endl;
    return 0;
}

ElementType Max(ElementType set[],int N){

    ElementType setMax=set[0];
    for (int i = 0; i < N; i++){
        if(set[i]>setMax){
            setMax=set[i];
        }
    }
    return setMax;
}
