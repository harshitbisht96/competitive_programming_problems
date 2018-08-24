#include <iostream>

using namespace std;



void constTree(int arr[],int seg[], int lo, int hi,int pos)
{
    if(lo==hi)
    {
        seg[pos]=arr[lo];
        return;
    }
    int mid=(lo+hi)/2;
    constTree(arr,seg,lo,mid,(2*pos)+1);
    constTree(arr,seg, mid+1,hi,(2*pos)+2);
    seg[pos]=min(seg[(2*pos)+1],seg[(2*pos)+2]);
    return;
}

void update(int arr[],int seg[],int lo, int hi, int idx, int val,int pos)
{
    if(lo==hi)
    {
        arr[idx]=val;
        seg[pos]=val;
        return;
    }
    int  mid=(lo+hi)/2;
    if(lo<=idx && idx<=mid)
    {
        update(arr,seg, lo,mid,idx,val,(2*pos)+1);
    }
    else{
        update(arr,seg,mid+1,hi,idx,val,(2*pos)+2);
    }
    seg[pos]=min(seg[(2*pos)+1],seg[(2*pos)+2]);
}

int foo(int arr[], int seg[], int lo, int hi, int l, int r, int pos)
{
    if(r<lo || l>hi)
    {
        return INT_MAX;
    }
    if(l<=lo && hi<=r)
    {
        return seg[pos];
    }
    int mid=(lo+hi)/2;
    int p1=foo(arr, seg, lo,mid,l,r,(2*pos)+1);
    int p2=foo(arr, seg, mid+1,hi,l,r,(2*pos+2));
    return min(p1,p2);
}

int main()
{
    int n,q;
    cin>>n>>q;
    int arr[n];
    int seg[100];
    for(int i=0;i<100;i++)
    {
        seg[i]=100000;
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    constTree(arr,seg,0,n-1,0);
    for(int i=0;i<9;i++)
    {
        cout<<seg[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<q;i++)
    {
        int typ;cin>>typ;
        if(typ==1)
        {
            int pos,val;
            cin>>pos>>val;
            pos--;
            update(arr,seg,0,n-1,pos,val,0);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--;r--;
            cout<<foo(arr,seg,0,n-1,l,r,0)<<endl;
        }
    }
    return 0;
}
