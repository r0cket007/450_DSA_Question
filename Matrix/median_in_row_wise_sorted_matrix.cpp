/*
	Median in a row-wise sorted Matrix
	LINK: https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

	Expected Time Complexity: O(32 * R * log(C))
	Expected Auxiliary Space: O(1)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
int median(vector<vector<int>> &matrix, int r, int c)
{
    int mn = INT_MAX ;
    int mx = INT_MIN ;
    int target = ( r * c + 1 ) / 2 ;
    
    for( int i = 0 ; i < r ; i ++ )
    {
        mn = min(mn, matrix[i][0]);
        mx = max(mx, matrix[i][c-1]);
    }
    
    
    while( mn < mx )
    {
        int count = 0 ;
        int mid = mn + ( mx - mn ) / 2 ;
        for( int i = 0; i < r; i ++ )
        {
            count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if( count >= target )
        {
            mx = mid ;
        }
        else 
        {
            mn = mid + 1 ;
        }
    }
    
    return mn ;
    
}
signed main( )
{
	#ifndef ONLINE_JUDGE
    r0cket007
    #endif
	int testcases = 1 ;
	// cin >> testcases ;
	while( testcases -- )
	{
		int r , c ;
		cin >> r >> c ;
		std::vector<vector<int>> v( r , std::vector<int>( c , 0 ) );
		for(int i = 0; i < r; i ++)
		{
			for(int j = 0; j < c; j ++)
			{
				cin >> v[i][j] ;
			}
		}
		cout << median(v, r, c) ;
		cout << endl ;
	}
	return 0 ;
}