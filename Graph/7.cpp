#include <iostream>
using namespace std;
int w[50][50];
int d[50][50];
int min(int x, int y)
{
    if (x < y)
        return x;
    else
        return y;
}
int main()
{
    int n;
    cout<<"enter number of vertices"<<endl;
    cin>>n;
    cout<<"enter the weighted matrix"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>w[i][j];
            if(i!=j)
            {
                if (w[i][j]==0)
                {
                    d[i][j]= __INT_MAX__/2;
                }
                else{
                    d[i][j]=w[i][j];
                } 
            }
            else{
                d[i][j]=0;
            }
        }
    }
    //FLLOYD-WARSHALL ALGO:-
    for(int k=0;k<n;k++)//to take each vertex as mediator
    {
        for(int i=0;i<n;i++)//to access all entires of weighted matrix
        {
            for(int j=0;j<n;j++)
            {
                d[i][j]= min(d[i][j],(d[i][k]+d[k][j]));
            }
        }
    }
    cout<<"ALL PAIRS SHORTEST PATH IS"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<d[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
