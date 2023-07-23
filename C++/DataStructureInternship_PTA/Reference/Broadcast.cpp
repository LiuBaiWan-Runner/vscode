#include<iostream>
using namespace std;

#define N 10000

int n,m;  //小镇数，相距20km内的小镇对数
int queue[N+10],head,tail;  //模拟队列

//nextTown
struct Node{
    int num;
    Node* next;
    Node() { next = NULL; }
    Node(int n,Node *node) :num(n),next(node) {}
};

//小镇
struct Town{
    int state;  //状态
    Node *nt;  //nextTown
    Town() { state = 0; nt = NULL; }
    void insert(int num);
}town[N];

//插入新边
void Town::insert(int num){
    if(this->nt == NULL){
        this->nt = new Node(num,NULL);
    }else{
        this->nt = nzew Node(num,this->nt);
    }
}

bool bfs(int x){
    queue[tail++] = x;
    town[x].state = 1;
    while(head < tail){
        Town cur = town[queue[head]];  //当前小镇
        Node *tmp = cur.nt;  //指向nextTown
        while(tmp != NULL){
            if(!town[tmp->num].state){
                town[tmp->num].state = -cur.state;
                queue[tail++] = tmp->num;
            }else if(town[tmp->num].state == cur.state){  //波段相同被干扰
                return false;
            }
            tmp = tmp->next;
        }
        head++;
    }
    return true;
}

int main()
{
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        town[x].insert(y);
        town[y].insert(x);
    }
    for(int i=0; i<n; i++){
        if(!town[i].state){
            if(bfs(i) == false){
                cout<<"-1"<<endl;
                return 0;
            }
        }
    }
    cout<<"1"<<endl;
    return 0;
}
