#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
//hello people how are you, im bored btw, and way too sleepy <3 :)))
int main()
{
    int v, a = 0, b = 0, e, cost;
    cout << "enter number of vertices" << endl;
    cin >> v;
    cout << "enter the number of edges";
    cin >> e;
    vector<pair<int, int>> adj[v+1];//pair-(vertex,key)nj
    cout << "for every edge enter the starting, terminating vertex, & cost of that edge" << endl;
    while (a != -1)
    {
        // cout<<"enter the start and terminating inndex and the weight of vertex"<<endl;
        cin >> a >> b >> cost;
        adj[a].push_back({b, cost});
        adj[b].push_back({a, cost});
    }
    cout << "THE WEIGHTED ADJ LIST IS" << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << " "
             << "->";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << " ( " << adj[i][j].first << " ," << adj[i][j].second << " ) ";
        }
        cout << endl;
    }
    return 0;
}
