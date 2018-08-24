#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[26]={};
    int shocks=0;char uniqueChar;
    int flag=0,countShocks=0;
    for(int i=0;i<n;i++)
    {
        string s1,s2;
        cin>>s1>>s2;
        if(s1[0]=='!')
        {
            if(flag==1)
            {
                shocks++;
            }
            else{
                int tempo[26]={};
                for(int i=0;i<s2.length();i++)
                {
                    if(tempo[int(s2[i])-97]==0){
                        a[int(s2[i])-97]++;
                        tempo[int(s2[i])-97]=1;
                    }
                }
                countShocks++;
                int countUnique=0;char temp;
                for(int i=0;i<26;i++)
                {
                    if(a[i]==countShocks)
                    {
                        countUnique++;
                        temp=char(i+97);
                    }
                }
                if(countUnique==1)
                {
                    uniqueChar=temp;
                    flag=1;

                }
            }
        }
        if(s1[0]=='.')
        {
                int tempo[26]={};
                for(int i=0;i<s2.length();i++)
                {
                    if(tempo[int(s2[i])-97]==0){
                        a[int(s2[i])-97]=INT_MIN;
                        tempo[int(s2[i])-97]=1;
                    }
                }
                int countUnique=0;char temp;
                for(int i=0;i<26;i++)
                {
                    if(a[i]==countShocks)
                    {
                        countUnique++;
                        temp=char(i+97);
                    }
                }
                if(countUnique==1)
                {
                    uniqueChar=temp;
                    flag=1;

                }
        }
        if(s1[0]=='?')
        {
            if(flag==1 && s2[0]!=uniqueChar)
            {
                shocks++;
            }
            else{
                for(int i=0;i<26;i++)
                {
                    a[int(s2[0])-97]=INT_MIN;
                }
                int countUnique=0;char temp;
                for(int i=0;i<26;i++)
                {
                    if(a[i]==countShocks)
                    {
                        countUnique++;
                        temp=char(i+97);
                    }
                }
                if(countUnique==1)
                {
                    uniqueChar=temp;
                    flag=1;

                }
            }
        }
    }
    cout<<shocks<<endl;
    return 0;
}
