/*
    Merge Sort for Linked List
    Link: https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
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
//-----------------------------------------------------------------------------------------
class Solution
{
public:

    Node *merge(Node *current1, Node *current2)
    {
        if (current1 == NULL)
            return current2;
        if (current2 == NULL)
            return current1;

        if (current1->data < current2->data)
        {
            current1->next = merge(current1->next, current2);
            return current1;
        }
        else
        {
            current2->next = merge(current1, current2->next);
            return current2;
        }
    }
    Node *mergeSort(Node *head)
    {
        //Your Code goes here
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        Node *slow = head;
        Node *fast = head->next;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node *head1 = slow->next;
        slow->next = NULL;
        return merge(mergeSort(head), mergeSort(head1));
    }
};
//-----------------------------------------------------------------------------------------

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}