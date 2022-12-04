#include<bits/stdc++.h>

using namespace std;

int max_n=1e5;
// min segtree +INF
vector<int> seg_tree(4*max_n,INT_MAX);
// INT_MAX+1
int identity=INT_MAX;
void init(int root,int L,int R,vector<int> &A)
{
    if(L==R)
    {
        seg_tree[root]=A[L];
        return ;
    }

    int mid=(L+R)/2;

    init(2*root+1,L,mid,A);
    init(2*root+2,mid+1,R,A);

    seg_tree[root]=min(seg_tree[2*root+1],seg_tree[2*root+2]);

}


int query(int root,int qL,int qR,int L,int R)
{
    if(L> qR) return identity;
    if( R < qL) return identity;

    if(qL<=L && R<=qR) return seg_tree[root];

    int mid=(L+R)/2;
    int left_ans=query(2*root+1,qL,qR,L,mid);
    int right_ans=query(2*root+2,qL,qR,mid+1,R);

    return min(left_ans,right_ans);
}

int main()
{
    int n; cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++) cin>>A[i];
    
    init(0,0,n-1,A);

    int q; cin>>q;
    while(q--)
    {
        int qL,qR; cin>>qL>>qR;
        // cout<<"qL: "<<qL<<endl;

        cout<<query(0,qL,qR,0,n-1)<<endl;
    }

    return 0;
}