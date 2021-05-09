/*
    Longest Palindrome
    LINK : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
    Expected Time Complexity: O(n*n)
    Expected Space Complexity: O(1)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 
//-----------------------------------------------------------------------------------
string longestPalin (string s)
{
    int n = s.length( ) ;
    int start_idx = 0 ;
    int end_idx = 0 ;
    int mx = 1 ; 
    for( int i = 0 ; i < n ; i ++ )
    {
        //for odd palindromic string
        int l = i - 1 ;
        int r = i + 1 ;
        int ct = 1 ;
        while( l >= 0 && r < n && s[ l ] == s[ r ] )
        {
            l -- ;
            r ++ ;
            ct += 2 ;
        }
        if( ct > mx )
        {
            mx = ct ;
            start_idx = l + 1 ;
            end_idx = r - 1 ;
        }
        //for even palindromic strings
        l = i ;
        r = i + 1 ;
        ct = 0 ;
        while( r < n && l >= 0 && s[ l ] == s[ r ] )
        {
            ct += 2 ;
            l -- ;
            r ++ ;
        }
        if( ct > mx )
        {
            mx = ct ;
            start_idx = l + 1 ;
            end_idx = r - 1 ;
        }

    }
    return s.substr( start_idx , (end_idx - start_idx + 1) ) ;
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
        string S; 
        cin >> S;
        cout << longestPalin(S) << endl;
    }
    return 0 ;
}