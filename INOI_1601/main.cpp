#include <bits/stdc++.h>

using namespace std;


int main()
{
    long long int n;
    cin>>n;
    long long int A[n+1],P[n+1];
    long long int boss;
    for(long long int i=1;i<=n;i++)
    {
        cin>>A[i];
    }
    for(long long int i=1;i<=n;i++)
    {
        cin>>P[i];
        if(P[i]==-1)
        {
            boss=i;
        }
    }

    long long int ans=0;
    for(long long int i=1;i<=n;i++)
    {
        long long int emp1=i;
        long long int diff=0;
        while(emp1!=-1)
        {
                emp1=P[emp1];
                if(emp1!=-1){
                diff=A[emp1]-A[i];
                ans=max(ans,diff);
                }

        }
    }
    cout<<ans<<endl;


    return 0;
}
