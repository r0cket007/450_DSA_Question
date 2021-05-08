/*
    Smallest window in a string containing all the characters of another string
    Link: https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#
    
    Expected Time Complexity: O(|S|)
    Expected Auxiliary Space: O(1)

    Constraints: 
    1 ≤ |S|, |P| ≤ 105
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//----------------------------------------------------------------------------
bool check( string str, string p)
{
    int hash[256] ={0};
    for(int i = 0; i < str.length(); i++)
    {
        hash[str[i]]++;    
    }
    for(int i = 0; i < p.length(); i++)
    {
        hash[p[i]]--;
        if(hash[p[i]] < 0)
        {
            return true;
        }
    }
    return false;
}
string smallestWindow (string str, string p)
{
    int n = str.length();
    int m = p.length();
    int start = 0, end = 0;
    int result  = INT_MAX;
    int arr[256] = {0}, hash[256] = {0};
    string ans;
    for(int i = 0; i < m; i++)
    {
        hash[p[i]]++;
    }
    if(check(str, p))
        return "-1";
    int ct = 0;
    int pos = 0, len = 0;
    while(end < n)
    {
        arr[str[end]] ++;
        if(arr[str[end]] == hash[str[end]])
        {
            ct += hash[str[end]];
        }
        if(ct == m)
        {
            while(start <= end && arr[str[start]] > hash[str[start]] )
            {
                arr[str[start]] --;
                start ++;
            }
            if(result > end - start + 1)
            {
                result = min(result, end - start + 1);
                pos = start ;
                len = result ;
            }
        }
        end ++;
    }
    ans = str.substr(pos, len);
    return ans;
}
//----------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        string S = "zoomlazapzo";
        string P = "oza";
        cout << smallestWindow(S, P);
        cout << endl ;
    }
    return 0 ;
}