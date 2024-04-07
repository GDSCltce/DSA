#include <iostream>
using namespace std;

struct NodeC
{
    int data;
    NodeC *next;

    NodeC(int x)
    {
        data = x;
        next = NULL;
    }
};

int printList(NodeC *head)
{
    int cnt = 0;
    NodeC *curr = head;
    if (head)
    {
        do
        {
            ++cnt;
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
    return cnt;
}

void pushHead(NodeC **head, int x)
{
    NodeC *new_node = new NodeC(x);
    if (*head == NULL)
    {
        new_node->next = new_node;
        *head = new_node;
    }
    else
    {
        new_node->next = (*head)->next;
        (*head)->next = new_node;
        swap((*head)->data, new_node->data);
    }
}

void pushTail(NodeC **head, int x)
{
    NodeC *new_node = new NodeC(x);
    if (*head == NULL)
    {
        new_node->next = new_node;
    }
    else
    {
        new_node->next = (*head)->next;
        (*head)->next = new_node;
        swap((*head)->data, new_node->data);
    }
    *head = new_node;
}

void popHead(NodeC **head)
{
    NodeC *temp = *head;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        delete temp;
        *head = NULL;
        return;
    }
    else
    {
        swap((*head)->data, (*head)->next->data);
        temp = (*head)->next;
        (*head)->next = temp->next;
        delete temp;
        return;
    }
}

void popTail(NodeC **head)
{
    NodeC *curr = *head;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->next == *head)
    {
        delete curr;
        *head = NULL;
        return;
    }
    else
    {
        while (curr->next->next != *head)
        {
            curr = curr->next;
        }
        NodeC *temp = curr->next;
        curr->next = *head;
        delete temp;
    }
}

void pushKth(NodeC **head, int x, int k)
{
    if (k == 0)
        return;
    if (*head == NULL || k == 1)
    {
        return pushHead(&*head, x);
    }
    else
    {
        NodeC *curr = *head;
        NodeC *new_node = new NodeC(x);
        for (int i = 0; i < k - 2; i++)
        {
            if (i && curr->next == *head)
            {
                cout << "Error k" << endl;
                return;
            }
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void popKth(NodeC **head, int k)
{
    if (*head == NULL)
    {
        return;
    }
    else if (k == 1)
    {
        return popHead(&*head);
    }
    else
    {
        NodeC *curr = *head;
        for (int i = 0; i < k - 2; i++)
        {
            if (i && curr->next->next == *head)
            {
                cout << "Error k" << endl;
                return;
            }
            curr = curr->next;
        }
        NodeC *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

void solve()
{
    // NodeC *head = new NodeC(1);
    // NodeC *second = new NodeC(2);
    // NodeC *third = new NodeC(3);
    // head->next = second;
    // second->next = third;
    // third->next = head;

    NodeC *head = NULL;
    printList(head);
    int n = 5; // No. of Nodes
    // cin >> n;
    for (int i = 1; i <= n; i++)
    {
        pushTail(&head, i); // Creating a Linked List of 1 2 3 4 5 ..... i
    }
    printList(head);

    pushKth(&head, 82763, 4);
    printList(head);
    // popKth(&head, 1);
    printList(head);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    solve();

    return 0;
}
