/*
        Count the Reversals
        Link: https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#
        
        Expected Time Complexity: O(|S|).
        Expected Auxiliary Space: O(1).
        Constraints:
        1 ≤ |S| ≤ 105
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-----------------------------------------------------------------
int countRev (string s)
{
    int counter = 0;
    int n = s.length();
    int ans = 0;
    for(int i =0 ; i < n; i ++)
    {
        if( s[i] == '}' )
        {
            if(counter == 0)
            {
                ans ++;
                counter ++;
            }
            else
            {
                counter --;
            }
        }
        else
        {
            counter ++;
        }
    }
    if((counter&1))
        return -1;
    ans += counter / 2;
    return ans;
    
}
//--------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n ;
        string s;
        cin >> s;
        cout << countRev(s);
        cout << endl ;
    }
    return 0 ;
}