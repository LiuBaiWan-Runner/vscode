#include <iostream>

using namespace std;

void print_N_loop(int N){
    int i;
    for (i=1;i<=N;i++){
        cout<<i<<endl;
    }
    return;
}

void print_N_recursion(int N){
    if(N){
        print_N_recursion(N-1);
        cout<<N<<endl;
    }
    return;
}


int main()
{
    int N;
    cin>>N;
    //print_N_loop(N);
    print_N_recursion(N);
    return 0;
}
