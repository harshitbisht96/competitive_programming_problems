#include <bits/stdc++.h>

using namespace std;


int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,k;
        cin>>n>>k;
        n=n-k;
        long long int fact=1;
        long long int j=1;
        for(long long int i=n+1;i<=n+k-1;i++)
        {
            fact=fact*i;
            fact=fact/j;
            j++;
        }
        cout<<fact<<endl;
    }
}
