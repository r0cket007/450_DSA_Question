/*
        Word Break
        Link: https://practice.geeksforgeeks.org/problems/word-break1352/1#
        
        Expected time complexity: O(s2)
        Expected auxiliary space: O(s) , where s = length of string A

        Constraints:
        1 <= N <= 12
        1 <= s <=1000
*/
#include<bits/stdc++.h>
using namespace std ;
#define int long long
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
//--------------------------------------------------------------------------
int wordBreak(string A, vector<string> &B) 
{
    int n = A.length();
    int dp[n + 1] = {0};
    set<string> se;
    for(auto i : B)
    {
        se.insert(i);
    }
    for(int i = 1; i <= n; i++)
    {
        string s = A.substr(0, i);
        if(dp[i] == 0 && se.find(s) !=se.end())
        {
            dp[i] = true;
        }
        if(dp[i])
        {
           for(int j = i + 1; j <= n; j ++)
           {
               string ss = A.substr(i, j - i);
               if(dp[j] == 0 && se.find(ss) != se.end())
                {
                    dp[j] = true;
                }
           }
        }
        if( dp[n] )
        {
            return true;
        }
    }
    return false ;
}
//--------------------------------------------------------------------------

signed main( )
{
    fast
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n ;
        cin >> n ;
        vector<string> v(n);
        string s;
        for(int i = 0; i < n; i ++)
        {
            cin >> s;    
            v.push_back( s );
        }
        cin >> s;
        cout << wordBreak(s, v);
        cout << endl ;
    }
    return 0 ;
}