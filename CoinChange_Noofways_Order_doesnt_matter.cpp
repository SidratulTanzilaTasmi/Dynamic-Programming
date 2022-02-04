#include<bits/stdc++.h>
using namespace std;

int count_total_ways(int coin[], int weight, int idx)
{
    if(weight==0)
    {
        return 1;
    }
    if(weight<0)
    {
        return 0;
    }
    if(idx<=0 && weight>=1)
    {
        return 0;
    }
    return ((count_total_ways(coin, weight-coin[idx-1],idx))+ count_total_ways(coin, weight, idx-1));
}
int count_total_ways_withdp(int coin[], int sum, int n)
{

    int i, j, x, y;
    int table[sum+ 1][n];
    for (i = 0; i <n; i++)
        table[0][i] = 1;
    for (int i = 1; i < sum+ 1; i++)
    {
        for (int j = 0; j <n; j++)
        {
            // Count of solutions including S[j]
            x = (i-coin[j] >= 0) ? table[i - coin[j]][j] : 0;

            // Count of solutions excluding S[j]
            y = (j >= 1) ? table[i][j - 1] : 0;

            // total count
            table[i][j] = x + y;


            /*if(i- coin [ j ] <= 0){x=0;}
            else{x =table [i- coin[ j  ]] [j ];}
            if(j <= 1){ y =0;}
            else{ y= table[ i] [j-1];}
            table[i][ j ]=x+ y;
            */
        }
    }
    return table[sum][n - 1];
}
int main()
{
    int weight=4;
    int coin[]= {1,2,3};
    cout<<"The total number of ways Weight is formed through brute force solution is: "<<count_total_ways(coin,weight, 3)<<endl;
    cout<<"The total number of ways Weight is formed through Dynamic Programming solution is:"<<count_total_ways_withdp(coin,weight,3)<<endl;
}
