#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int count=0;
    string temp=s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='h' && s[i+1]=='i')
        {
            s[i]='?';
            s[i+1]='7';
            count++;
        }
    }
    cout<<count<<endl;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]!='?' && s[i]!='7')
        {
            cout<<s[i];
        }
    }
    cout<<endl;
        for(int i=0;i<temp.length();i++)
    {
        if(temp[i]=='h' && temp[i+1]=='i')
        {
            cout<<'b'<<'y'<<'e';
            i+=1;
        }
        else{
            cout<<temp[i];
        }
    }
    return 0;
}
