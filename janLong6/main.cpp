#include <bits/stdc++.h>

using namespace std;

long long int myNum;
long long int health[1000000];
long long int ans=1;

void dodo(long long int num,long long int n,long long int y)
{
    int end=pow(2,n-1);
    for(int i=num;i>=end;i--)
    {
    if(i<myNum){
        if((num&i)==i )
        {
            if(health[i]>0)
            {
                health[i]=health[i]-y;
                if(health[i]<=0)
                {
                    ans++;
                }
            }
        }
    }
    }
}

void foo(long long int x,long long int y)
{
    long long int num=0,n=0;
    vector<int> vec;
    while(x>0)
    {
        if(n>=17)
        {
            break;
        }

        int last=x&1;
        if(last)
        {
            num+=pow(2,n);
        }
        vec.push_back(last);
        n++;
        x=x>>1;
    }
    int start=0;
    reverse(vec.begin(),vec.end());
    while(start<vec.size())
    {
        if(vec[start]==1){

            dodo(num,n,y);
            num=num-pow(2,n-1);
        }
        n--;
        start++;
    }

}

int main()
{

    cin>>myNum;
    int check=pow(2,10);
    if(myNum<=check)
    {
    for(long long int i=0;i<myNum;i++)
    {
        cin>>health[i];
    }
    long long int q;
    cin>>q;
    for(long long int i=0;i<q;i++)
    {
        long long int x,y;
        cin>>x>>y;
        for(long long int i=0;i<=x;i++)
        {
            if((i & x)==i)
            {
                health[i]=health[i]-y;
            }
        }
        long long int ans=0;
        for(long long int i=0;i<myNum;i++)
        {
            if(health[i]>0)
            {
                ans++;
            }
        }
        cout<<ans<<endl;
    }



    }
    else{

    for(long long int i=0;i<myNum;i++)
    {
        cin>>health[i];
    }
    long long int q;
    cin>>q;
    for(long long int i=0;i<q;i++)
    {
        long long int x,y;
        cin>>x>>y;
        foo(x,y);
        cout<<myNum-ans<<endl;
    }
    }
    return 0;
}
