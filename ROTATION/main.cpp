#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int k;cin>>k;
        arr.push_back(k);
    }
    for(int i=0;i<n;i++)
    {
        arr.push_back(arr[i]);
    }
    int start=0;
    for(int i=0;i<q;i++)
    {
        char qc;int d;
        cin>>qc>>d;
        if(qc=='C')
        {
            start=start+d;
            start=start%n;
        }
        else if(qc=='A')
        {
            start+=n-d;
            start=start%n;
        }
        else{
            d--;
            cout<<arr[start+d]<<endl;
        }
    }
    return 0;
}
