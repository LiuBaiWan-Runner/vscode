/*
* @file    :4_copy.cpp
* @author  :LiuBaiWan-Runner
* @version :V1.0.0
* @date    :2023-03-23
* @brief   :https://blog.csdn.net/weixin_41753316/article/details/108040793
*          :
*          :
*/
#include <iostream>
 
using namespace std;
 
int main(){
	int n;
	cin>>n;
	for(int i=2;i<=n;i++){
		for(int j=2;j<i;j++){
			for(int k=j+1;k<i;k++){
				for(int l=k+1;l<i;l++){
					if(i*i*i==j*j*j+k*k*k+l*l*l){
						cout << "Cube = "<<i<<", Triple = ("<<j<<","<<k<<","<<l<<")"<<endl;
					}
				}
			}
		}
	}
	return 0;
}