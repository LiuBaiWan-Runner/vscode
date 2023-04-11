#include <iostream>

using namespace std;


int main(){
    int sign = 1;
    double sum = 0.5, term;
    float deno = 3;             //换成浮点型
    sum += (-1)*(1/deno);
    // for(int deno = 2; deno <= 3; deno++){
    //     sign *= -1;
    //     term = sign*(1/deno);
    //     sum += term;
    // }
    printf("%f", 1/deno);
    return 0;
}