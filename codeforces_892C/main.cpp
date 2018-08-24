#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];int count1=0,totalgcd;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i==0)
        {
            totalgcd=a[0];
        }
        totalgcd=__gcd(totalgcd,a[i]);
        if(a[i]==1)
        {
            count1++;
        }
    }
    if(totalgcd>1)
    {
        cout<<-1<<endl;
        return 0;
    }
    if(count1>=1)
    {
        cout<<n-count1<<endl;
        return 0;
    }
    int ans = INT_MAX;
    for(int i = 0;i<n;i++) {
        int gc = a[i];
        for(int j = i+1;j<n;j++) {
            gc = __gcd(a[j],gc);
            if(gc==1) {
                ans = min(j-i,ans);
                break;
            }
        }
    }
    cout<<n-1+ans<<endl;

    return 0;
}
