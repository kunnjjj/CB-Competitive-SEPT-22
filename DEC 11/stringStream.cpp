#include<bits/stdc++.h>
using namespace std;


int main()
{


    string s; 
    getline(cin,s);
    stringstream obj(s);
    string word;
    while(obj>>word)
    {
        cout<<"word is: "<<word<<endl;
        // process word....
    }
    return 0;
}