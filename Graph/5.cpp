#include <iostream>
#include <vector>
using namespace std;
void dfsvisit(vector<int> adj[], vector<int>&visited, int i)//IMP- As we have to alter the original
//visited list & not create a copy of it & make changes in it, so we will accept 
//the address of visited vector(call by refrence, to make changes in the original variable)
{
    visited[i] = 1;
    cout << i << " ";
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (visited[adj[i][j]] == 0)
        {
            dfsvisit(adj, visited, adj[i][j]);
        }
    }
}
void dfs(vector<int> adj[], int v)
{
    vector<int> visited(v, 0);
    for (int i = 0; i < v-1; i++)
    {
        if (visited[i] == 0)
            dfsvisit(adj, visited, i);
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
