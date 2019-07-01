#include <bits/stdc++.h>

using namespace std;


int myKnapSack(int n,int wt[],int val[],int W)
{
    if(W<=0 || n==0)
    {
        return 0;
    }
    if(wt[n-1]>W)
    {
        return myKnapSack(n-1,wt,val,W);
    }
    else{
            int val1=val[n-1]+myKnapSack(n-1,wt,val,W-wt[n-1]);
            int val2=myKnapSack(n-1,wt,val,W);
            return max(val1,val2);
    }
}

int main()
{
    int n,W;
    cin>>n;
    cin>>W;
    int wt[n],val[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
    }
    cout<<myKnapSack(n,wt,val,W);
    return 0;
}
