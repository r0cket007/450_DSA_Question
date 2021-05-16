/*
    Second most repeated string in a sequence
    Link: https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#

    Expected Time Complexity: O(N*max(|Si|).
    Expected Auxiliary Space: O(N*max(|Si|).

    Constraints:
    1<=N<=103
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//----------------------------------------------------------------------
string secFrequent (string arr[], int n)
{
    map<string, int> mp;
    set<pair<int, string>, greater<pair<int, string>>> s;
    for(int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto i : mp)
    {
        s.insert({i.second, i.first});
    }
    s.erase(s.begin());
    return (s.begin()->second);
}
//----------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        int n ;
        cin >> n ;
        string arr[n];
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
        }
        cout << secFrequent(arr, n);   
        cout << endl ;
    }
    return 0 ;
}