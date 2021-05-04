/*
    subsequences of a string
    LINK : https://www.geeksforgeeks.org/print-subsequences-string/
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 
int N = 501 ;
vector<vector<int>> ans;
//-----------------------------------------------------------------------------------
void printSolution(int p[], int n) 
{ 
    int k; 
    ans.push_back({p[n], n});
    if (p[n] == 1) 
    {
        return ;
    }
    printSolution(p, p[n] - 1);
} 
vector<vector<int>> solveWordWrap(vector<int>nums, int k) 
{ 
    int extra[N][N];
    int cost[N][N];
    int dp[N]; 
    int n = nums.size();
    for(int i = 0 ; i <= n; i ++)
    {
        extra[i][0] = 0;
    }
    for(int i = 1; i <= n; i ++)
    {
        int spaces = k ;
        for(int j = i; j <= n; j ++)
        {
            spaces = spaces - nums[j - 1] ;
            extra[i][j] = spaces;
            spaces --;
            if(extra[i][j] < 0)
            {
                extra[i][j] = INT_MAX;
            }
            else if(j == n)
            {
                extra[i][j] = 0;
            }
            else
            {
                extra[i][j] *= extra[i][j];
            }
        }
    }
    int p[n+1], c[n+1] = {0};
    for(int i = 1; i <= n; i ++ )
    {
        c[i] = INT_MAX;
    }
    pair<int,int> temp;
    for(int j = 1; j <= n; j ++)
    {
        for(int i = 1 ; i <=j ; i ++)
        {
            if(c[i-1] != INT_MAX && extra[i][j] != INT_MAX && c[i - 1] + extra[i][j] < c[j])
            {
                c[j] = c[i - 1] + extra[i][j];
                p[j] = i;
            }
        }
        
    }
    printSolution(p, n); 
    reverse(ans.begin(), ans.end());
    return ans;
} 
//-------------------------------------------------------------------------------------
signed main( )
{
    #ifndef ONLINE_JUDGE
    r0cket007
    #endif
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int l[] = {3, 2, 2, 5}; 
        int n = sizeof(l)/sizeof(l[0]); 
        int M = 6; 
        solveWordWrap (l, n, M);
    }
    return 0 ;
}