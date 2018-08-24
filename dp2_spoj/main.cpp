#include <bits/stdc++.h>

using namespace std;

int main()
{
  int tc;
  cin>>tc;
  for(int i=0;i<tc;i++)
  {
   string n;
   cin>>n;
   int arr[10]={};
   for(int i=0;i<n.length();i++)
   {

       int last=n[i]- '0';
       arr[last]++;
  }
   string s="";
   for(int i=65;i<=90;i++)
   {
       int temp=i;
       int last=temp%10;
       temp=temp/10;
       int first=temp%10;
       if(first==last)
       {
           if(arr[first]>=2)
           {
               s=s+char(i);
           }
       }
       else{
        if(arr[first]>=1 && arr[last]>=1)
        {
            s=s+char(i);
        }
       }
   }
   cout<<s<<endl;
  }
    return 0;
}
