/*
    Find the string in grid
    Link: https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1#
    
    Expected Time Complexity: O(n*m*k) where k is constant
    Exected Space Complexity: O(1)
    
    Constraints:
    1 <= n <= m <= 100
    1 <= |word| <= 10 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//---------------------------------------------------------------------------
int x[8] = {0, 0, 1, 1, -1, -1, 1, -1};
int y[8] = {1, -1, 0, 1, 0, -1, -1, 1};
bool check(int row, int col, int n, int m)
{
    return ( n > row && m > col && row >= 0 && col >= 0);
}
bool bruteforce(string txt, int pos, vector<vector<char>> &arr, int row, int col, int n, int m)
{
    if( arr[row][col] != txt[pos] )
    {
        return false;
    }
    if(pos == txt.length() - 1 && arr[row][col] == txt[pos])
    {
        return true;
    }
    pos ++ ;
    for(int i = 0; i < 8; i ++)
    {
        int temp = pos;
        int temp_row = row + x[i];
        int temp_col = col + y[i];
        while(check(temp_row, temp_col, n, m))
        {
            if( temp == txt.length( ) - 1 && txt[temp] == arr[temp_row][temp_col])
                return true;
            if( txt[temp] != arr[temp_row][temp_col] )
                break;
            temp ++ ;
            temp_row += x[i];
            temp_col += y[i];
        }
    }
    return false;
}
vector<vector<int>>searchWord(vector<vector<char>>grid, string word)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            if(bruteforce( word, 0, grid, i, j, n, m))
                ans.push_back({i, j});              
        }
    }
    return ans;
}
//---------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        vector<vector<char>>grid = {{'a','b','a','b'},{'a','b','e','b'},{'e','b','e','b'}};
        string word = "abe";
        vector<vector<int>> ans = searchWord(grid, word);
        for(auto i : ans)
        {
            for(auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl ;
    }
    return 0 ;
}