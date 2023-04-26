#include <iostream>
using namespace std;
int adj[50][50];
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
    cout << "enter number of vertices" << endl;
    cin >> n;
    cout << "enter the adjacency matrix" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    // FLLOYD-WARSHALL ALGO:-
    for (int k = 0; k < n; k++) // to take each vertex as mediator
    {
        for (int i = 0; i < n; i++) // to access all entires of weighted matrix
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
            }
        }
    }
    cout << "THE TRANSITIVE CLOSURE MATRIX IS" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
