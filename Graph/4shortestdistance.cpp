#include <iostream>
#include <vector>
#include<queue>
//BFS
using namespace std;
int main()
{
    int v, a = 0, b = 0, e;
    cout << "enter number of vertices" << endl;
    cin >> v;
    cout << "enter the number of edges";
    cin >> e;
    vector<int> adj[v];
    queue<int>q;
    vector<int>dis(v);
    for (int i = 1; i <= e; i++)
    {
        // cout<<"enter the start and terminating inndex"<<endl;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    q.push(0);
    dis[0]=0;
    cout<<"BFS:-";
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int j=0;j<adj[x].size();j++){
            if (dis[adj[x][j]]==0)
            {
                q.push(adj[x][j]);
                dis[adj[x][j]]=dis[x]+1;
            }
        }
         cout<<x;
    }
    cout<<endl;
    cout<<"the shortest distance of all nodes from 0 is"<<endl;
    for ( int i = 0; i < v; i++)
    {
        cout<<i<<"->"<<dis[i];
        cout<<endl;
    }
    
    return 0;
}
