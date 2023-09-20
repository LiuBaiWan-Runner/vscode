/*
 * @file    :1_csdn.cpp
 * @author  :LiuBaiWan-Runner
 * @version :V1.0.0
 * @date    :2023-09-20
 * @brief   :MT2214元素共鸣
 *          :CSDN:https://blog.csdn.net/m0_51787573/article/details/126192220
 *          :
 */

#include<iostream> 
 
using namespace std;
int i, j;
 
int main( )
{
    int n, k;
    bool flag = 1;
    cin >> n >> k;
    vector<int> arr;
 
	for(i=2;i<=n;i++){
		for(j=2;j<=i;j++){
			if(i%j==0){
				break;
			}
		}
		if(i==j){
			arr.insert(arr.end(), i);
		}
 
	}
	
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j <arr.size();j++){
            if(arr[j]- arr[i] == k){
                flag = 0;
                cout << arr[i] <<" "<< arr[j] << endl;
            }
        }
    }
 
    if(flag){
        cout << "empty";
    }
    return 0;
}