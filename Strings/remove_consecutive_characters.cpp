/*
    Remove Consecutive Characters
    Link: https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/
    
    Expected Time Complexity: O(|S|).
    Expected Auxiliary Space: O(|S|).
    
    Constraints:
    1<=|S|<=105
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//------------------------------------------------------------------------------
string removeConsecutiveCharacter(string S)
{
    int i = 0;
    int n = S.length();
    string ans;
    while(i < n)
    {
        ans += S[i];
        while(i < n && ans.back() == S[i])
        {
            i ++ ;
        }
    }
    return ans;
}
//------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string A = "aaabbbacc";
        cout << removeConsecutiveCharacter(A);
        cout << endl ;
    }
    return 0 ;
}
