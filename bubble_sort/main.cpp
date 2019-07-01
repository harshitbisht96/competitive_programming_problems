
#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;


       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

void printArray(int arr[], int n)
{
   int i;
   for (i=0; i < n; i++)
       printf("%d ", arr[i]);

}

int main()
{
    int arr[1000];
    for(int i=0;i<1000;i++)
    {
        arr[i]=1000-i;
    }
    clock_t time1,time2;
    time1=clock();
    insertionSort(arr, 1000);
    time2=clock();
    printArray(arr, 1000);
    cout<<endl<<time2-time1;
    return 0;
}
