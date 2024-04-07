#include <iostream>
using namespace std;

template <typename T>
class QueueLL
{
    struct Node
    {
        T data;
        Node *next;
        Node(T x)
        {
            data = x;
            next = NULL;
        }
    };
    int qsize;
    Node *head, *tail;

public:
    QueueLL()
    {
        qsize = 0;
        head = NULL;
        tail = NULL;
    }
    void enque(T x)
    {
        Node *new_node = new Node(x);
        if (head == NULL)
        {
            // Node* new_node = new Node(x);
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
        qsize++;
    }
    void deque()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            qsize--;
        }
    }

    int size() { return qsize; }
    bool isEmpty() { return (head == NULL); }

    T getFront()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    T getRear()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return tail->data;
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
    int n;
    cin >> n;
    QueueLL<int> q;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.enque(x);
    }
    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    q.deque();
    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;
    q.deque();
    cout << "Size: " << q.size() << endl;
    q.enque(3);
    cout << "Size: " << q.size() << endl;
    cout << "Front: " << q.getFront() << endl;
    cout << "Rear: " << q.getRear() << endl;

    return 0;
}