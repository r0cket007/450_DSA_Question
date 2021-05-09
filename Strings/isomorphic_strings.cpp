/*
    Isomorphic Strings
    Link: https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-------------------------------------------------------------------------
bool areIsomorphic(string str1, string str2)
{
    if(str1.size() != str2.size())
    {
        return false;
    }
    int hash1[26] = {0};
    int hash2[26] = {0};
    for(int i = 0; i < str1.size(); i++)
    {
        hash1[str1[i] - 'a']++;
        hash2[str2[i] - 'a']++;
        if(hash1[str1[i] - 'a'] != hash2[str2[i] - 'a'])
        {
            return false;
        }
    }
    return true;
}
//-------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string str1 = "aab", str2 = "xxy";
        cout << areIsomorphic(str1, str2);
        cout << endl ;
    }
    return 0 ;
}