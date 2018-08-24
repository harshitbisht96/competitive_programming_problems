#include <bits/stdc++.h>

using namespace std;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int tunnels;
        cin >> tunnels;
        long long int tunnelTime,beg=0,f=0;

        for(int i=0;i<tunnels;i++)
        {
            cin >> tunnelTime;
            if(tunnelTime>beg){
                f+=(tunnelTime-beg);
                beg=tunnelTime;
            }
        }
        int c,d,s;
        cin >>c >>d >>s;
        double ans = f*(c-1);
        printf("%.10f",ans);
        cout<<endl;
    }

    return 0;
}
