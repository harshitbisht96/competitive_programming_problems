#include <iostream>

using namespace std;

int main()
{
    long long int tc;
    cin>>tc;
    while(tc--)
    {
        long long int n;
        cin>>n;
        long long int arr[n+1]={};
        arr[0]=1;
        long long int a[n];
        long long int cumsum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cumsum+=a[i];
            cumsum=cumsum%n;
            arr[cumsum]++;
        }
        long long int ans=0;
        for(long long int i=0;i<=n;i++)
        {
            if(arr[i]>=2)
            {
                long long int temp=arr[i];
                long long int tempans=(temp*(temp-1))/2;
                ans+=tempans;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
