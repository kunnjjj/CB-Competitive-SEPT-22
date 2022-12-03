#include <bits/stdc++.h>
using namespace std;

// sum
class segmentTree
{
    vector<int> seg_tree;
    int identity;
    int n;

public:
    segmentTree(int N, vector<int> &A)
    {
        n = N;
        identity = 0;
        seg_tree = vector<int>(4 * n, identity);
        init(0, 0, n - 1, A);
    }

    void init(int root, int L, int R, vector<int> &A)
    {
        if (L == R)
        {
            seg_tree[root] = A[L];
            return;
        }
        int mid = (L + R) / 2;
        init(2 * root + 1, L, mid, A);
        init(2 * root + 2, mid + 1, R, A);

        seg_tree[root] = seg_tree[2 * root + 1] + seg_tree[2 * root + 2];
        cout << "L: " << L << " , R: " << R << endl;
        cout << seg_tree[root] << endl;
    }

    int query(int root, int qL, int qR, int L, int R)
    {
        if (L > qR)
            return identity;
        if (R < qL)
            return identity;

        if (qL <= L && R <= qR)
            return seg_tree[root];
        int mid = (L + R) / 2;
        int left_ans = query(2 * root + 1, qL, qR, L, mid);
        int right_ans = query(2 * root + 2, qL, qR, mid + 1, R);
        return left_ans + right_ans;
    }

    void update(int root, int idx, int val, int L, int R)
    {
        if (idx < L)
            return; // iske bina bhi hojana chahie (i guess)
        if (idx > R)
            return;
        if (L == R) // we are calling left or right only if idx lies in that range, if L==R , idx has been found
        {
            seg_tree[root] = val;
            return;
        }
        int mid = (L + R) / 2;
        if (idx <= mid)
        {
            update(2 * root + 1, idx, val, L, mid);
        }
        else
        {
            update(2 * root + 2, idx, val, mid + 1, R);
        }
        seg_tree[root] = seg_tree[2 * root + 1] + seg_tree[2 * root + 2];
        cout << "L: " << L << " , R: " << R << endl;
        cout << seg_tree[root] << endl;
    }
};

int main()
{

    vector<int> A = {5, 4, 3, 6, 1, 1, 0};
    for(int i=0;i<(int)A.size();i++) cout<<A[i]<<" ";
    cout<<endl;
    int n = A.size();
    segmentTree tree(n, A);

    cout << "query ans: " << tree.query(0, 2, 6, 0, n - 1) << endl;
    tree.update(0, 6, 5, 0, n - 1);
    cout << "query ans: " << tree.query(0, 2, 6, 0, n - 1) << endl;

    return 0;
}