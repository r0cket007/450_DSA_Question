/*
    Rotate Doubly linked list by N nodes
    Link: https://www.geeksforgeeks.org/rotate-doubly-linked-list-n-nodes/
*/
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void push(Node  **head, int data)
{
    if(*head == NULL)
    {
        *head = new Node(data);
    }
    else
    {
        Node *temp = new Node(data);
        temp->next = (*head);
        (*head)->prev = temp;
        (*head)= temp;
    }
}
void print(Node *head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next; 
    }
    cout << endl;
}
//-----------------------------------------------------------------------------------
class Solution
{
 public:    
    Node* rotate(Node *head, int N)
    {
        Node *current = head, *prev = NULL;
        while(current != NULL && N)
        {
            N--;
            prev = current;
            current = current->next;
        }
        if(current == NULL)
            return head;
        current->prev = NULL;
        prev->next = NULL;
        Node *final = current;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = head;
        head->prev = current;
        return(final);
    }
};
//-----------------------------------------------------------------------------------
int main()
{
    Solution obj;
    Node *head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    print(head);
    head = obj.rotate(head, 6);
    print(head);
    return 0;
}