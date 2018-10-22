#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
    long long int n;
    cin>>n;
    long long int sze= pow(2,n);
    multiset<long long int> m;
    for(long long int i=0;i< sze;i++)
    {
        int num;cin>>num;
        if(num!=0){
            m.insert(num);
        }
    }
    vector<long long int> vec;
    vector<long long int> tmp;
    tmp.push_back(0);
    for(int i=0;i<n;i++)
    {
        long long int curr= *(m.begin());
        vec.push_back(curr);
        long long int s=tmp.size();
        for(int j=0;j<s;j++)
        {
            long long int sum=curr+tmp[j];
            m.erase(m.find(sum));
            tmp.push_back(sum);
        }
    }
    for(long long int i=0;i<n;i++)
    {
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    }

    return 0;
}
