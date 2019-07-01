#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j]=arr[i];
            }
            else{
                dp[i][j]=-1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            dp[i][j]=
nKJYNJKY        {
        }
    }
    int maxElem=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            maxElem=max(maxElem,dp[i][j]);
        }
    }
    cout<<maxElem;
    return 0;
}
