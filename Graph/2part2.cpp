#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    int v,a=0,b=0;
    cout<<"enter the number of vertices"<<endl;
    cin>>v;
    vector<int>adj[v+1];
    cout<<"enter the edges for UNDIRECTED GRAPH"<<endl;
    while (a!=-1 && b!=-1)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    cout<<"THE ADJ LIST:-"<<endl;
    for(int i=0;i<=v;i++)
    {
        cout<<i<<"-> ";
        for(int j=0; j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
    return 0;
}
