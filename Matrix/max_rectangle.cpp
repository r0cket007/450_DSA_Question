/*
    Max rectangle
    LINK : https://practice.geeksforgeeks.org/problems/max-rectangle/1#

    Expected Time Complexity : O(n*m)
    Expected Auixiliary Space : O(m)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 
//------------------------------------------------------------------------------
int histogram_area( int arr[] , int n )
{
    int max_area = 0;
    stack<int> st;
    for(int i = 0; i < n; i ++)
    {
        if(st.empty() || arr[st.top()] <= arr[i])
        {
            st.push(i);
        }
        else
        {
            while((!st.empty()) && (arr[st.top()] > arr[i]))
            {
                int pos = st.top();
                st.pop();
                int temp_area = arr[pos] * (st.empty() ? i : i - st.top() - 1);
                max_area = max(max_area, temp_area);
            }
            st.push(i);
        }
    }   
    while(st.empty() == false)
    {
        int pos = st.top();
        st.pop();
        int temp_area = arr[pos] * (st.empty() ? n : n - st.top() - 1);
        max_area = max(max_area, temp_area);
    }
    return max_area ;
}
//-----------------------------------------------------------------------------------
int maxArea(int M[MAX][MAX], int n, int m) 
{
    int arr[m] = {0} ;
    int max_area = 0 ;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            arr[j] = (M[i][j] == 0 ? 0 : arr[j] + M[i][j]);
        }
        int temp_area = histogram_area(arr, m);
        max_area = max(max_area, temp_area);
    }
    return max_area;
}
//-------------------------------------------------------------------------------------
signed main( )
{
    #ifndef ONLINE_JUDGE
    r0cket007
    #endif
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n, m;
        cin >> n >> m;
        int matrix[n][m];
        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; j ++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << maxArea ;
        cout << endl ;
    }
    return 0 ;
}