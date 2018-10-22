#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n+1]={};
    int q;
    cin>>q;
    int ans=0;
    while(q--)
    {
        string s;
        cin>>s;
        if(s=="CLICK")
        {
            int r;
            cin>>r;
            if(arr[r]==0)
            {
                ans++;
                arr[r]=1;
            }
            else{
                ans--;
                arr[r]=0;
            }
            cout<<ans<<endl;

        }
        else{
            for(int i=0;i<=n;i++)
            {
                arr[i]=0;
            }
            ans=0;
            cout<<ans<<endl;
        }
    }
    return 0;
}
