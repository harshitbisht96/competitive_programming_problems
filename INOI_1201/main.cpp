#include <bits/stdc++.h>

using namespace std;
bool sortinrev(const pair<int,int> &a,
               const pair<int,int> &b)
{
       return (a.first > b.first);
}
int main()
{
    int n;cin>>n;
    int cobol[n];
    vector< pair<int,int> > vec;
    for(int i=0;i<n;i++)
    {
        cin>>cobol[i];
        int b,c;
        cin>>b>>c;
        int sum=b+c;
        pair<int,int> p=make_pair(sum,i);
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end(),sortinrev);
    int ans=-1;
    int last=0;
    for(int i=0;i<n;i++)
    {
        int total=last+vec[i].first+cobol[vec[i].second];
        ans=max(ans,total);
        last+=cobol[vec[i].second];
    }
    cout<<ans<<endl;
    return 0;
}
