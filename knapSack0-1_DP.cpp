#include<bits/stdc++.h>
using namespace std;
int knapsack(int capacity, int val[], int wt[], int item)
{
    int W=capacity;
    int n=item;
   int dp[W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n + 1; i++) {
        for (int w =0; w <= W; w++)
        {
        if (wt[i - 1] <= w){dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);}
        }
    }
    return dp[W];
}
int main()
{
    int value[]={60,100,120};
    int weight[]={10,20,30};
    int capacity=50;
    cout<<knapsack(capacity, value, weight, 3);
}

