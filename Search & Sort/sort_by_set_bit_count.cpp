/*
    Sort by Set Bit Count
    Link: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public :
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, [](int a, int b) { return __builtin_popcount(a) > __builtin_popcount(b); });
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
        int n = 9;
        Solution obj;
        obj.sortBySetBitCount(arr, n);
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0 ;
}