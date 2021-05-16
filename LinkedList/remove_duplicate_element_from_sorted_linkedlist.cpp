/*
    Remove duplicate element from sorted Linked List
    Link: https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1#
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
    void *removeDuplicates()
    {
        Node *current = head;
        while (current != NULL && current->next != NULL)
        {
            if (current->data == (current->next)->data)
            {
                Node *temp = current->next;
                current->next = temp->next;
                free(temp);
                continue;
            }
            current = current->next;
        }
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
        obj.removeDuplicates();
        cout << endl;
    }
    return 0;
}