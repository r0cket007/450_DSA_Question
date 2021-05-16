/*
    Longest Repeating Subsequence
    LINK : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

    Expected Time Complexity: O(N*N)
    Expected Auxiliary Space: O(N*N)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 

//-----------------------------------------------------------------------------------

int LongestRepeatingSubsequence(string str)
{
    int n=str.size();
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0 ;
            }
            else if(str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
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
        string str = "axxxy";
        cout << LongestRepeatingSubsequence( str ) ;
    }
    return 0 ;
}