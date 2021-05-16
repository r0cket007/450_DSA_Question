/*
    Find Pair Given Difference
    Link: https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

    Expected Time Complexity: O(L*Log(L)).
    Expected Auxiliary Space: O(1).

    Constraints:
    1 ≤ L ≤ 104
    1 ≤ Arr[i], N ≤ 105
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    for(int i = 0; i < size - 1; i ++)
    {
        int target = n + arr[i];
        int l = i + 1;
        int r = size - 1;
        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            if(arr[mid] == target)
            {
                return true;
            }
            if(arr[mid] > target)
            {
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
    }
    return false;
}
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int size = 6, n = 78;
        int arr[] = {5, 20, 3, 2, 5, 80};
        cout << (findPair(arr, size, n) ? 1 : -1);
        cout << endl ;
    }
    return 0 ;
}