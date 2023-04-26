#include <iostream>
#include <vector>
using namespace std;
int DFSR(vector<int> adj[], int i, int c, vector<int> &status)
{
    c++;
    status[i] = 1;
    cout << i << "\t";
    for (int j = 0; j < adj[i].size(); j++)
    {
        if (status[adj[i][j]] == 0)
        {
            c = DFSR(adj, adj[i][j], c, status);
        }
    }
    return c;
}
void DFS(vector<int> adj[], int v)
{
    int m = 0, k=0;
    vector<int> status(v, 0);
    vector<int> connectedcomponents;
    for (int i = 0; i < v; i++)
    {
        if (status[i] == 0)
        {
            k= DFSR(adj, i, 0, status);
            m++;
            connectedcomponents.push_back(k);
        }
    }
    cout<<endl;
    cout<<"THE NUMBER OF CONNECTED COMPONENTS ARE "<<k<<endl;
    cout<<"THE NO OF CONNECTED COMPONENTS IN EACH TREE IS:-"<<endl;
    for(int i=0;i<connectedcomponents.size();i++)
    {
        cout<<i+1<<" -> "<<connectedcomponents[i]<<endl;
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
       // adj[b].push_back(a);
    }
    cout<<"THE DFS TRAVERSAL IS"<<endl;
    DFS(adj,v);

    return 0;
}
