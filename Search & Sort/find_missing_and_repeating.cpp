/*
    Find Missing And Repeating
    Link: https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//---------------------------------------------------------------------------
class Solution{
public:
    long long *findTwoElement(int *arr, int n) 
    {
        long long repeated = 1;
        long long missing = 0;
        long long sum = 0;
        for(int i = 0; i < n; i ++)
        {
            if( arr[abs(arr[i]) - 1] < 0 )
            {
                repeated = abs(arr[i]);
            }
            else arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
            sum += abs(arr[i]);    
        }
        long long temp = ((long long)n * (n + 1)) / 2;
        sum -= repeated;
        missing = temp - sum;
        long long *ans = new long long[2];
        ans[0] = repeated;
        ans[1] = missing;
        return ans;
    }
};
//---------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    cin >> testcases ;
    while( testcases -- )
    {
        int n ;
        int arr[] = {1, 2, 3, 4, 4, 5, 6, 7};
        n = 7;
        Solution obj;
        int *ans = obj.findTwoElement(arr, n);   
        cout << endl ;
    }
    return 0 ;
}