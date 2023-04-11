  /*
  * @file    :5.cpp
  * @author  :LiuBaiWan-Runner
  * @version :V1.0.0
  * @date    :2023-03-05
  * @brief   :MT2041三角形的个数
  *          :https://blog.csdn.net/gyk1303/article/details/121183132
  *          :
  */
#include <iostream>

using namespace std;

int count(int n){
    int ans=1,a1=4,a2=4,a3=2;
	for(int i=1;i<n;i++)
	{
		ans+=a1;
		a1+=a2;
		a2+=a3;
		if(a3==2) a3=1;
		else a3=2;
	}
	return ans;
}

int main( )
{
    int N;
    cin >> N;
    int n[N];
    for(int i = 0; i<N; i++){
        cin >> n[i];
    }
    for(int i = 0; i<N; i++){
        cout << count(n[i]) << endl;
    }
    return 0;
}