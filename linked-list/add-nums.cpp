#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

struct LinkList
{
    Node *head;
    //int size;

    LinkList()
    {
        head = nullptr;
    }

    LinkList(Node *h)
    {
        head = h;
    }

    LinkList add(LinkList sec)
    {
        Node *a = this->head;
        Node *b = sec.head;

        Node *res = nullptr;
        Node *temp, *prev = nullptr;

        int carry = 0, sum;

        while (a != nullptr || b != nullptr)
        {
            sum = carry + (a ? a->data : 0) + (b ? b->data : 0);

            carry = (sum >= 10) ? 1 : 0;

            sum = sum % 10;

            temp = new Node(sum);

            if (res == nullptr)
                res = temp;

            else
                prev->next = temp;

            prev = temp;

            if (a)
                a = a->next;
            if (b)
                b = b->next;
        }

        if (carry > 0)
            temp->next = new Node(carry);

        return LinkList(res);
    }

    void reverseIterative()
    {
        Node *current = head;
        Node *next = nullptr;
        Node *prev = nullptr;

        while (current != nullptr)
        {
            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;
    }

    Node *reverseRecursive(Node *current)
    {
        if (current == nullptr || current->next == nullptr)
            return current;

        Node *newHead = reverseRecursive(current->next);

        //reverse
        current->next->next = current;

        //Not doing this will leave a loop at the last node of the reversed list
        current->next = nullptr;

        return newHead;
    }

    void print()
    {
        Node *p = head;

        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void push(int x)
    {
        Node *p = new Node(x, head);
        head = p;
    }
};

int main()
{
    LinkList l1{};

    l1.push(1);
    l1.push(5);
    l1.push(2);
    l1.push(9);

    l1.print();
    LinkList l2{};

    l2.push(1);
    l2.push(5);
    l2.push(2);
    l2.push(3);

    l2.print();

    l1.reverseIterative();
    l2.reverseIterative();

    LinkList l3 = l1.add(l2);

    l3.reverseIterative();

    l3.print();
}