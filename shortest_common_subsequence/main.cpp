#include <bits/stdc++.h>

using namespace std;
string s1,s2;
string getMyAns(string s1,string s2, int len1, int len2)
{
    if(!len1)
    {
        string temp="";
        for(int i=0;i<len2;i++)
        {
            temp+=s2[i];
        }
        return temp;
    }
     if(!len2)
    {
        string temp="";
        for(int i=0;i<len1;i++)
        {
            temp+=s1[i];
        }
        return temp;
    }
    if(s1[len1-1]==s2[len2-1])
    {
        return getMyAns(s1,s2,len1-1,len2-1)+s1[len1-1];
    }
    string temp1=getMyAns(s1,s2,len1,len2-1)+s2[len2-1];
    string temp2=getMyAns(s1,s2,len1-1,len2)+s1[len1-1];
    if(temp1.length()<=temp2.length())
    {
        return temp1;
    }
    return temp2;
}
int main(){
ios_base::sync_with_stdio(false);
 #ifndef ONLINE_JUDGE
 freopen("input.in","r",stdin);
 freopen("output.out","w",stdout);
 #endif

 while(scanf("%s",&s1) != EOF){
  scanf("%s",&s2);
    int len1=s1.length();
    int len2=s2.length();

    cout<<getMyAns(s1,s2,len1,len2)<<endl;
    }
    return 0;
}
