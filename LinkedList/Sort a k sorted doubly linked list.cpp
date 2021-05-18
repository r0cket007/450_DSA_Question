/*
    Sort a k sorted doubly linked list
    Link: https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data  = data;
        next = NULL;
        prev = NULL;
    }
};
struct Node *sortAKSortedDLL(struct Node *head, int k)
{
    if (head == NULL)
        return head;
    priority_queue<int,vector<int>, greater<int>> pq;
    struct Node *newHead = NULL, *last;
    while(head != NULL && k != -1) 
    {
        pq.push(head->data);
        head = head->next;
        k --;
    } 
    Node *ans;
    while (!pq.empty())
    {
        if (newHead == NULL)
        {
            newHead = new Node(pq.top());
            ans = newHead;
        }
        else
        {
            Node *temp = new Node(pq.top());
            temp->prev = newHead;
            newHead->next = temp;
            newHead = temp;
        }
        pq.pop();
        if (head != NULL)
        {
            pq.push(head->data);
            head = head->next;
        }
    }
    return ans;
}
void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    (*head_ref) = new_node;
}
void printList(struct Node *head)
{
    if (head == NULL)
        cout << "Doubly Linked list empty";

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
int main()
{
    struct Node *head = NULL;
    push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
    int k = 2;
    cout << "Original Doubly linked list:\n";
    printList(head);
    head = sortAKSortedDLL(head, k);
    cout << "\nDoubly linked list after sorting:\n";
    printList(head);

    return 0;
}
