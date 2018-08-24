#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    int a[n];
    int myMap[n][n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            myMap[i][j]=__gcd(a[i],a[j]);
        }
    }

    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        int ans=-1;
        for(int i=l;i<r;i++)
        {
            for(int j=i+1;j<=r;j++)
            {
               int temp=myMap[i][j];
				if(temp>ans)
					ans=temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
