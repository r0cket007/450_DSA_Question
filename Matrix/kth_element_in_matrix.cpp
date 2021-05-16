/*
    Kth element in Matrix 
    LINK : https://practice.geeksforgeeks.org/problems/kth-element-in-matrix/1#

    Expected Time Complexity: O(N*Log(N))
    Expected Auxiliary Space: O(N)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
const int MAX = 500; 

//-----------------------------------------------------------------------------------
#define pii pair<int,pair<int,int>>

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for(int i = 0; i < n; i ++)
    {
        q.push({mat[0][i], {0, i}});
    }
    for(int i = 1; i < k; i ++ )
    {
        pii it = q.top();
        q.pop();
        int row = it.second.first;
        int col = it.second.second;
        int val = it.first ;
        val = ( row + 1 == n ? INT_MAX : mat[row+1][col]) ;
        row ++ ;
        q.push({val, {row, col}}) ;
    }
    pii it = q.top();
    return it.first;
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
        int n = 4 ;
        int mat[MAX][MAX] = {{16, 28, 60, 64},
                            {22, 41, 63, 91},
                            {27, 50, 87, 93},
                            {36, 78, 87, 94 }};
        int k = 3 ;

        cout << kthSmallest(mat, n, k);
    }
    return 0 ;
}