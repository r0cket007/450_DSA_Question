/*
    Detect Loop in linked list 
    Link: https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
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
    void loopHere(int position)
    {
        if (position == 0)
            return;

        node *walk = head, *tail = head;
        while(tail->next != NULL)
            tail = tail->next;
        for (int i = 1; i < position; i++)
            walk = walk->next;
        tail->next = walk;
    }
    //---------------------------------------------------------------------------------
    bool detectLoop(node *head)
    {
        node *fast = head;
        node *slow = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
    //----------------------------------------------------------------------------------
    bool detect()
    {
        return detectLoop(head);
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
        obj.loopHere(0);
        cout << obj.detect();
        cout << endl;
    }
    return 0;
}