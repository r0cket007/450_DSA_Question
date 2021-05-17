/*
    Segregate even and odd nodes in a Link List
    Link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
//---------------------------------------------------------------------------------------------
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *current = head;
        while (current != NULL)
        {
            Node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    Node *divide(int N, Node *head)
    {
        Node *create = NULL;
        Node *current = head;
        while (current != NULL)
        {
            if (current->data % 2 == 0)
            {
                Node *temp = new Node(current->data);
                temp->next = create;
                create = temp;
            }
            current = current->next;
        }
        current = head;
        while (current != NULL)
        {
            if (current->data % 2 == 1)
            {
                Node *temp = new Node(current->data);
                temp->next = create;
                create = temp;
            }
            current = current->next;
        }
        return create = reverse(create);
    }
};
//---------------------------------------------------------------------------------------------
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}