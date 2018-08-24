#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        if(s.length()<=3)
        {
            cout<<"normal"<<endl;
        }
        else{
            int c=0,h=0,e=0,f=0;
            int total=0;
            for(int i=0;i<=s.length()-4;i++)
            {
                int local=0;
                for(int j=i;j<i+4;j++)
                {
                    if(s[j]=='c')
                    {
                        c=1;
                    }
                    else if(s[j]=='h')
                    {
                        h=1;
                    }
                    else if(s[j]=='e')
                    {
                        e=1;
                    }
                    else if(s[j]=='f')
                    {
                        f=1;
                    }
                }
                local=c+h+e+f;
                if(local==4)
                {
                    total++;
                }
                c=0,h=0,e=0,f=0;
            }
            if(total==0)
            {
                cout<<"normal"<<endl;
            }
            else{
                cout<<"lovely "<<total<<endl;
            }
        }
    }
    return 0;
}
