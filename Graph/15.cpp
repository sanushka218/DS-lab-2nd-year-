#include <iostream>
#include <vector>
#include<queue>
#include <utility>
using namespace std;
typedef pair<int,int>ipair;
int main()
{
    int v, a = 0, b = 0, e, cost;
    cout << "enter number of vertices" << endl;
    cin >> v;
    cout << "enter the number of edges";
    cin >> e;
    vector<ipair> adj[v + 1];
    vector<int> inMST(v, 0); // vertex in this mean they are not included in mst
    vector<int> key(v, __INT_MAX__);
    vector<int> predecessor(v, -1); // initialized to null
    cout<< "for every edge enter the starting, terminating vertex, & cost of that edge" << endl;
    while (a != -1)
    {
        // cout<<"enter the start and terminating inndex and the weight of vertex"<<endl;
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }
    key[1]=0;
    priority_queue< ipair, vector<ipair>, greater<ipair>>pq; // greater works as comparator here
    pq.push({0,1});// key, vertex
    for(int i=2;i<=v;i++)
    {
        pq.push({__INT_MAX__, i});
    }
    for(int i=1;i<=v;i++)
    {
        pair<int,int>x= pq.top();//key,vertex
        pq.pop();
        int u=x.second;//vertex
        inMST[u]=1;//status =1, i.e. vertex is now inlcuded in MST
        for(int j=0;j<adj[u].size();j++)
        {
            //adj list will have data in form of (vertex,weight)
            int vertex=adj[u][j].first;
            int weight= adj[u][j].second;
            if(inMST[vertex]==0 && key[vertex]>weight)
            {
                key[vertex]=weight;
                predecessor[vertex]=u;
                pq.push({key[vertex],vertex});//pair key,vertex
            }
        }
    }
    cout<<"MST IS"<<endl;
    cout<<"VERTEX   KEY   PREDECESSOR"<<endl;
    for(int i=1;i<=v;i++)
    {
        cout<<i<<"\t";
        cout<<key[i]<<"\t";
        cout<<predecessor[i]<<endl;
    }
    return 0;
}
