#include <iostream>

using namespace std;

int main()
{
    int tc=0;
    while(true){
    int n;
    cin>>n;
    if(n==0)
    {
        return 0;
    }
    tc++;
    int a[n][n];
    int sum1=0,sum2=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
            sum1+=a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        int out=0,in=0;
        for(int j=0;j<n;j++)
        {
            in+=a[i][j];
        }
        for(int j=0;j<n;j++)
        {
            out+=a[j][i];
        }
        if(in>=out)
        {
            sum2+=(in-out);
        }
    }
    cout<<tc<<". "<<sum1<<" "<<sum2<<endl;
    }

    return 0;
}
