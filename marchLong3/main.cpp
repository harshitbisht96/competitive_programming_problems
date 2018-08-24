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
        long long int arr[n];
        long long int votes[n]={};
        for(long long int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(long long int i=0;i<n;i++)
        {
            long long int num1=arr[i];
            long long int num2=arr[i];
            long long int forward=i+1;
            long long int backward=i-1;
            while(forward<=n-1 && num1>=0)
            {
                votes[forward]++;
                num1=num1-arr[forward];
                forward++;
            }
            while(backward>=0 && num2>=0)
            {
                votes[backward]++;
                num2=num2-arr[backward];
                backward--;
            }
        }
        for(long long int i=0;i<n;i++)
        {
            cout<<votes[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
