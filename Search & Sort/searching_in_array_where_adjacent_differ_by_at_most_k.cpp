/*
    Searching in an array where adjacent differ by at most k
    Link: https://www.geeksforgeeks.org/searching-array-adjacent-differ-k/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
 public:
    int search(int arr[], int n, int x, int k)
    {
        int i = 0;
        while(i < n)
        {
            if(arr[i] == x)
            {
                break;
            }
            i += max(1LL, abs(x - arr[i]) / k);
        }
        return i;
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int arr[] = {20, 40, 50, 70, 70, 60};
        int n = 5;
        int x = 60, k = 20;
        Solution obj;

        cout << obj.search(arr, n, x, k);
        cout << endl ;
    }
    return 0 ;
}