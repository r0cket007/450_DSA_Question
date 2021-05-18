/*
    Merge K sorted linked lists 
    Link: https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}
//---------------------------------------------------------------------------------------
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        while (head != NULL)
        {
            Node *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    Node *mergeKLists(Node *arr[], int k)
    {
        Node *current[k];
        Node *head;
        for (int i = 0; i < k; i++)
        {
            current[i] = arr[i];
        }
        while (1)
        {
            int data = INT_MAX;
            int pos = -1;
            for (int i = 0; i < k; i++)
            {
                if (current[i] != NULL && data > current[i]->data)
                {
                    data = current[i]->data;
                    pos = i;
                }
            }
            if (pos == -1)
                break;
            else
            {
                Node *temp = new Node(current[pos]->data);
                temp->next = head;
                head = temp;
                current[pos] = current[pos]->next;
            }
        }
        return head = reverse(head);
    }
};
//---------------------------------------------------------------------------------------
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        struct Node *arr[N];
        for (int j = 0; j < N; j++)
        {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node *curr = arr[j];
            n--;

            for (int i = 0; i < n; i++)
            {
                cin >> x;
                Node *temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr, N);
        printList(res);
    }

    return 0;
}