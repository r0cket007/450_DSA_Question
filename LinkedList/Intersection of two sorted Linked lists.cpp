/*
    Intersection of two sorted Linked lists
    Link: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
Node *inputList(int size)
{
    Node *head, *tail;
    int val;

    cin >> val;
    head = tail = new Node(val);

    while (--size)
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
}

Node *findIntersection(Node *head1, Node *head2);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        Node *head1 = inputList(n);
        Node *head2 = inputList(m);

        Node *result = findIntersection(head1, head2);

        printList(result);
        cout << endl;
    }
    return 0;
}
//-------------------------------------------------------------------------------------------
Node *reverse(Node *dummy)
{
    if (dummy->next == NULL)
    {
        return dummy;
    }
    Node *rest = reverse(dummy->next);
    dummy->next->next = dummy;
    dummy->next = NULL;
    return rest;
}
Node *findIntersection(Node *head1, Node *head2)
{
    unordered_set<int> s;
    Node *current1 = head1;
    Node *current2 = head2;
    Node *result = NULL;
    while (current1 != NULL && current2 != NULL)
    {
        if (current1->data == current2->data)
        {
            Node *temp = new Node(current1->data);
            temp->next = result;
            result = temp;
            current1 = current1->next;
            current2 = current2->next;
        }
        else if (current1->data > current2->data)
        {
            current2 = current2->next;
        }
        else
            current1 = current1->next;
    }
    result = reverse(result);
    return result;
}
//-------------------------------------------------------------------------------------------