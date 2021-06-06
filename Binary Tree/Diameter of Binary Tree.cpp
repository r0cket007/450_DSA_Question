/*
    Diameter of Binary Tree
    Link: https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
//------------------------------------------------------------------------------------------
class Solution
{
public:
    int height(Node *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int left = height(root->left, ans);
        int right = height(root->right, ans);
        int h = 1 + left + right;
        ans = max(ans, h);
        return 1 + max(left, right);
    }
    int diameter(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans = 0;
        height(root, ans);
        return ans;
    }
};
//------------------------------------------------------------------------------------------
int main()
{
    int t;
    scanf("%d\n", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}