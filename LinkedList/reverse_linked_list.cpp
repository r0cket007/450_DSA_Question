/*
    Reverse a linked list
    Link: https://www.geeksforgeeks.org/reverse-a-linked-list/
*/
#include<bits/stdc++.h>
#define int long long
using namespace std ;
//--------------------------------------------------------------------
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
        while(current != NULL)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
    void reverse_iterative()
    {
        node *current, *prev, *current_next;
        prev = NULL;
        current = head;
        while(current != NULL)
        {
            node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        head = prev;
    }
    node *reverse_recursive(node *current)
    {
        if(current == NULL || current->next == NULL)
        {
            return current;
        }
        node *rest = reverse_recursive(current->next);
        current->next->next = current;
        current->next = NULL;
        return rest;
    }
    void reverse_recursive()
    {
        head = reverse_recursive(head);
    }
};
//--------------------------------------------------------------------
signed main()
{
    int testcases = 1 ;
    // cin >> testcases ;
    while( testcases -- )
    {
        LinkedList obj;
        obj.push(1);
        obj.push(2);
        obj.push(3);
        obj.push(4);
        obj.push(5);
        obj.push(6);
        obj.print();
        obj.reverse_iterative();
        obj.print();
        obj.reverse_recursive();
        obj.print();
        cout << endl ;
    }
    return 0 ;
}