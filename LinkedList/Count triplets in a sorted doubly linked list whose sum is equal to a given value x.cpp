/*
    Count triplets in a sorted doubly linked list whose sum is equal to a given value x
    Link: https://www.geeksforgeeks.org/count-triplets-sorted-doubly-linked-list-whose-sum-equal-given-value-x/
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next, *prev;
};
//-------------------------------------------------------------------------------
int countTriplets(struct Node *head, int x)
{
    int ans = 0;
    Node *front = head;
    while (front->next != NULL)
    {
        front = front->next;
    }
    Node *back = front;
    front = head;
    while(front->next != NULL)
    {
        int rem_sum = x - front->data;       
        Node *start = front->next, *end = back;
        while(start->data < end->data)
        {
            if(start->data + end->data == rem_sum)
            {
                ans ++;
                start = start->next;
                back = back->prev;
            }
            else if(start->data + end->data > rem_sum)
            {
                end = end->prev;
            }
            else
            {
                start = start->next;
            }
        }
        front = front->next;
    }
    return ans;
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
    int x = 17;
    cout << "Count = " << countTriplets(head, x);
    return 0;
}
