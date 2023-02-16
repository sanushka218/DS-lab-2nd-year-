#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //vector<int> v;// size 0 vector
    vector<int>v[5];//array of vector
   /*  cout << "The capacity is:-" << v.capacity() << endl;
    v.push_back(1);
    cout << "The capacity is:-" << v.capacity() << endl;

    v.push_back(2);
    cout << "The capacity is:-" << v.capacity() << endl;

    v.push_back(3);
    cout << "The capacity is:-" << v.capacity() << endl;

    v.push_back(4);
    cout << "The capacity is:-" << v.capacity() << endl;
    v.push_back(5);
    cout << "The capacity is:-" << v.capacity() << endl;

    //cout << "the size is:-" << v.size() << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout<<endl; */
     /* for (auto i : v2)
    {
        cout << i << " ";
    }
    cout<<endl;
    cout<<"size is:-"<<v2.size()<<"capacity:-"<<v2.capacity()<<endl;
    v2.push_back(11);
     for (auto i : v2)
    {
        cout << i << " ";
    }
    cout<<endl;
    cout<<"size is:-"<<v2.size()<<"capacity:-"<<v2.capacity()<<endl; */
    /* for(int i=0;i<5;i++)
    {
        cout<<"the size of vector "<<i<<" "<<v[i].size()<<endl;
    } */
    v[0].push_back(1);
    v[0].push_back(2);
    v[0].push_back(3);
    v[1].push_back(4);
    v[1].push_back(5);
    v[2].push_back(6);
    v[2].push_back(7);
    v[3].push_back(8);
    v[4].push_back(9);
    v[4].push_back(10);
    //v[5].push_back(11);
    //v[5].push_back(12);
    for(int i=0;i<5;i++)
    {
        cout<<"vector "<<i<<" "<<"->";
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
