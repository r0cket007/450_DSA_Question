/*
    Add 1 to a number represented as linked list  
    Link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1#
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
    Node *reverse(Node * dummy)
    {
        if (dummy->next == NULL)
            return dummy;
        Node *rest = reverse(dummy->next);
        dummy->next->next = dummy;
        dummy->next = NULL;
        return rest;
    }
    void addOne()
    {
        Node *current = reverse(head);
        int carry = 0;
        if (current->data + 1 > 9)
        {
            carry = 1;
            current->data = 0;
        }
        else
            current->data += 1;
        head = current;
        Node *prev = current;
        current = current->next;
        while (carry != 0 && current != NULL)
        {
            if (current->data + carry <= 9)
            {
                carry = 0;
                current->data += 1;
                break;
            }
            else
            {
                current->data = 0;
            }
            prev = current;
            current = current->next;
        }
        if (carry == 1)
        {
            Node *temp = new Node(1);
            prev->next = temp;
        }
        head = reverse(head);
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
        // Numbers are push in front
        obj.push(9);
        obj.push(9);
        obj.push(9);
        obj.push(8);
        obj.addOne();
        obj.print();
        cout << endl;
    }
    return 0;
}