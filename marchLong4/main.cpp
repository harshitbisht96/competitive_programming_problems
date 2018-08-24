#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > seg;
vector<int> job1(int num)
{
    vector<int> fool;
    fool.push_back(0);
    for(int i=1;i<=1000;i++)
    {
        if(__gcd(num,i)==1)
        {
            fool.push_back(1);
        }
        else{
            fool.push_back(0);
        }
    }
    return fool;
}

vector<int> job2( vector<int> a1, vector<int> a2)
{
    vector<int> fool;
    fool.push_back(0);
    for(int i=1;i<=1000;i++)
    {
        fool.push_back(a1[i]+a2[i]);
    }
    return fool;
}

void constTree(int arr[], int lo, int hi,int pos)
{
    if(lo==hi)
    {
        vector<int> tmp=job1(arr[lo]);
        seg[pos]=tmp;
        return;
    }
    int mid=(lo+hi)/2;
    constTree(arr,lo,mid,(2*pos)+1);
    constTree(arr,mid+1,hi,(2*pos)+2);
    seg[pos]=job2(seg[(2*pos)+1],seg[(2*pos)+2]);
    return;
}

void update(int arr[],int lo, int hi, int idx, int val,int pos)
{
    if(lo==hi)
    {
        arr[idx]=val;
        seg[pos]=job1(val);
        return;
    }
    int  mid=(lo+hi)/2;
    if(lo<=idx && idx<=mid)
    {
        update(arr,lo,mid,idx,val,(2*pos)+1);
    }
    else{
        update(arr,mid+1,hi,idx,val,(2*pos)+2);
    }
    seg[pos]=job2(seg[(2*pos)+1],seg[(2*pos)+2]);
}

vector<int> foo(int arr[],int lo, int hi, int l, int r, int pos)
{
    if(r<lo || l>hi)
    {
        vector<int> pt;
        for(int i=0;i<1001;i++)
        {
            pt.push_back(0);
        }
        return pt;
    }
    if(l<=lo && hi<=r)
    {
        return seg[pos];
    }
    int mid=(lo+hi)/2;
    return job2(foo(arr, lo,mid,l,r,(2*pos)+1),foo(arr, mid+1,hi,l,r,(2*pos+2)));
}

int main()
{

    int n,q;
    cin>>n;
    for(int i=0;i<1000;i++)
    {
        vector<int> v;
        seg.push_back(v);
    }
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    constTree(arr,0,n-1,0);
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int typ;cin>>typ;
        if(typ==1)
        {
            int pos,val;
            cin>>pos>>val;
            pos--;
            update(arr,0,n-1,pos,val,0);
        }
        else{
            int l,r,g;
            cin>>l>>r>>g;
            l--;r--;
            vector<int> ans=foo(arr,0,n-1,l,r,0);
            cout<<ans[g]<<endl;
        }
    }
    return 0;
}
