#include <iostream>
#include<queue>
using namespace std;
#define INF 65535
#define Max 1000
#define MaxVertexNum 1000
bool Visited[MaxVertexNum], Visited1[MaxVertexNum];
int ans[MaxVertexNum];
queue<int>qu;

typedef struct GNode{ 
  char node[Max];
  int arcs[Max][Max];
  int nodeNum,arcNum;
}*MGraph; 

typedef struct ENode{
    int V1,V2,Weight;
}*Edge;

void DFS(MGraph T,int V);

MGraph CreateGraph(int VNum){
    int V,M;
    MGraph Graph;
    Graph =(MGraph)malloc(sizeof(struct GNode));
    Graph->nodeNum=VNum;
    Graph->arcNum=0;
    for(V=0;V<=VNum;V++)
        for(M=0;M<=VNum;M++)
            Graph->arcs[V][M]=INF;
    return Graph;
}

void InsertEdge(MGraph Graph,Edge edge){
    Graph->arcs[edge->V2][edge->V1]=edge->Weight;
    Graph->arcs[edge->V1][edge->V2]=edge->Weight;
}

// MGraph BuildGraph(){
//     MGraph Graph;
//     Edge edge;
//     int V;
//     int nodeNum,i;
//     //cin>>nodeNum;
//     //Graph =(MGraph)malloc(sizeof(struct GNode));
//     Graph=CreateGraph('Z');
//     cin>>Graph->nodeNum>>Graph->arcNum;
//     for(int i=0;i<='Z';i++) Visited[i]=1;
//     if(Graph->arcNum!=0){
//         edge=(Edge)malloc(sizeof(struct ENode));
//         for(i=0;i<Graph->nodeNum;i++){
//             cin>>edge->V1>>edge->V2>>edge->Weight;
//             Visited[edge->V1]=Visited[edge->V2]=0;
//             InsertEdge(Graph,edge);
//         }
//     }
//     DFS(Graph,'B');
//     return 0;
// }

void DFS(MGraph T,int V)
{
    cout<<' '<<(char)V;
    Visited[V]=true;//改标记
    int i;
    for(i=0;i<='Z';i++)//邻接表遍历所有结点
    {
        if(T->arcs[V][i]!=INF&&Visited[i]==false)//找到一个邻接点递归遍历
            DFS(T,i);
    }
}

void BFS(MGraph T,int V)
{
    qu.push(V);
    Visited1[V]=1;
    while(!qu.empty())
    {
        int M=qu.front();
        cout<<" "<<(char)M;
        qu.pop();
        for(int M1=0;M1<='Z';M1++)
        {
            if(T->arcs[M1][M]!=INF&&Visited1[M1]==false)//找到一个邻接点递归遍历
            {
                Visited1[M1]=1;
                qu.push(M1);
            }
        }
    }
}

int main(){
    MGraph Graph;
    Edge edge;
    int V,MIN=INF;
    int nodeNum,i;
    //cin>>nodeNum;
    //Graph =(MGraph)malloc(sizeof(struct GNode));
    Graph=CreateGraph('Z');
    
    cin>>Graph->nodeNum>>Graph->arcNum;
    for(int i=0;i<='Z';i++) Visited[i]= Visited1[i]=1;
    if(Graph->arcNum!=0){
        
        for(i=0;i<Graph->arcNum;i++){
            edge=(Edge)malloc(sizeof(struct ENode));
            char a,b;
            int c;
            cin>>a>>b>>c;
            edge->V1=a;
            edge->V2=b;
            MIN=min(min(MIN,(int)a),(int)b);
            edge->Weight=c;
            Visited1[edge->V1]=Visited1[edge->V2]=Visited[edge->V1]=Visited[edge->V2]=0;
            InsertEdge(Graph,edge);
        }
    }
// for(int i='A';i<='Z';i++)
//     {
//         for(int j='A';j<='Z';j++)
//         cout<<Graph->arcs[i][j]<<" ";
//         cout<<endl;
//     }
    cout<<"DFS:";
    DFS(Graph,MIN);
    cout<<endl;
    cout<<"BFS:";
    BFS(Graph,MIN);
    cout<<endl;
    for(int i=MIN;i<='Z';i++)
    {
        for(int j=MIN;j<='Z';j++)
        if(Graph->arcs[i][j]!=INF) 
            ans[i]++;
    }
    for(int i=MIN;i<='Z';i++) 
        if(ans[i])
        cout<<(char)i<<':'<<ans[i]<<endl;
    return 0;
}