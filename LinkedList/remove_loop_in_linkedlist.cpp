/*
    Remove loop in Linked List
    Link: https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node
{
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
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
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }
    void loopHere(int position)
    {
        if (position == 0)
            return;

        Node *walk = head, *tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        for (int i = 1; i < position; i++)
            walk = walk->next;
        tail->next = walk;
    }
    //---------------------------------------------------------------------------------
    void removeLoop()
    {
        Node *fast = head;
        Node *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (fast->next == NULL || fast->next->next == NULL)
            return;
        slow = head;
        Node *prev = fast;
        while (prev->next != fast)
        {
            prev = prev->next;
        }
        while (slow != fast)
        {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }
        prev->next = NULL;
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
        obj.loopHere(0);
        obj.removeLoop();
        cout << endl;
    }
    return 0;
}