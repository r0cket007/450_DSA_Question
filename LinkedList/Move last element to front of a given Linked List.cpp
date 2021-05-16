/*
    Remove duplicate element from unsorted Linked List
    Link: https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1#
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void push(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
    }
    void print()
    {
        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    //---------------------------------------------------------------------------------
    void moveToFront()
    {
        if (head == NULL || (head)->next == NULL)
            return;
        Node *secLast = NULL;
        Node *last = head;
        while (last->next != NULL)
        {
            secLast = last;
            last = last->next;
        }
        secLast->next = NULL;
        last->next = head;
        head = last;
    }
    //----------------------------------------------------------------------------------
};
signed main()
{
    int testcases = 1;
    // cin >> testcases ;
    while (testcases--)
    {
        LinkedList obj;
        obj.push(8);
        obj.push(7);
        obj.push(6);
        obj.push(6);
        obj.print();
        obj.moveToFront();
        obj.print();
        cout << endl;
    }
    return 0;
}