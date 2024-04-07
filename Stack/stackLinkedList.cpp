#include <iostream>
// #include "../Cpplibrary/array.h"
using namespace std;

#define endl '\n'
#define space ' '
/*************************************/

class myStackLL
{
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
    Node *head;
    int size;

public:
    myStackLL()
    {
        head = NULL;
        size = 0;
    }
    void push(int x)
    {
        Node *new_node = new Node(x);
        if (head == NULL)
        {
            head = new_node;
        }
        else
        {
            new_node->next = head;
            head = new_node;
        }
        size++;
    }
    int pop()
    {
        if (size == 0 && head == NULL)
        {
            cout << "underflow: stack is empty ";
            return 0;
        }
        else //if (size == 1 && head->next == NULL)
        {
            int res = head->data;
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return res;
        }
    }
    void print()
    {
        Node *curr = head;
        // print();
        while (curr)
        {
            cout << curr->data << space;
            curr = curr->next;
        }
        cout << endl;
    }
    int peek()
    {
        if (head == NULL && size == 0)
        {
            cout << "underflow: stack is empty ";
            return 0;
        }
        else
        {
            return head->data;
        }
    }
    bool isEmpty()
    {
        return !head;
    }
};

inline void solve()
{
    myStackLL s;

    cout << s.pop() << endl;
    cout << "top: " << s.peek() << endl;
    s.push(3);
    s.push(5);
    s.push(8);
    cout << "top: " << s.peek() << endl;
    s.print();
    // cout << endl;
    cout << s.pop() << " is poped" << endl;
    cout << "top: " << s.peek() << endl;
    s.push(1);
    s.print();
    if (s.isEmpty())
        cout << "stack is empty\n";
    else
        cout << "stack is not  empty\n";
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
