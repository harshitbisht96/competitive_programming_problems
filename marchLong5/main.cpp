#include <bits/stdc++.h>

using namespace std;

bool foo(long long int a,long long  int b,long long int c) {
return (a+b > c) && (a+c > b) && (b+c > a);
}

int main()
{
    long long int n;
    long long int q;
    cin>>n;
    cin>>q;
    long long int arr[n+1];
    for(long long int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }

    for(long long int i=0;i<q;i++)
    {
        int typ;cin>>typ;
        if(typ==1)
        {
            int pos,val;
            cin>>pos>>val;
            arr[pos]=val;
        }
        else{
            int l,r;
            cin>>l>>r;
            long long int ans=0;
            if((r-l)>=2){
                long long int sz=r-l+1;
                long long int tmp[sz];
                for(int i=0;i<sz;i++)
                {
                    tmp[i]=arr[i+l];
                }

                sort(tmp,tmp+sz);
                for (long long int i = sz-1; i >= 2; i--) {
                    if (foo(tmp[i-2], tmp[i-1], tmp[i])) {
                    ans=tmp[i-2]+tmp[i-1]+tmp[i];
                    break;
                    }
                    if(ans!=0)
                    {
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
