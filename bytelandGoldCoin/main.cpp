#include <bits/stdc++.h>

using namespace std;

map<long long int,long long int> dp;

long long int getMeMax(long long int n)
{
    if(n==1 || n==0)
    {
        return n;
    }
    if(dp.find(n)!=dp.end())
    {
        return dp[n];
    }
    long long int option=getMeMax(n/2)+getMeMax(n/3)+getMeMax(n/4);
    return dp[n]=max(n,option);
}

int main()
{
    long long int n;
    while(cin>>n){
    cout<<getMeMax(n)<<endl;
    }
    return 0;
}
