#include <iostream>
#include <queue>
#include <vector>
#include <utility>
typedef pair<int, char> cpair;
using namespace std;
int main()
{
    int v, e,x,y;
    char a, b;
    cout << "enter the no of vertices" << endl;
    cin >> v;
    vector<cpair> adj[v];
    queue<cpair> q;
    int dat[v] = {0};
    cout << "enter the no of edges" << endl;
    cin >> e;
    cout << "enter the edge:-vertex and key" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[i].push_back();
        cout << adj[a];
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            dat[adj[i][j]]++;
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (dat[i] == 0)
        {
            q.push(i);
        }
    }
    cout << "TOPOLOGICAL SORT IS" << endl;
    while (!q.empty())
    {
        char x;
        x = q.front();
        q.pop();
        cout << x;
        for (int j = 0; j < adj[x].size(); j++)
        {
            dat[adj[x][j]]--;
            if (dat[adj[x][j]] == 0)
            {
                q.push(ad[x][j]);
            }
        }
    }
    return 0;
}
