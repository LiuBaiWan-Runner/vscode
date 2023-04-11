#include <stdio.h>
#include <math.h>

int main(){
	int x; 
	double y;
	scanf("%d",&x);
	if(x<1){
		y=3*x/5;
	}
	else if(x >=1 && x < 10)
		y=abs(2-5*x);
	else
		y=sqrt(4*x-13);
	printf("y=%.2f\n",y);
	return 0;
}
