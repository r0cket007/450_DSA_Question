/*
    Transform One String to Another using Minimum Number of Given Operation
    Link: https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------------------
int ConvertAtoB(string s1, string s2)
{
    int ans = 0;
    int count1[256] = {0}, count2[256] = {0};
    int n = s1.length();
    for(auto i : s1)
    {
        count1[i] ++;
    }
    for(auto i : s2)
    {
        count2[i] ++;
    }
    for(int i = 0; i < 256; i ++)
    {
        if( count1[i] != count2[i] )
        {
            return -1;
        }
    }
    int ct1 = n - 1, ct2 = n - 1;
    while(ct1 >= 0)
    {
        if( s1[ct1] != s2[ct2] )
        {
            while(ct1 >= 0 && s1[ct1] != s2[ct2])
            {
                ct1 --;
                ans ++;
            }
        }
        if( ct1 >= 0 )
        {
            ct1 -- ;
            ct2 -- ;
        }
    }
    return ans;
}
//---------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        string A = "EACBD", B = "EABCD";
        cout << ConvertAtoB(A, B);           
        cout << endl ;
    }
    return 0 ;
}