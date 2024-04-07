#ifndef SLL_h
#define SLL_H
#include <bits/stdc++.h>
using namespace std;

/* A Node of data integer with a constructor */
struct Node
{
    int data;   // Node
    Node *next; // Pointer

    Node(int x) // Constructor
    {
        data = x; // Asignning the data to the Node
        next = NULL;
    }
};

/* Function which takes head and print Linked List */
int printList(Node *head)
{

    int counter = 0; // counter to count the no. of nodes
    while (head)     // Traverse until the head becomes NULL
    {
        cout << head->data << " ";
        head = head->next; // update the pointer to next pointer
        counter++;         // counter update
    }
    cout << endl;
    return counter;
}

/* Insert Node at beginning  -  O(1) */
void pushFront(Node *&head, int x)
{
    Node *new_node = new Node(x);
    new_node->next = head;
    head = new_node;
}

/* Inserting at the end  -  O(n) */
void pushBack(Node *&head, int x)
{
    Node *temp = new Node(x); // Creating a new Node
    if (head == NULL)         // if head is NULL we will change the head with temp
    {
        head = temp;
    }
    else
    {
        Node *curr = head; // curr to traverse at the end of Linked List
        while (curr->next) // until curr is NULL, loop will run
        {
            curr = curr->next; // Update curr next to curr
        }
        curr->next = temp; // curr is now the end of Linked List so we will update it with temp
    }
}
/*  */
void pushSorted(Node **head, int x)
{
    Node *new_node = new Node(x);
    if (*head == NULL)
    {
        *head = new_node;
    }
    else if ((*head)->data > x)
    {
        new_node->next = *head;
        *head = new_node;
    }
    else
    {
        Node *curr = *head;
        while (curr->next && curr->next->data <= x)
        {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}
/* Find the middle element  -  O(n) */
Node getMid(Node *head)
{
    Node *fastPtr = head;
    Node *slowPtr = head;

    if (head != NULL)
    {
        while (fastPtr && fastPtr->next)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
    }
    return *slowPtr;
}
/* Delete the first Node  -  O(1) */
void popFront(Node *&head)
{
    if (head == NULL) // if head is null we will simply return null
    {
        return;
    }
    Node *temp = head->next; // else we have to create a new temporary Node to store the head->next and delete the first Node to deallocate the memory
    delete head;

    head = temp; // then we will return temp to head
}
/* Delete the Last Node  -  O(n) */
void popBack(Node *&head)
{
    if (head == NULL) /* if Linked List is Empty then we will simply return NULL */
    {
        return;
    }
    if (head->next == NULL) /* if Linked List as Only 1 Node in it then we will delete the Node and return NULL */
    {
        delete (head);
        head = NULL;
        return;
    }

    Node *curr = head;       /* if their is are more the 1 Nodes */
    while (curr->next->next) /* we traverse until we reach second last Node */
    {
        curr = curr->next;
    }
    delete (curr->next); /* then we will delete the last Node */
    curr->next = NULL;   /* and set last Node's Next to NULL */
                         // return Head
}
/* Insert a Node to Nth position */
void pushKth(Node *&head, int x, int n)
{
    Node *new_Node = new Node(x);
    if (n == 1)
    {
        new_Node->next = head;
        head = new_Node;
        return;
    }

    Node *curr = head;
    for (int i = 0; (i < n - 2) && curr; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        cout << "The given position beyond the limits" << endl;
        return;
    }

    new_Node->next = curr->next;
    curr->next = new_Node;
    return;
}

/* Delete Nth Node */
void popKth(Node *&head, int n)
{
    Node *curr = head;
    if (head == NULL)
    {
        return;
    }
    if (n == 1)
    {
        head = curr->next;
        delete curr;
        return;
    }
    for (int i = 0; i < n - 2; i++)
    {
        curr = curr->next;
    }
    if ((curr && curr->next) == 0)
    {
        cout << "The given position beyond the limits" << endl;
        return;
    }
    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return;
}

/* Searching in Linked List (Iterative) */
int search(Node *head, int x)
{
    int pos = 0;
    while (head)
    {
        ++pos;
        if (x == head->data)
        {
            return pos;
        }
        head = head->next;
    }
    return -1;
}

/* Searching in Linked List (Recursive) */
int rec_search(Node *head, int x)
{
    if (head == NULL)
        return -1;

    else if (head->data == x)
        return 1;

    else
    {
        int res = search(head->next, x);
        if (res == -1)
            return -1;
        else
            return (res + 1);
    }
}

/* Reverse a linked List */
void reverse(Node *&head)
{
    Node *curr = head, *prev = NULL, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

#endif