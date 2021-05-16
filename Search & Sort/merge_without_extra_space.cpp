/*
    Merge Without Extra Space
    Link: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        int counter1 = n - 1;
        int counter2 = 0;
        while (counter1 >= 0 && counter2 < m)
        {
            if (arr1[counter1] > arr2[counter2])
            {
                swap(arr1[counter1], arr2[counter2]);
                counter1--;
                counter2++;
            }
            else
            {
                break;
            }
        }
        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int N = 4, M = 5 ;
        int arr1[] = {1, 3, 5, 7};
        int arr2[] = {0, 2, 6, 8, 9};
        cout << endl;
    }
    return 0 ;
}