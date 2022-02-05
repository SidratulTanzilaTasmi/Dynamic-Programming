#include<bits/stdc++.h>
using namespace std;
int tiling_problem( int n )
{
    int table [n +1];
    table[0 ]=0;
    table [1 ]=1;
    table [2 ]=2;
    for(int i=3;i <n+1; i++)
    {
        table[ i ]= table [ i - 1 ]+ table [ i - 2 ];
    }
    return table [ n ];
}

int main()
{
    int n= 4;
    cout<<tiling_problem(n)<<endl;
}
