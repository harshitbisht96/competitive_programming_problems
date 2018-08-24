#include <iostream>

using namespace std;

bool check(int num)
{
    for(int i=2;i*i<=num;i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
       int x,y;
       cin>>x>>y;
       int ans=1;
       int total=x+y+ans;
       while(!check(total))
       {
           ans++;
           total=x+y+ans;
       }
       cout<<ans<<endl;
    }
    return 0;
}
