/*
    Arithmetic Number 
    Link: https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
 public :
    int inSequence(int A, int B, int C)
    {
        if (A == B) return true;
        if (C == 0)
            return false;
        if ((B - A > 0 && C < 0) || (B - A < 0 && C > 0))
            return false;
        return !((B - A) % C);
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        Solution obj;
        int a, b, c ;
        cin >> a >> b >> c;
        cout << obj.inSequence(a, b, c);
        cout << endl ;
    }
    return 0 ;
}