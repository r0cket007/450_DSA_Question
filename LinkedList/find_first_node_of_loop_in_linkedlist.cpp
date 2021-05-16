/*
    Find first node of loop in a linked list
    Link: https://www.geeksforgeeks.org/find-first-node-of-loop-in-a-linked-list/
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
    int startPoint()
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
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast->val;
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
        cout << obj.startPoint();
        cout << endl;
    }
    return 0;
}