#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m; cin>>n>>m;
    vector<vector<int>> A(n,vector<int> (m));


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) cin>>A[i][j];
    }

    vector<vector<int>> prefix(n,vector<int> (m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            prefix[i][j]=A[i][j]+(j-1>=0?prefix[i][j-1]:0) + (i-1>=0?prefix[i-1][j]:0) - (i-1>=0 && j-1>=0?prefix[i-1][j-1]:0);
        }
    }

    // for(int j=0;j<m;j++)
    // {
    //     for(int i=0;i<n;i++)
    //     {
    //         prefix[i][j]+=(i-1>=0?prefix[i-1][j]:0);
    //     }
    // }

    cout<<"original: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"prefix: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<prefix[i][j]<<" ";
        }
        cout<<endl;
    }






    return 0;
}