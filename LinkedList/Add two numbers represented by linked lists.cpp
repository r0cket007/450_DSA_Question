/*
    Add two numbers represented by linked lists  
    Link: https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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
struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}
void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
//----------------------------------------------------------------------------------------------
class Solution
{
public:
    Node *reverse(Node *dummy)
    {
        if (dummy->next == NULL)
            return dummy;

        Node *rest = reverse(dummy->next);
        dummy->next->next = dummy;
        dummy->next = NULL;
        return rest;
    }
    struct Node *addTwoLists(struct Node *first, struct Node *second)
    {
        Node *current1 = reverse(first);
        Node *current2 = reverse(second);

        Node *result = NULL;
        int carry = 0;
        while (current1 != NULL && current2 != NULL)
        {
            int x = current1->data + current2->data + carry;
            Node *temp = new Node(x % 10);
            carry = x / 10;
            temp->next = result;
            result = temp;
            current1 = current1->next;
            current2 = current2->next;
        }
        while (current1 != NULL)
        {
            int x = current1->data + carry;
            Node *temp = new Node(x % 10);
            carry = x / 10;
            temp->next = result;
            result = temp;
            current1 = current1->next;
        }
        while (current2 != NULL)
        {
            int x = current2->data + carry;
            Node *temp = new Node(x % 10);
            carry = x / 10;
            temp->next = result;
            result = temp;
            current2 = current2->next;
        }
        if (carry)
        {
            Node *temp = new Node(carry);
            temp->next = result;
            result = temp;
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);
        Solution ob;
        Node *res = ob.addTwoLists(first, second);
        printList(res);
    }
    return 0;
}