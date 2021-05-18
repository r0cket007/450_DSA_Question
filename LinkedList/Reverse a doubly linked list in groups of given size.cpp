/*
    Reverse a doubly linked list in groups of given size
    Link: https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
};
Node *getNode(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}
void push(Node **head_ref, Node *new_node)
{
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
//------------------------------------------------------------------------------
Node *revListInGroupOfGivenSize(Node *head, int k)
{
    Node *current = head;
    Node *prev = NULL;
    while(current != NULL and k)
    {
        k--;
        Node *temp = current->next;
        current->next = prev;
        current->prev = temp;
        prev = current;
        current = temp; 
    }   
    if(current == NULL)
        return prev;
    else
    {
        head->next = current;
        current->prev = head;
        prev->prev = NULL;
    }
    return prev;
}
//------------------------------------------------------------------------------
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
    int k = 3;
    cout << "Original list: ";
    printList(head);
    head = revListInGroupOfGivenSize(head, k);
    cout << "\nModified list: ";
    printList(head);
    return 0;
}