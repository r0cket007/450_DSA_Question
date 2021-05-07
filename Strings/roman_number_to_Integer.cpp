/*
    Roman Number to Integer
    Link: https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1#
    
    Expected Time Complexity: O(|S|), |S| = length of string S.
    Expected Auxiliary Space: O(1)

    Constraints:
    1<=roman no range<=3999
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-----------------------------------------------------------------------------
int romanToDecimal(string &str) 
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int res = 0;
    
    for(int i = 0; i < str.size(); i++)
    {
        if(i+1 < str.size() && mp[str[i]] < mp[str[i+1]])
        {
            res += mp[str[i+1]] - mp[str[i]];
            i += 1;
        }
        else
        {
            res += mp[str[i]];
        }
    }
    
    return res;
}
//--------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string str = "IV";
        cout << romanToDecimal(str);   
        cout << endl ;
    }
    return 0 ;
}