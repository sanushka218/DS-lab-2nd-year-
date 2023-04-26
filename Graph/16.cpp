#include<iostream>
#include<utility>
#include<queue>
#include<vector>
typedef pair<int,int> cpair;
using namespace std;
int main()
{
    int v,e,a,b,cost;
    cout<<"enter the number of vertices"<<endl;
    cin>>v;
    vector<int>d(v,__INT_MAX__);
    vector<int>p(v,-1);
    vector<cpair>adj[v];
    cout<<"enter the number of edges"<<endl;
    cin>>e;
    cout<<"enter starting, termianting vertex with cost of edge"<<endl;
    for(int i=0;i<e;i++)
    {
      cin>>a>>b>>cost;
      adj[a].push_back({b,cost});
    }
    priority_queue<cpair, vector<cpair>, greater<cpair>>pq;
    
    return 0;
}
