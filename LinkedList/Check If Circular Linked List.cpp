/*
    Check If Circular Linked List 
    Link: https://practice.geeksforgeeks.org/problems/circular-linked-list/1#
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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
bool isCircular(struct Node *head);
int main()
{
    int T, i, n, l, k;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        Node *head = NULL, *tail = NULL;
        int x;
        cin >> x;
        head = new Node(x);
        tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        if (k == 1 && n >= 1)
            tail->next = head;
        printf("%d\n", isCircular(head));
    }
    return 0;
}
//-----------------------------------------------------------------------------------
bool isCircular(Node *head)
{
    Node *current = head->next;
    while (current != NULL)
    {
        if (current == head)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}
//-------------------------------------------------------------------------------------