#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int v;
    cout<<"enter the number of vertices"<<endl;
    cin>>v;
    int a[v][v];
    vector<int>adj[v];
    cout<<"enter the ADJ MATRIX"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i;
        for(int j=0;j<v;j++)
        {
            cin>>a[i][j];
        }
        cout<<endl;
    }
    for (int i = 0; i < v; i++)
    {
        for(int j=0;j<v;j++)
        {
            if (a[i][j]==1)
            {
                adj[i].push_back(j);
            }
            
        }
    }
    cout<<"THE ADJ LIST IS:-"<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<"->";
        for (int j = 0; j<adj[i].size(); j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    return 0;
}
