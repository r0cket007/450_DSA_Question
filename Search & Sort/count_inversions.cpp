/*
    Count Inversions
    Link: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/
#include <bits/stdc++.h>
using namespace std;
//---------------------------------------------------------------------------------
class Solution
{
public: 
    long long merge(long long arr[], int l, int mid, int r)
    {
        long long temp[r - l + 1];
        int i = l;
        int j = mid + 1;
        int counter = 0;
        long long ans = 0;
        while (i <= mid && j <= r)
        {
            if (arr[i] <= arr[j])
            {
                temp[counter] = arr[i++];
            }
            else
            {
                temp[counter] = arr[j++];
                ans += ((mid + 1) - i);
            }
            counter++;
        }
        while (i <= mid)
        {
            temp[counter++] = arr[i++];
        }
        while (j <= r)
        {
            temp[counter++] = arr[j++];
        }
        for (int k = 0; k < counter; k++)
        {
            arr[k + l] = temp[k];
        }
        return ans;
    }
    long long mergesort(long long arr[], int l, int r)
    {
        if (l >= r)
            return 0;
        int mid = l + (r - l) / 2;
        long long res = 0;
        res += mergesort(arr, l, mid);
        res += mergesort(arr, mid + 1, r);
        res += merge(arr, l, mid, r);
        return res;
    }
    long long inversionCount(long long arr[], long long N)
    {
        return mergesort(arr, 0, N - 1);
    }
};
//---------------------------------------------------------------------------------
int main()
{
    long long T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;
        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A, N) << endl;
    }
    return 0;
}