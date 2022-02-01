#include<bits/stdc++.h>
using namespace std;
int knapsack(int capacity, int value[], int weight[], int item)
{
    if(item==0 || capacity==0){ return 0;}
    if(weight[item-1]> capacity){knapsack(capacity, value, weight, item-1);}
    else{ return max(value[item-1]+knapsack(capacity-weight[item-1],value, weight, item-1), knapsack(capacity, value, weight, item-1));}

}
int main()
{
    int value[]={60,100,120};
    int weight[]={10,20,30};
    int capacity=50;
    cout<<knapsack(capacity, value, weight, 3);
}
