/*
    Smallest distinct window 
    Link: https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#

*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------------
string findSubString(string str)
{
    int n = str.length();
    set<char> s;
    for(int i = 0; i < n; i++)
    {
        s.insert(str[i]);    
    }
    int start = 0, end = 0;
    int result  = INT_MAX;
    int arr[256] = {0};
    int ct = 0, m = s.size();
    while(end < n)
    {
        if(arr[str[end]] == 0)
        {
            ct ++;
        }
        arr[str[end]] ++;
        if(ct == m)
        {
            while(start <= end && arr[str[start]] > 1 )
            {
                arr[str[start]] --;
                start ++;
            }
            result = min(result, end - start + 1);
        }
        end ++;
    }
    string ans;
    for(int i = 0; i < result; i++)
    {
        ans += 'a';
    }
    return ans;
}
//-------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string s = "GEEKSGEEKSFOR";
        cout << findSubString(s);
        cout << endl ;
    }
    return 0 ;
}