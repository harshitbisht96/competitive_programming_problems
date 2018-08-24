#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int c,d,s;
        cin>>c>>d>>s;
        int ans=(c-1)*a[0];
        cout<<ans<<".000000000"<<endl;
    }
    return 0;
}
