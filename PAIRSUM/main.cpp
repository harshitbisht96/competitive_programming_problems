#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ans=INT_MIN;
    sort(a.begin(),a.end());
    int start=a[0]+a[1];
    int last= a[n-2]+a[n-1];
    for(int i=start;i<=last;i++)
    {
        int c=0;
        int s=0,l=n-1;
        while(s<l)
        {
            if(a[s]+a[l]==i)
            {
                c++;
                s++;
                l--;
            }
            else if(a[s]+a[l]>i)
            {
                l--;
            }
            else{
                s++;
            }
        }
        ans=max(ans,c);
    }
    cout<<2*ans<<endl;
}
