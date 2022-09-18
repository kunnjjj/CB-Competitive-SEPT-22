#include<bits/stdc++.h>
using namespace  std;

#define LL long long 

int n3(vector<int> &A)
{
    int mx_sum=-1e9;
    int n=A.size();


    for(int L=0;L<n;L++)
    {
        for(int R=L;R<n;R++)
        {
            int cur_sum=0;
            for(int i=L;i<=R;i++)
            {
                cur_sum+=A[i];
            }
            mx_sum=max(mx_sum,cur_sum);
        }
    }
    return mx_sum;
}

int n2(vector<int> &A)
{
    int mx_sum=-1e9;
    int n=A.size();
    vector<int> prefix(n);

    for(int i=0;i<n;i++)
    {
        prefix[i]=(i-1>=0?prefix[i-1]:0) + A[i];
    }

    for(int L=0;L<n;L++)
    {
        for(int R=L;R<n;R++)
        {
            int cur_sum=0;
            // for(int i=L;i<=R;i++)
            // {
            //     cur_sum+=A[i];
            // }
            cur_sum=prefix[R]-(L-1>=0?prefix[L-1]:0);
            mx_sum=max(mx_sum,cur_sum);
        }
    }
    return mx_sum;
}

int kadaneN_N(vector<int> &A)
{
    int n=A.size();
    vector<int> best(n);
    int mx_sum=-1e9;
    for(int i=0;i<n;i++)
    {
        best[i]=max((i-1>=0?best[i-1]:0) + A[i], // continue in old subarray
        A[i]); // naya subarray start 
        mx_sum=max(mx_sum,best[i]);
    }

    return mx_sum;

}

int kadane_N(vector<int> &A)
{
    int n=A.size();

    int last_tak=0;
    int mx_sum=-1e9;

    for(int i=0;i<n;i++)
    {
        int best_choice=max(last_tak + A[i], // continue
            A[i]); // naya subarray
        mx_sum=max(mx_sum,best_choice);
        last_tak=best_choice;
    }
    return mx_sum;
}



int main()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    cout<<n3(A)<<endl;
    cout<<n2(A)<<endl;
    cout<<kadaneN_N(A)<<endl;
    cout<<kadane_N(A)<<endl;
    return 0;
}


