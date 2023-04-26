#include <iostream>
#include <vector>
using namespace std;
int dfsvisit(vector<int> adj[], vector<int>&visited, int i, int x)
{
    visited[i] = 1;
    cout << i << " ";
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (visited[adj[i][j]] == 0)
        {
            x++;
           x= dfsvisit(adj, visited, adj[i][j],x);
            
        }
    }
    return x;
}
void dfs(vector<int> adj[], int v)
{
    int c=0;
    vector<int> visited(v, 0);
    vector<int>numberOfElementInConnectedComponents;
    for (int i = 0; i < v-1; i++)
    {
        if (visited[i] == 0)
        {
           int elements=dfsvisit(adj, visited, i,1);
            c++;
           numberOfElementInConnectedComponents.push_back(elements);
        }
    }
    cout<<endl;
    cout<<"TOTAL NUMBER OF CONNECTED COMPONETS"<<endl;
    for (int i = 0; i < c; i++)
    {
        cout<<"COMPONENT - "<<i+1<<" has elements in it = "<<numberOfElementInConnectedComponents[i]<<endl;
    } 
}
int main()
{
    int v, a = 0, b = 0, e;
    cout << "enter number of vertices" << endl;
    cin >> v;
    cout << "enter the number of edges";
    cin >> e;
    vector<int> adj[v];
    for (int i = 1; i <= e; i++)
    {
        // cout<<"enter the start and terminating inndex"<<endl;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout << "THE DFS TRAVERSAL IS " << endl;
    dfs(adj, v);

    return 0;
}
