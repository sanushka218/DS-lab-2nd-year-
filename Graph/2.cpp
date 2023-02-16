#include <iostream>
#include <vector>
#include<queue>
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
    cout << "THE ADJ LIST IS\n"
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
    }
    

    return 0;
}
