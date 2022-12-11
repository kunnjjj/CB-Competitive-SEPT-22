#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    int capacity; cin>>capacity;
    vector<int> A(n);

    for(int &x:A) cin>>x;

    vector<int> minRides((1<<n),(int)1e9);  
    // har possible subset ke liye, 
    // ek unique index should be there
    // and hence 2^n size
    vector<int> maxWeight((1<<n),0);


    minRides[0]=0;
    maxWeight[0]=0; // abhi tak ride nahi hui hai

    for(int mask=1;mask<(1<<n);mask++)
    {
        // mask represents a subset

        // eg if mask=1011=11, 0th, 1st, 3rd

        for(int bit=0;bit<n;bit++)
        {
            if(mask&(1<<bit)) // person[bit] is present
            {
                int remainingMask=mask^(1<<bit);
                // represents subset excluding person[bit]
                int oldMinRides=minRides[remainingMask];
                int oldMaxWeight=maxWeight[remainingMask];
                int myRides,myMaxWeight;
                if(A[bit] <= oldMaxWeight)
                {
                    myRides= oldMinRides;
                    myMaxWeight=oldMaxWeight-A[bit];
                }
                else
                {
                    myRides=1 + oldMinRides;
                    myMaxWeight=capacity- A[bit];
                } 
                  
                if(myRides < minRides[mask])
                {
                    minRides[mask]=myRides;
                    maxWeight[mask]=myMaxWeight;
                }
                else if(myRides== minRides[mask])
                {
                    maxWeight[mask]=max(maxWeight[mask],myMaxWeight);
                }
            }
        } 
    }
    cout<<minRides[(1<<n)-1]<<endl;

    // 1111= (1<<4)-1 



    return 0;
}