/*
    Longest Common Prefix
    Link: https://leetcode.com/problems/longest-common-prefix/
    
    Constraints
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
struct TrieNode 
{
    TrieNode(char symbol) 
    {
        c = symbol;
    }
    char c='\0';
    bool endPoint=false;
    unordered_map<char, TrieNode *> child;
};
//------------------------------------------------------
class Trie 
{
    public:
    Trie( const vector<string> &words) 
    {
        root = new TrieNode('\0');
        for(auto &s:words)
            insert(s);
    }
    
    void insert(const string &s) 
    {

        TrieNode *p = root;
        for(auto &c:s) {
            if(p->child.find(c) == p->child.end())
                p->child[c] = new TrieNode(c);
            p = p->child[c];
        }
        p->endPoint = true;
    }
    
    string findLongestCommonPrefix() 
    {
        TrieNode *p = root;
        string prefix{""};
        
        if(p->child.size() != 1 || p->endPoint )
            return "";
			
        p = (p->child.begin())->second; 
        while(p->child.size() == 1 && !p->endPoint ){
            prefix.push_back(p->c);
            p = (p->child.begin())->second;
        }
        prefix.push_back(p->c);
        return prefix;
    }
    private:
    TrieNode *root;
};

//--------------------------------------------------------
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie(strs);
        return trie.findLongestCommonPrefix();
    }
};
//--------------------------------------------------------------------------------------
signed main( )
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        int n ;
        // cin >> n ;
        Solution obj;
        vector<string> v = {"flower","flow","flight"};
        cout << obj.longestCommonPrefix(v);
        cout << endl ;
    }
    return 0 ;
}