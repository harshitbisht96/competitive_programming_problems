#include <iostream>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a==b && c==d) || (a==c && b==d) || (a==d && b==c))
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    return 0;
}
