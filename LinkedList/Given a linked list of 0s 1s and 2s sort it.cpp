/*
    Given a linked list of 0s, 1s and 2s, sort it.
    Link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#
*/
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
struct Node *start = NULL;
//-----------------------------------------------------------------------------------
class Solution
{
public:
    Node *segregate(Node *head)
    {
        int cnt[3] = {};
        for (Node *i = head; i != 0; i = i->next)
            cnt[i->data]++;
        Node *x = head;
        for (int i = 0; i < 3; i++)
        {
            while (cnt[i]--)
            {
                x->data = i;
                x = x->next;
            }
        }
        return head;
    }
};
//--------------------------------------------------------------------------------------
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void insert(int n1)
{
    int n, value, i;
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        if (i == 0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}
int main()
{

    int n;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }
    return 0;
}