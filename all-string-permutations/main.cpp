#include <bits/stdc++.h>

using namespace std;


void addString(char chars[],bool visited[],int len, string s, vector<string>& ans)
{
    if(s.length()==len){
        ans.push_back(s);
        return;
    }
    for(int i=0;i<len;i++)
    {
        if(visited[i]==false)
        {
            visited[i]=true;
            string temp=s;
            temp+=chars[i];
            addString(chars,visited,len,temp,ans);
            visited[i]=false;
        }
    }
    return;
}

int main()
{
    string s;
    cin>>s;
    char chars[s.length()];
    bool visited[s.length()];
    for(int i=0;i<s.length();i++)
    {
        chars[i]=s[i];
        visited[i]=false;
    }
    vector<string> ans;
    string start="";
    addString(chars,visited,s.length(),start,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
