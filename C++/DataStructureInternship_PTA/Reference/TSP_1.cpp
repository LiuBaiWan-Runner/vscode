#include<iostream>
#include<cstdio>
#define MAXSIZE 1000000

using namespace std;
struct ENode{
	int vsub;
	ENode *succ;
};
struct VNode{
	int in,len;
	ENode *fstEdge;
};
VNode adjList[MAXSIZE];
ENode *t;
int stack[MAXSIZE],top=0,maxlen=0,n,m,v1,v2;

int GetMax(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

//拓扑排序
void TSort(){
	for(int i=1; i<=n; i++){
        if(!adjList[i].in){
            stack[++top] = i;
        }
	}
	while(top){
		int v=stack[top--];
		for(ENode *p=adjList[v].fstEdge; p; p=p->succ){
			adjList[p->vsub].len = GetMax(adjList[v].len+1,adjList[p->vsub].len);
			maxlen = GetMax(adjList[p->vsub].len,maxlen);
			if(!(--adjList[p->vsub].in)){
                stack[++top] = p->vsub;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=0; i<m; i++){
		cin>>v1>>v2;
		t = new ENode;
		t->vsub = v2;
		adjList[v2].in++;
		t->succ = adjList[v1].fstEdge;
		adjList[v1].fstEdge = t;
	}
	TSort();
	cout<<maxlen+1<<endl;
	return 0;
}
