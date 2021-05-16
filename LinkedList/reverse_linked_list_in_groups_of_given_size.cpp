/*
    Reverse a Linked List in groups of given size
    Link: https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1#
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
    int val;
    node *next;
    node(int val)
    {
        this->val = val;
        next = NULL;
    }
};
class LinkedList
{
    node *head;

public:
    LinkedList()
    {
        head = NULL;
    }
    void push(int val)
    {
        node *temp = new node(val);
        temp->next = head;
        head = temp;
    }
    void print()
    {
        node *current = head;
        while (current != NULL)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
    //----------------------------------------------------------------------------
    node *reverse(node *head, int k)
    {
        if (head == NULL)
            return NULL;
        int counter = k;
        node *current = head, *prev = NULL;
        while (counter && current != NULL)
        {
            node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            counter--;
        }
        head->next = reverse(current, k);
        return prev;
    }
    //----------------------------------------------------------------------------
    void reverse_in_group(int k)
    {
        head = reverse(head, k);
    }
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
        obj.push(5);
        obj.push(4);
        obj.push(2);
        obj.push(2);
        obj.push(1);
        obj.print();
        obj.reverse_in_group(4);
        obj.print();
        cout << endl;
    }
    return 0;
}