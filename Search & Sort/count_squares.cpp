/*
    Count Squares
    Link: https://practice.geeksforgeeks.org/problems/count-squares3649/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-------------------------------------------------------------------
class Solution 
{
  public:
    int countSquares(int N) 
    {
        int counter = 1;
        int ans = 0;
        while(counter * counter < N)
        {
            ans ++ ;
            counter ++ ;
        }
        return ans;
    }
};
//-------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int N = 15;
        Solution obj;
        cout << obj.countSquares(N);
        cout << endl ;
    }
    return 0 ;
}