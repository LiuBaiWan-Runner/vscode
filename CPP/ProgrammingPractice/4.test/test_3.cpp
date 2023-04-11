#include <iostream>
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	int a[n+10];
	int t[q];
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	for(int i = 0; i<q; i++){
		cin >> t[i];
	}
	int s, e;
	for(int i = 0; i<q; i++){
		for(int j = 1; j<=n;j++){
			if(a[j] == t[i] && a[j+1] != t[i]){
				s = e = j;
				cout << s << ' ' << e <<endl;
				break;
			}
			if(a[j] == t[i] && a[j+1] == t[i]){
				s = j;
				for(int k = j; k<=n; k++){
					if(a[k] == t[i]){
						e = k;
					}
					else{
						break;
					}
				}
				cout << s << ' ' << e << endl;
				break;
			}
			if(a[j] > t[i] || t[i] > a[n]){
				s = e = -1;
				cout << s << ' ' << e << endl;
				break;
			}
		}
	}
	
	return 0;
}