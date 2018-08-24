#include <bits/stdc++.h>

using namespace std;

long long int maxSubArraySum(int a[], int size)
{
    long long int max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
    int n,k;
    cin>>n>>k;
    int arr[n];
    int temparr[2*n],finalarr[3*n];
    long long int sum=0,maxPreSum=0,maxPostSum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(i<n)
        {
            sum+=arr[i];
            maxPreSum=max(maxPreSum,sum);
        }
        temparr[i]=arr[i];
        finalarr[i]=arr[i];
        temparr[n+i]=arr[i];
        finalarr[n+i]=arr[i];
        finalarr[(2*n)+i]=arr[i];
    }
    long long int tempSum=0;
    for(int i=n-1;i>=0;i--)
    {
        tempSum+=arr[i];
        maxPostSum=max(maxPostSum,tempSum);
    }

    if(k==1){
        long long int ans= maxSubArraySum(arr, n);
        cout<<ans<<endl;
    }
    else if(k==2){
        long long int ans1 = maxSubArraySum(temparr, 2*n);
        long long int ans2=((k)*sum);
        long long int ans3=(max(maxPreSum,maxPostSum))+sum;
        long long int tempans=max(ans3,max(ans1,ans2));
        cout<<tempans<<endl;
    }
   else{
        long long int ans1 = maxSubArraySum(finalarr, 3*n);
        long long int ans2=((k)*sum);
        long long int ans3=(max(maxPreSum,maxPostSum))+(k-1)*sum;
        long long int ans4=maxPostSum+((k-2)*sum)+maxPreSum;
        long long int tempans=max(ans3,max(ans1,ans2));
        tempans=max(tempans,ans4);
        cout<<tempans<<endl;
    }
    }
    return 0;
}
