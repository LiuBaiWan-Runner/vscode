#include <iostream>

using namespace std;


int LoopSum(int List[],int N);
int RecursiveSum(int List[],int N);

int main()
{
    int N;
    cin>>N;
    int List[N];
    for(int i=0;i<N;i++){
        cin>>List[i];
    }

    cout<<LoopSum(List,N)<<endl;
    cout<<RecursiveSum(List,N)<<endl;

    return 0;
}


int LoopSum(int List[],int N){
    int i;
    int sum = 0;
    
    for(i=0;i<N;i++){
        sum+=List[i];
    }
    return sum;
}

int RecursiveSum(int List[],int N){
    if(N){
        return(RecursiveSum(List,N-1)+List[N-1]);
    }
    return 0;
}