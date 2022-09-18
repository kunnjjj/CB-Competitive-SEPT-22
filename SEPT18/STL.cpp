#include<bits/stdc++.h>
using namespace std;
int main()
{

    int x; 

    map<int,int> mp;
    unordered_map<int,int> mp2;

    cout<<mp[5]<<endl;
    mp[3];


    cout<<mp.size()<<endl;


    mp.erase(5);

    cout<<mp.size()<<endl;

    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(3);
    s.insert(7);


    cout<<"printing set: "<<endl;
    for(int x:s)
    {
        cout<<x<<" ";
    }
    cout<<endl;


    multiset<int> ms;
    ms.insert(3);
    ms.insert(4);
    ms.insert(4);
    ms.insert(5);


    cout<<"printing multiset: "<<endl;
    for(int x:ms)
    {
        cout<<x<<" ";
    }
    cout<<endl;



    

    multiset<int> :: iterator it=

    it=ms.begin();


    cout<<"smallest in ms: ";
    cout<<(*it)<<endl;


    it=ms.find(3);

    if(it!=ms.end())
    {
        cout<<"entry is: "<<(*it)<<endl;
    }

    it=ms.begin();

    if(it!=ms.end())
    {
        cout<<"smallest is: "<<(*it)<<endl;
    }

    it=ms.find(6);
    if(it==ms.end())
    {
        cout<<"not found"<<endl;
    }

    cout<<"printing A"<<endl;
    vector<int> A(3);
    
    for(int i=0;i<(int)A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    cout<<"size of A: "<<A.size()<<endl;
    A.push_back(5);
    for(int i=0;i<(int)A.size();i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    cout<<"size of A: "<<A.size()<<endl;

    return 0;
}