#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int v, e, a, b;
    cout << "enter number of vertices" << endl;
    cin >> v;
    cout << "enter number of edges" << endl;
    cin >> e;
    vector<int> adj[v];
    queue<int> ts;
    int dat[v] = {0};
    cout << "enter the starting and terminating vertices for DIRECTED GRAPH" << endl;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            dat[adj[i][j]]++;
        }
    }
    /*   cout<<"OUT DEGREE  IN DEGREE"<<endl;
      for(int i=0;i<v;i++)
      {
          cout<<i<<" -> "<<adj[i].size()<<"\t"<<dat[i]<<endl;
      } */
    for (int i = 0; i < v; i++)
    {
        if (dat[i] == 0)
        {
            ts.push(i);
        }
    }
    cout << "TOPOLOGICAL SORT IS" << endl;
    while (!ts.empty())
    {
        int x;
        x = ts.front();
        ts.pop();
        cout << x << " ";
        for (int j = 0; j < adj[x].size(); j++)
        {
            dat[adj[x][j]]--;
            if (dat[adj[x][j]] == 0)
            {
                ts.push(adj[x][j]);
            }
        }
    }

    return 0;
}
