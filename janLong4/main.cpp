#include <bits/stdc++.h>

using namespace std;

long long int dp[5001][5001];

int lcs( vector<char> X,vector<char> Y, int m, int n )
{

   int L[m+1][n+1];
   int i, j;
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;

       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;

       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   return L[m][n];
}

int foo(int n,int m,vector<char> s1,vector<char> s2,int one,int two,char lastchar)
{
    if(dp[one][two]!=-1)
    {
        return dp[one][two];
    }
    int ans1,ans2;
    if(one==n)
    {
        if(lastchar==char(s2[two]))
        {
            return dp[one][two]=s2.size()-two-1;
        }
        else{
            return dp[one][two]=s2.size()-two;
        }
    }
    if(two==m)
    {
        if(lastchar==char(s1[one]))
        {
            return dp[one][two]=s1.size()-one-1;
        }
        else{
            return dp[one][two]=s1.size()-one;
        }
    }

    if(s1[one]==s2[two] )
    {
        if(lastchar==char(s1[one])){
            return dp[one][two]=foo(n,m,s1,s2,one+1,two+1,lastchar);
        }

        else{
            return dp[one][two]=1+foo(n,m,s1,s2,one+1,two+1,char(s1[one]));
        }
    }

    else if(char(s1[one])==lastchar && char(s2[two])!=lastchar)
    {
        ans1=foo(n,m,s1,s2,one+1,two,lastchar);
        return dp[one][two]=ans1;
    }
    else if(char(s2[two])==lastchar && char(s1[one])!=lastchar)
    {
        ans2=foo(n,m,s1,s2,one,two+1,lastchar);
        return dp[one][two]=ans2;
    }
    else{
        ans1=1+foo(n,m,s1,s2,one+1,two,char(s1[one]));
        ans2=1+foo(n,m,s1,s2,one,two+1,char(s2[two]));
        return dp[one][two]=min(ans1,ans2);
    }


}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--){
        vector<char> s1,s2;
        int n,m;
        scanf("%d %d",&n, &m);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                dp[i][j]=-1;
            }
        }
        char lastc='1';
        for(int i=0;i<n;i++)
        {
            char c;
            cin>>c;
            if(c!=lastc)
            {
                s1.push_back(c);
                lastc=c;
            }
        }
        lastc='1';
        for(int i=0;i<m;i++)
        {
            char c;
            cin>>c;
            if(c!=lastc)
            {
                s2.push_back(c);
                lastc=c;
            }
        }
        int ans=lcs(s1,s2,s1.size(),s2.size());
        int h=s1.size()+s2.size()-ans;
        printf("%d \n",h);
    }

}
