#ifndef CDL_h
#define CDL_H
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};
int printList(Node **head)
{
    int cnt = 0;
    Node *curr = *head;
    if (*head)
    {
        do
        {
            cnt++;
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != *head);
        cout << endl;
    }
    return cnt;
}

void pushHead(Node **head, int x)
{
    Node *new_node = new Node(x);
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else
    {
        Node *temp = (*head)->prev;
        new_node->next = *head;
        new_node->prev = temp;
        (*head)->prev = new_node;
        temp->next = new_node;
        *head = new_node;
    }
}

void pushTail(Node **head, int x)
{
    Node *new_node = new Node(x);
    if (*head == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        *head = new_node;
    }
    else
    {
        Node *temp = (*head)->prev;
        new_node->next = *head;
        new_node->prev = temp;
        (*head)->prev = new_node;
        temp->next = new_node;
    }
}

void pushKth(Node **head, int x, int k)
{
    if (*head == NULL || k == 1)
    {
        return pushHead(&*head, x);
    }
    else
    {
        Node *new_node = new Node(x);
        Node *curr = *head;
        for (int i = 0; i < k - 2; i++)
        {
            if (i && curr->next == *head)
            {
                cout << "ERRor k" << endl;
                return;
            }
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = new_node;
        new_node->next = temp;
        temp->prev = new_node;
        new_node->prev = curr;
    }
}

void popHead(Node **head)
{
    Node *temp = *head;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->prev == *head)
    {
        delete temp;
        *head = NULL;
    }
    else
    {
        (*head) = (*head)->next;
        temp->prev->next = *head;
        (*head)->prev = temp->prev;
        delete temp;
    }
}

void popTail(Node **head)
{
    Node *temp = (*head)->prev;
    if (*head == NULL)
    {
        return;
    }
    else if ((*head)->prev == *head)
    {
        delete temp;
        *head = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        (*head)->prev = temp->prev;
        delete temp;
    }
}

void popKth(Node **head, int k)
{
    if (*head == NULL || k == 1)
    {
        return popHead(&*head);
    }
    else
    {
        Node *curr = *head;
        for (int i = 0; i < k - 2; i++)
        {
            if (i && curr->next->next == *head)
            {
                cout << "ERRor k" << endl;
                return;
            }
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        temp->next->prev = temp->prev;
        delete temp;
    }
}

#endif
