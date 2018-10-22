#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        string s;cin>>s;
        string ori=s;
        string ans=s;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    //char i'th at j'th position
                    string temp=s.substr(i,1);
                    s.erase(s.begin()+i);
                    s.insert(j,temp);
                    ans=min(s,ans);
                }
                s=ori;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}
