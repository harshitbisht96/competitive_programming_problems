#include <bits/stdc++.h>

using namespace std;

int dp[301][301];
int ans[301]={};


int sol(int last,int n)
{
    int lastans=last;
    for(int i=0;i<n;i++)
    {
        if(ans[i]==1)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]==1 && ans[j]==0)
                {
                    ans[j]=1;
                    lastans++;
                }
            }
        }
    }
    if(lastans==last)
    {
        return lastans;
    }
    else{
        sol(lastans,n);
    }
}

void setRelations(vector< vector<int> > vec,int n, int k)
{
    for(int i=0;i<n-1;i++)
    {
        vector<int> curr1= vec[i];
        for(int j=i;j<n;j++)
        {
            vector<int> curr2= vec[j];
            vector<int> temp(602);
            vector<int>::iterator it=set_intersection (curr1.begin(),curr1.end(),curr2.begin(),curr2.end(), temp.begin());
            temp.resize(it-temp.begin());
            if(temp.size()>=k)
            {
                dp[i][j]=1;
                dp[j][i]=1;
            }
            else{
                dp[i][j]=0;
                dp[j][i]=0;
            }

        }
    }
}

int main()
{
    ans[0]=1;
    int n,k;
    cin>>n>>k;
    vector< vector<int> > vec;
    for(int i=0;i<n;i++)
    {
        int rel;cin>>rel;
        vector<int> knows;
        for(int j=0;j<rel;j++)
        {
            int num;cin>>num;
            knows.push_back(num);
        }
        sort(knows.begin(),knows.end());
        vec.push_back(knows);
    }
    setRelations(vec,n,k);
    int a=sol(1,n);
    cout<<a<<endl;
    return 0;
}
