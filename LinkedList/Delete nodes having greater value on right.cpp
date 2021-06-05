/*
    Delete nodes having greater value on right 
    Link: https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
//----------------------------------------------------------------------------------------
class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    Node *compute(Node *head)
    {
        head = reverse(head);
        Node *dummy = head;
        while (dummy != NULL and dummy->next != NULL)
        {
            if (dummy->next->data < dummy->data)
            {
                Node *temp = dummy->next;
                dummy->next = temp->next;
                delete temp;
                continue;
            }
            dummy = dummy->next;
        }
        return reverse(head);
    }
};
//----------------------------------------------------------------------------------------
int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout << endl;
    }
}