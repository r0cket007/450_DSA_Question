/*
    Find pairs with given sum in doubly linked list
    Link: https://www.geeksforgeeks.org/find-pairs-given-sum-doubly-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next, *prev;
};
//-------------------------------------------------------------------------------
void pairSum(Node *head, int x)
{
    int ans = 0;
    Node *start = head;
    while (start->next != NULL)
    {
        start = start->next;
    }
    Node *back = start;
    start = head;
    Node *end = back;
    while(start->data < end->data)
    {
        if (start->data + end->data == x)
        {
            cout << start->data << " " << end->data << endl;
            start = start->next;
            back = back->prev;
        }
        else if(start->data + end->data > x)
        {
            end = end->prev;
        }
        else
        {
            start = start->next;
        }
    }
}
//------------------------------------------------------------------------------
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node();
    temp->data = data;
    temp->next = temp->prev = NULL;

    if ((*head) == NULL)
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;
    pairSum(head, 7);
    return 0;
}
