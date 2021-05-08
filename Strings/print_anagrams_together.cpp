/*
    Print Anagrams Together
    Link: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#

    Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
    Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.

    Constraints:
    1<=N<=100
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//-------------------------------------------------------------------------
vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    map<string, vector<string>> mp;
    int n = string_list.size();
    for(int i = 0; i < n; i++)
    {
        string temp = string_list[i];
        sort(temp.begin(), temp.end());
        mp[temp].push_back(string_list[i]);
    }
    vector<vector<string>> ans;
    for(auto i :mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}
//-------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        vector<string> words = {"act","god","cat","dog","tac"};
        vector<vector<string>> ans = Anagrams(words);
        for(int i = 0; i < ans.size(); i++)
        {
            for(int j = 0; j < ans[i].size(); j ++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl ;
    }
    return 0 ;
}   
