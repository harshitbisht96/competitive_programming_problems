#include <bits/stdc++.h>

using namespace std;

long long int addLen(long long int dist[],long long int option1,long long int option2)
{
    if(option1+1==option2)
    {
        return 0;
    }
    long long int len1,len2;
    long long int ans=INT_MAX;
    for(long long int i=option1;i<=option2;i++)
    {

        len1=abs(dist[i]-dist[option1]);
        len2=abs(dist[option2]-dist[i+1]);
        ans=min(ans,len1+len2);
    }
    return ans;

}
int main()
{
    long long int tc;
    cin>>tc;
    while(tc--)
    {
        long long int n;
        cin>>n;
        string str; long long int dist[n];
        cin>>str;
        for(long long int i=0;i<n;i++)
        {
            cin>>dist[i];
        }
        long long int length=0;
        int start=0;
        while(str[start]!='1')
        {
            start++;
        }
        length+=dist[start]-dist[0];
        long long int option1=start;long long int option2;

        for(long long int i=start+1;i<n;i++)
        {
            if(str[i]=='1')
            {
                option2=i;
                length+=addLen(dist,option1,option2);
                option1=option2;
            }

        }
        start=n-1;
        while(str[start]!='1')
        {
            start--;
        }
        length+=abs(dist[n-1]-dist[start]);
        cout<<length<<endl;

    }
    return 0;
}
