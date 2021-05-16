/*
    Rotate String
    Link: https://leetcode.com/problems/rotate-string/ 
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;

//-----------------------------------------------------------------------------------
bool areRotations(string s1, string s2)
{
    int n = s1.length( );
    int m = s2.length( );
    if( n == 0 && m == 0 ) 
        return true ;
    if( n != m )
        return false ;
    s1 += s1 ;
    int LPS[ m ] = { 0 } ;

    //LPS array
    for(int i = 1; i < m; i ++)
    {
        int j = LPS[i-1];
        while(j>0 && s2[i] != s2[j] )
        {
            j = LPS[j-1];
        }
        if( s2[i] == s2[j] )
        {
            j ++ ;
        }
        LPS[i] = j ;
    }

    //comparing two string now
    int j = 0;
    int i = 0 ;
    while(i < 2 * n)
    {
        while(i < 2 * n && s1[i] == s2[j] )
        {
            i ++ ;
            j ++ ;
            if(j == m)
            {
                return true ;
            }
        }
        if(j==0)
        {
            i ++ ;
            continue ;
        }
        j = LPS[j-1];
    }
    return false;
}
//-----------------------------------------------------------------------------------
signed main( )
{
    #ifndef ONLINE_JUDGE
    r0cket007
    #endif
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n ;
        //cin >> n ;
        string s1, s2 ;
        cin >> s1 >> s2 ;
        cout << (areRotations( s1 , s2 ) ? "YES" : "NO") ;
        cout << endl ;
    }
    return 0 ;
}