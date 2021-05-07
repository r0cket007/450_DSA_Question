/*
    Count Palindromic Subsequence
    Link: https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
    
    Expected Time Complexity: O(N*N)
    Expected Auxiliary Space: O(N*N)

    Constraints:
    1<=length of string str <=1000
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;

//------------------------------------------------------------------------------------------
int mod = 1e9 + 7;
int dp[1001][1001];
int solve(string &str, int i, int j )
{
    int ans = 0 ;
    if( i > j )
    {
        return 0;
    }
    if(dp[i][j] != -1)
        return dp[i][j] ;
    if( i == j )
    {
        return dp[i][j] = 1;
        
    }
    if(str[i] == str[j])
    {
        return dp[i][j] = 1 + solve(str, i + 1, j) + solve(str, i, j - 1);
    }
    if(str[i] == str[j])
        {
            return dp[i][j] = (1 + solve(str, i + 1, j) + solve(str, i, j - 1)) % mod;
        }
        dp[i][j] = solve(str, i + 1, j);
        dp[i][j] = (dp[i][j] + solve(str, i, j - 1)) % mod;
        dp[i][j] = ((dp[i][j] - solve(str, i + 1, j - 1) )% mod + mod ) % mod;
        return dp[i][j];
}

long long countPS(string str)
{
    for(int i=0; i<1001; i++)
    {
        for(int j=0; j<1001; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solve(str, 0, str.length() - 1);
}
//-------------------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string str = "abcb";
        int n = str.length();
        for(int i=0; i<1001; i++)
        {
            for(int j=0; j<1001; j++)
            {
                dp[i][j] = -1;
            }
        }
        cout << "Total palindromic subsequence are : " << countPS(str) << endl;          
        cout << endl ;
    }
    return 0 ;
}