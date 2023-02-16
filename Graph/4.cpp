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
    vector<int>status(v);
    for (int i = 1; i <= e; i++)
    {
        // cout<<"enter the start and terminating inndex"<<endl;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   /*  cout << "THE ADJ LIST IS\n"
         << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << " "
             << "->";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    } */
    q.push(0);
    status[0]=1;
    while (!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int j=0;j<adj[x].size();j++){
            if (status[adj[x][j]]==0)
            {
                q.push(adj[x][j]);
                status[adj[x][j]]=1;
            }
        }
         cout<<x;
    }
    return 0;
}
