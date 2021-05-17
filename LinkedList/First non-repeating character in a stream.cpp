/*
    First non-repeating character in a stream
    Link: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
*/
#include <bits/stdc++.h>
using namespace std;
//---------------------------------------------------------------------------------
class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        queue<char> q;
        int hash[26] = {0};
        string ans;
        for (int i = 0; i < A.length(); i++)
        {
            hash[A[i] - 'a']++;
            if (hash[A[i] - 'a'] == 1)
            {
                q.push(A[i]);
            }
            while(q.empty() == false && hash[q.front() - 'a'] > 1)
            {
                q.pop();
            }
            if (q.empty())
                ans += "#";
            else
                ans += q.front();
        }
        return ans;
    }
};
//---------------------------------------------------------------------------------
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";
    }
    return 0;