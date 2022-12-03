// https://www.codechef.com/problems/BRKNLIFE?tab=statement

#include <iostream>
using namespace std;


char kuch_aur(char x)
{
    if(x=='e') return 'a';
    return 'e';
    
}
void solve()
{
    int n,m; cin>>n>>m;
    string S,A;
    cin>>S>>A;
    
    int i=0,j=0;
    while(i<n)
    {
        if(j==m)
        {
            cout<<-1<<endl;
            return ;
        }
        if(S[i]==A[j])
        {
            i++;
            j++;
            continue;
        }
        
        if(S[i]=='?')
        {
             S[i]=kuch_aur(A[j]);
             i++;
        }
        else
        {
            i++;
        }
    }
    if(j==m)
        {
            cout<<-1<<endl;
            return ;
        }
        cout<<S<<endl;
    
}
int main() {
	// your code goes here
	int t; cin>>t;
	while(t--)
	{
	    solve();
	}
	
	return 0;
}
