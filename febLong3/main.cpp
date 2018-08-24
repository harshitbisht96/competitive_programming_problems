#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        vector<int> v;
        vector< queue <int> > q;
        queue<int> tq;
        for(int i=0;i<26;i++)
        {
            q.push_back(tq);
            v.push_back(0);
        }
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
            int z=int(s[i])-97;
            v[z]++;
            char c=s[i];
            q[int(c)-97].push(i+1);
        }
        int oddCount=0;
        for(int i=0;i<26;i++)
        {
            if(v[i]%2==1)
            {
                oddCount++;
            }
        }
        if(oddCount>=2)
        {
            cout<<"-1"<<endl;
        }
        else{
            char a[s.length()];
            long long int start=0;
            long long int last=s.length()-1;
            for(int i=0;i<26;i++)
            {
                if(v[i]%2==0 && v[i]>0)
                {
                    int temp=0;
                    while(temp<v[i])
                    {
                        a[start]=char(97+i);
                        temp++;
                        a[last]=char(97+i);
                        temp++;
                        start++;
                        last--;
                    }
                }
                if(v[i]%2==1)
                {
                   a[s.length()/2]=char(97+i);
                   int temp=1;
                   while(temp<v[i])
                    {
                        a[start]=char(97+i);
                        temp++;
                        a[last]=char(97+i);
                        temp++;
                        start++;
                        last--;
                    }
                }
            }
            for(int i=0;i<s.length();i++)
            {
                int l=q[int(a[i])-97].front();
                q[int(a[i])-97].pop();
                cout<<l<<" ";

            }
            cout<<endl;
        }
    }
    return 0;
}
