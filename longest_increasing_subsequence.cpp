#include<bits/stdc++.h>
using namespace std;
int main()
{
     int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
     int max_length=0;
     int n=8;
     for(int i=0;i<n;i++)
     {
         int cnt=0;
         for(int j=i+1;j<n;j++)
         {
             if(arr[i]<=arr[j]){ cnt++;}
             if(arr[i]>arr[j]){ break;}
         }
         if(cnt>max_length)
         {
             max_length=cnt;
         }
     }
     cout<<max_length;
}
