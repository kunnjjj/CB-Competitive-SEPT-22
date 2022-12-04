#include<bits/stdc++.h>
using namespace std;
#define int long long
#define float long double
#define deb(x) cout<<#x<<" -> "<<x<<"\n";
int inf=1e18;
int max_n=2e5+3;
vector<int> seg_tree(4 * max_n+3,-inf);
 
void update(int idx,int val,int s,int e,int i)
{
	if(s > e) return ;
	if(s==e)
	{
		seg_tree[i]=val;
		return ;
	}
	int mid=(s+e)/2;
	if(idx<=mid) 
	{
		update(idx,val,s,mid,2*i+1);
	}
	else
	{
		update(idx,val,mid+1,e,2*i+2);
	}
	seg_tree[i]=max(seg_tree[2*i+1],seg_tree[2*i+2]);
}
 
int query(int s,int e,int L,int R,int i)
{
	if(e < L) return -inf;
	if(s > R) return -inf;
 
	if(L<=s && e<=R) return seg_tree[i];
 
	int mid=(s+e)/2;
	int l=query(s,mid,L,R,2*i+1);
	int r=query(mid+1,e,L,R,2*i+2);
 
	return max(l,r);
}
 
signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
 
	int n; cin>>n;
	vector<int> A(n+1);
	for(int i=0;i<n;i++) cin>>A[i+1];
	vector<int> B(n+1);
	for(int i=0;i<n;i++) cin>>B[i+1];
	n++;
 
	update(0,0,0,n-1,0);
	vector<int> ans(n+1,-inf);
	for(int i=1;i<n;i++)
	{
		int get=query(0,n-1,0,A[i]-1,0);
		// deb(get);
		ans[i]=get + B[i];
		update(A[i],ans[i],0,n-1,0);
	}
 
	// for(int x:ans) cout<<x<<" ";
	// cout<<endl;
 
	cout<<*max_element(ans.begin(),ans.end())<<endl;
 
 
 
 
 
    
    return 0;
}