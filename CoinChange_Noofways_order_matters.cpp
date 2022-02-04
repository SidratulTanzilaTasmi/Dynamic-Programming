#include<bits/stdc++.h>
using namespace std;
int s=0;
int count_ways(int sum,int n, int coins[])
{
    if(sum<0) return 0;

    int table[sum+1], i, j;
    fill(table, table+sum+1, 0);
    table[0]=1;

    for(i=1; i<=sum; i++)
    {

        for(j=0; j<n; j++)
        {
            if(i>=coins[j])
            {

                table[i]+=table[ i- coins[ j ] ];
            }
        }
    }

    return table[sum];
}


int main()
{
    int coin[]= {1,2,3};
    int weight=4;
    cout<<count_ways(weight, 3, coin);
}
