#include<bits/stdc++.h>
using namespace std;
int max(int a, int b);
int dp[1000][1000];

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if(dp[m][n]!=-1)
   {
       cout<<"DP being used"<<endl;
       return dp[m][n];
   }
   if (X[m-1] == Y[n-1])
     return dp[m][n]=1 + lcs(X, Y, m-1, n-1);
   else
     return dp[m][n]= max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Driver program to test above function */
int main()
{
  memset(dp,-1,sizeof(dp));
  char X[] = "ABACCD";
  char Y[] = "ACDF";

  int m = strlen(X);
  int n = strlen(Y);

  printf("Length of LCS is %d", lcs( X, Y, m, n ) );

  return 0;
}
