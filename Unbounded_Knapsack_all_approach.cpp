#include<bits/stdc++.h>
using namespace std;
int unbounded(int val[], int wt[], int  W, int n)
{
    int dp[W+1];
    memset(dp, 0, sizeof dp);

    for (int i=0; i<=W; i++)
    {
        for (int j=0; j<n; j++)
        {

            if (wt[j] <= i)
            {
                dp[i] = max(dp[i], dp[i-wt[j]] + val[j]);
                //compae including the weight index, and excluding the weight and adding the value
                //the dp stores the maximmum value that can be made in the ith number of weight
            }
        }
    }
    return dp[W];
}
int unbounded_notdp(int weight[], int value[], int wt, int n)
{
    if(wt<0){ return 0;}
    if(wt==0){ return 0;}
    if(n<=0 && wt>=1){ return 0;}
    return max( unbounded_notdp(weight, value, wt, n-1), (value[n-1]+unbounded_notdp(weight, value, wt- weight [n-1], n)));
}

int main()
{
    int wt=100;
    int value[]= {10,30,20};
    int weight[]= {5,10,15};
    cout<<"Not dyanmic programming: "<<unbounded_notdp(weight, value, wt, 3)<<endl;
    cout<<"Dynamic Programming: "<<unbounded(value, weight, wt, 3)<<endl;
}
