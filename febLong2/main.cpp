#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m,x,k,e=0,o=0;
        cin>>n>>m>>x>>k;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='E')
            {
                e++;
            }
            else{
                o++;
            }
        }
        int flag=0;
        for(int i=1;i<=m;i++)
        {
            if(n<=0)
            {
                cout<<"yes"<<endl;
                flag=1;
                break;
            }
            if(i%2==1)
            {
                if(o>0){
                    n=n-min(x,o);
                    o=o-min(x,o);
                }
            }
            else if (i%2==0){
                if(e>0){
                    n=n-min(x,e);
                    e=e-min(x,e);
                }
            }
        }
        if(n<=0 && flag==0)
        {
            cout<<"yes"<<endl;
            flag=1;
        }
        if(flag==0)
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
