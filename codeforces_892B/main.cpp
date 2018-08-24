#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>swords(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&swords[i]);
    }
    int ans=1;
    int maxLen=swords[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(maxLen<=0)
        {
            ans++;
        }
        maxLen=max(maxLen-1,swords[i]);
    }
    cout<<ans<<endl;
    return 0;
}
