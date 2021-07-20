#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = new Node(stoi(ip[0]));
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
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
vector<int> zigZagTraversal(Node *root);

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
//---------------------------------------------------------------
vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    deque<int> dq;
    bool f = false;
    while (q.empty() == false)
    {
        int n = q.size();
        while (n--)
        {
            Node *temp = q.front();
            q.pop();
            dq.push_back(temp->data);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        while (dq.size())
        {
            if (f)
            {
                ans.push_back(dq.back());
                dq.pop_back();
            }
            else
            {
                ans.push_back(dq.front());
                dq.pop_front();
            }
        }
        f = !f;
    }
    return ans;
}
//--------------------------------------------------------------------------