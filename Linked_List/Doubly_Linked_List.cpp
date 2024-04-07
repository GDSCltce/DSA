#include <iostream>
using namespace std;

struct NodeD
{
    int data;
    NodeD *prev;
    NodeD *next;
    NodeD(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

void printlist(NodeD *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void printlist_rev(NodeD *tail)
{
    while (tail)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

NodeD *getTail(NodeD *head)
{
    NodeD *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }
    return curr;
}

void insertBegD(NodeD **head, int x)
{
    NodeD *temp = new NodeD(x);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    temp->next = *head;
    if (head)
        (*head)->prev = temp;

    *head = temp;
}

void insertEnd(NodeD **tail, int x)
{
    NodeD *temp = new NodeD(x);
    if (*tail == NULL)
        *tail = temp;

    (*tail)->next = temp;
    temp->prev = *tail;

    *tail = temp;
}

void reverseDLL(NodeD **head)
{
    NodeD *prev = NULL;
    NodeD *curr = *head;
    if (curr == NULL || curr->next == NULL)
        return;

    while (curr)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    *head = prev->prev;
}

void CreateDoublyLinkedList(NodeD **head, int n)
{
    int x;
    NodeD *tail = *head;
    while (n--)
    {
        cin >> x;
        // insertEnd(&tail, x);
        NodeD *temp = new NodeD(x);
        if (tail == NULL){
            tail = temp;
            *head = temp;
            continue;
        }

        tail->next = temp;
        temp->prev = tail;

        tail = temp;
    }
}

inline void solve()
{
    // NodeD *head = new NodeD(2);
    // NodeD *second = new NodeD(3);
    // NodeD *third = new NodeD(4);
    // head->next = second;
    // second->prev = head;
    // second->next = third;
    // third->prev = second;

    int n;
    cin >> n;
    NodeD *head = NULL;
    // int x;
    // cin >> x;
    // insertBegD(&head, x);
    // NodeD *tail = head;

    // while (--n)
    // {
    //     cin >> x;
    //     insertEnd(&tail, x);
    // }
    CreateDoublyLinkedList(&head, n);

    printlist(head);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif

    // int t;
    // scanf("%d", &t);
    // while (t--)
    {
        solve();
    }
    return 0;
}
