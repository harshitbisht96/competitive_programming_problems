#include <iostream>

using namespace std;


void fillsubsets(int start,int num,int notes[],int total,int subsets[])
{
    subsets[total]=1;
    if(start==num)
    {
        return;
    }
    else{
       int newTotal=total+notes[start];
       start=start+1;
       fillsubsets(start,num,notes,newTotal,subsets);
       fillsubsets(start,num,notes,total,subsets);
    }
}

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int subsets[20001]={};
        int num,sum;
        cin>>num>>sum;
        int notes[num];
        for(int i=0;i<num;i++)
        {
            cin>>notes[i];
        }
        fillsubsets(0,num,notes,0,subsets);
        if(subsets[sum]==1)
        {
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}
