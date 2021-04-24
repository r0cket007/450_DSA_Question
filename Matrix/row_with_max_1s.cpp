/*
	Row with max 1s 
	LINK : https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#

    Expected Time Complexity: O(N+M)
    Expected Auxiliary Space: O(1)
*/
#include<bits/stdc++.h>
#define int long long
#define in  freopen("input.txt","r",stdin);
#define out freopen("output.txt","w",stdout);
#define r0cket007 in out 
using namespace std ;
int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
{
    int result = -1 ;
    int j = m - 1 ;
    for(int i = 0; i < n; i ++)
    {
        while( j != -1 )
        {
            if(arr[i][j] == 1)
            {
                result = i ;
            }
            else break ;
            j -- ;
        }
    }
    return result ;
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
        int n , m ;
        cin >> n >> m ;
		vector<vector<int>> matrix(n, std::vector<int>(m, 0));
        for (int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; j ++)
            {
                cin >> matrix[i][j];
            }
        }
        cout << rowWithMax1s(matrix, n, m);
		cout << endl ;
	}
	return 0 ;
}