#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        long long int n;
        cin>>n;
        long long int ans=0;
        long long int arr[n];
        long long int maxNum=INT_MIN;
        map<long long int,long long int> duplicate;
        map<long long int,long long int> checked;
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
            maxNum=max(arr[i],maxNum);
            checked[arr[i]]=0;
            duplicate[arr[i]]=0;
        }
        for(long long int i=0;i<n;i++)
        {
            duplicate[arr[i]]=duplicate[arr[i]]+1;
        }
        for(int i=0;i<n;i++)
        {
            if(duplicate[arr[i]]>1 && checked[arr[i]]==0)
            {
                ans=ans+duplicate[arr[i]]-1;
                checked[arr[i]]=1;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
