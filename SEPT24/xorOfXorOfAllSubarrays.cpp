#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &A)
{
    int n = A.size();
    int ans = 0;
    int M=1e9+7;
    for (int i = 0; i < n; i++)
    {
        int L = (i + 1); // I can choose any subarray that starts in [0.....i]=(i+1) choices
        int R = (n - i); // I can choose any subarray that ends in [i...n-1]=(n-i) choices

        int freq = (L * R);
        ans = (ans + (freq * A[i])%M)%M;
    }
    return ans;
}

int XOR (vector<int> & A) {
    int n = A.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int L = (i + 1); // I can choose any subarray that starts in [0.....i]=(i+1) choices
        int R = (n - i); // I can choose any subarray that ends in [i...n-1]=(n-i) choices

        int freq = (L * R);
        // for xor
        // a ^ a = 0 so any element with even freq will be cancelled
        if (freq & 1) // so we consider only indices with odd freq
            ans ^= (A[i]);
    }
    return ans;
}

    int main()
{

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << "sum is: "<< sum(A) << endl;
    cout << "xor is: "<<XOR(A) << endl;

    return 0;
}