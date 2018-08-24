#include <bits/stdc++.h>

using namespace std;

int main()
{
    int noOfSoldiers;
    cin>>noOfSoldiers;
    int c=0;
    int weaponsArray[noOfSoldiers];
    for(int i=0;i<noOfSoldiers;i++)
    {
        cin>>weaponsArray[i];
    }
    for(int i=0;i<noOfSoldiers;i++)
    {
        if(weaponsArray[i]%2==0)
        {
            c++;
        }
        else{
            c--;
        }
    }
    if(c>0)
    {
        cout<<"READY FOR BATTLE";
    }
    else{
        cout<<"NOT READY";
    }
    return 0;
}
