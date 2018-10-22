#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int recipies;cin>>recipies;
    vector < pair<long long int,string> > lst;
    for(int i=0;i<recipies;i++)
    {
        long long int score;string name;
        cin>>name>>score;
        pair<long long int,string> mp= make_pair(score,name);
        lst.push_back(mp);
    }
    sort(lst.begin(),lst.end());
    long long int q;cin>>q;
    while(q--)
    {
        string query;cin>>query;
        bool found=false;string ans;
        for(long long int j=recipies-1;j>=0;j--)
        {
            string res=lst[j].second;
            ans= res;
            res=res.substr(0,query.size());
            if(res==query)
            {
                found=true;
                break;
            }
        }
        if(found)
        {
            cout<<ans<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}
