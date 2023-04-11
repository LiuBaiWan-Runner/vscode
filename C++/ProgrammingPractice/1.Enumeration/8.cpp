/*
* @file    :8.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :
*          :
*          :
*/
#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	int x, y;
	int count = 0;
	cin >> a >> b >> c;
	for(x=0; x<=c/a; x++){
		y = (c-a*x)/b;
		if(a*x+b*y == c){
			count ++;
		}
	}
	cout << count << endl;
	return 0;
}	