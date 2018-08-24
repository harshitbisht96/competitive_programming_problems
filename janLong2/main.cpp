#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector< vector<int> > a;
        for(int i=0;i<n;i++)
        {
            vector<int> tempvec;
            for(int j=0;j<n;j++)
            {
                int num;
                cin>>num;
                tempvec.push_back(num);
            }
            sort(tempvec.begin(),tempvec.end());
            a.push_back(tempvec);
        }
        long long int last=INT_MAX;
        int flag=1;
        long long int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(a[i][j]<last)
                {
                    sum+=a[i][j];
                    last=a[i][j];
                    break;
                }
                if(j==0)
                {
                    flag=0;
                    break;
                }

            }
            if(flag==0)
                {
                    break;
                }

        }
        if(flag==0)
            {
                cout<<-1<<endl;
            }
        else{
                cout<<sum<<endl;
            }

    }
    return 0;
}
