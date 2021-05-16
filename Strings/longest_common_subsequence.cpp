/*
    Longest Common Subsequence
    Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#

    Expected Time Complexity : O(|str1|*|str2|)
    Expected Auxiliary Space: O(|str1|*|str2|)

    Constraints:
    1<=size(str1),size(str2)<=103
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;

//--------------------------------------------------------------------------
int dp[1001][1001];
int solve(string s1, string s2, int i, int j)
{
    if(i >= s1.length() || j >= s2.length())
    {
        return dp[i][j] = 0 ;
    }
    if(dp[i][j] != -1)
        return dp[i][j];
    if(s1[i] == s2[j])
    {
        return dp[i][j] = 1 + solve(s1, s2, i + 1, j + 1);
    }
    else 
        return dp[i][j] = max(solve(s1, s2, i, j + 1), solve(s1, s2, i + 1, j));
        
}
int lcs(int x, int y, string s1, string s2)
{
    for(int i = 0; i < 1001; i++)
    {
        for(int j = 0; j < 1001; j++)
        {
            dp[i][j] = -1;
        }
    }
    return solve(s1, s2, 0, 0);
}
//--------------------------------------------------------------------------

signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string s1 = "ABCDGH";
        string s2 = "AEDFHR";
        int x = s1.length();
        int y = s2.length();
        cout << lcs(x, y, s1, s2);
        cout << endl ;
    }
    return 0 ;
}