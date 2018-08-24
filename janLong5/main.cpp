#include <iostream>

using namespace std;

int main()
{
    long long int tc;
    cin>>tc;
    while(tc--)
    {
        long long int x,n;
        cin>>x>>n;
        long long int check=(n+1)/2;
        if((check%2==0 && x%2==0) || (check%2==1 && x%2==1) && n>2)
        {
            long long int arr[n+1]={};
            arr[x]=2;
            long long int sum=((n)*(n+1))/2;
            sum=sum-x;
            sum=sum/2;
            long long int start=0;
            long long int i=n;
            while(sum!=0 && i>0)
            {
                if(i!=x && i<=sum)
                {
                    if((sum-i)!=x)
                    {
                        arr[i]=1;
                        sum=sum-i;
                    }
                }
                i--;
            }
            if(i==0 && sum!=0)
            {
                cout<<"impossible"<<endl;
                continue;
            }
            for(long long int i=1;i<=n;i++)
            {
                cout<<arr[i];
            }
            cout<<endl;
        }
        else{
            cout<<"impossible"<<endl;
            continue;
        }
    }
    return 0;
}
