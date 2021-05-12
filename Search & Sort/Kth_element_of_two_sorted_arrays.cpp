/*
    K-th element of two sorted Arrays
    Link: https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int arr3[n + m];
        merge(arr1, arr1 + n, arr2, arr2 + m, arr3);
        return arr3[k - 1];
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1;
    // cin >> testcases ;
    while (testcases--)
    {
        int arr1[] = {100, 112, 256, 349, 770}, arr2[] = {72, 86, 113, 119, 265, 445, 892};
        int k = 7, n = 5, m = 7;
        Solution obj;
        cout << obj.kthElement(arr1, arr2, n, m, k);
        cout << endl;
    }
    return 0;
}