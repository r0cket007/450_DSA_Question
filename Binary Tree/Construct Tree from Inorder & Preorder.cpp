//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

//----------------------------------------------------------------------------
class Solution{
    int idx = 0;
    public:
    Node* build(int in[], int pre[], int l , int r){
        if(l > r){
            return NULL;
        }
        
        Node *root = new Node(pre[idx++]);
        int i = l;
        while(i < r ){
            
            if(root->data == in[i]){
                break;
            }
            i ++;
        }
        
        root->left = build(in, pre, l, i - 1);
        root->right = build(in, pre, i + 1, r);
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        idx = 0;
        return build(in, pre, 0 , n - 1);  
    }
};
//----------------------------------------------------------------------------
// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends