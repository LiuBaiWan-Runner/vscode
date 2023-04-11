  /*
  * @file    :1.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-02-23
  * @brief   :12枚银币
  *          :
  *          :
  */

#include <iostream>
using namespace std;
char Left[3][7];
char Right[3][7];
char result[3][7];

bool find(char ch[], char c){
	for (int i = 0; i < 7; i++)
	{
		if (ch[i] == c){
			return true;
		}
		else{
			return false;
		}
	}
	
}

bool IsFake(char c, bool light){
	for (int i = 0; i < 3; i++){
		char *pLeft, *pRight;
		if (light){
			pLeft = Left[i];
			pRight = Right[i];
		}
		else{
			pLeft = Right[i];
			pRight = Left[i];
		}

		switch (result[i][0]){
		case 'e':
			if(find(pLeft,c)||find(pRight,c)){
				return false;
			}
			break;
		case 'u':
			if(!find(pRight,c)){
				return false;
		}
			if(!find(pLeft,c)){
				return false;
		}
		
		default:
			break;
		}
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		for (int i = 0; i < 3; i++){
			cin >> Left[i] >> Right[i] >> result[i];
		}
		for (char c = 'A'; c <= 'L'; c++){
			if (IsFake(c,true)){
				cout << c << "is light." << endl;
			}
			
		}
		
		
	}
	
	
	return 0;
}
