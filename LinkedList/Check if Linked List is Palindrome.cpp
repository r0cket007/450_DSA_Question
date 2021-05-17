/*
    Check if Linked List is Palindrome 
    Link: https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1#
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
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
//---------------------------------------------------------------------------------------------
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL, *current = head;
        while (current != NULL)
        {
            Node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL)
        {
            slow = slow->next;
        }
        fast = reverse(slow);
        slow = head;
        while (fast != NULL)
        {
            if (fast->data != slow->data)
            {
                return false;
            }
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
};
//---------------------------------------------------------------------------------------------
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        Solution obj;
        cout << obj.isPalindrome(head) << endl;
    }
    return 0;
}