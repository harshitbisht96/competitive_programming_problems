#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=0;
    int maxTillNow=INT_MIN;
    for(int i=0;i<n;i++)
    {
        ans=ans+arr[i];
        if(ans>maxTillNow)
        {
            maxTillNow=ans;
        }
        if(ans<0)
        {
            ans=0;
        }
    }
    cout<<maxTillNow;
}