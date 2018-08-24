#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,q;
    map<pair<int,int> , int> myMap;
    cin>>n>>q;
    long long int arr[n+1];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result[n][31];
    for(int j=0;j<31;j++)
    {
        int last=arr[0] & 1;
        result[0][j]=last;
        arr[0]=arr[0]>>1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<31;j++)
        {
            int last=arr[i]&1;
            last+=result[i-1][j];
            result[i][j]=last;
            arr[i]=arr[i]>>1;
        }
    }
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        long long int ans=0;
        long long int elements=r-l+1;
        int tempArr[31];
        if(l>0){
            for(int j=30;j>=0;j--)
            {
                tempArr[j]=result[r][j]-result[l-1][j];
            }
        }
        else{
            for(int j=30;j>=0;j--)
            {
                tempArr[j]=result[r][j];
            }
        }
        long long int k=1;
        for(int j=0;j<31;j++)
        {
            long long int zeroes=elements-tempArr[j];
            if(zeroes>tempArr[j])
            {
                ans+=k;
            }
            k=k*2;
        }
        cout<<ans<<endl;
    }

    return 0;
}
