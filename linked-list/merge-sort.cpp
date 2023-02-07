#include <iostream>
using namespace std;

//Incomplete!

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

    // Node *mergeSort(Node *first, Node *middle, Node *last)
    // {
    //     if(first!middle)

    // }

    Node *merge(Node *first, Node *middle, Node *last)
    {
        Node *left = first;
        Node *right = middle;

        Node *res = nullptr;
        Node *temp, *prev = nullptr;

        while (left != middle || right != last->next)

        {

            if (right == nullptr && left == nullptr)
            {
                break;
            }
            else if (right == nullptr && left != nullptr)
            {

                if (left == middle)
                    continue;
                temp = new Node(left->data);

                if (res == nullptr)
                    res = temp;

                else
                    prev->next = temp;

                prev = temp;
                left = left->next;
            }
            else if (left == nullptr && right != nullptr)
            {
                if (right == last->next)
                    continue;
                temp = new Node(right->data);

                if (res == nullptr)
                    res = temp;

                else
                    prev->next = temp;

                prev = temp;
                right = right->next;
            }
            else if (left->data < right->data)
            {
                if (left == middle)
                    continue;
                temp = new Node(left->data);

                if (res == nullptr)
                    res = temp;

                else
                    prev->next = temp;

                prev = temp;
                left = left->next;
            }
            else
            {
                if (right == last->next)
                    continue;
                temp = new Node(right->data);

                if (res == nullptr)
                    res = temp;

                else
                    prev->next = temp;

                prev = temp;
                right = right->next;
            }
        }

        return res;
    }

    Node *findMiddle()
    {

        Node *rabbit = this->head;
        Node *tortise = this->head;

        if (rabbit == nullptr || rabbit->next == nullptr)
            return rabbit;

        while (rabbit->next != nullptr && rabbit->next->next != nullptr)
        {
            rabbit = rabbit->next->next;
            tortise = tortise->next;
        }

        return tortise->next;
    }
    Node *findLast()
    {

        Node *tortise = this->head;

        if (tortise == nullptr || tortise->next == nullptr)
            return tortise;

        while (tortise->next != nullptr)
        {

            tortise = tortise->next;
        }

        return tortise;
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

    void print(Node *p)
    {
        //Node *p = head;

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
    LinkList l{};

    //l.push(2);
    l.push(1);
    l.push(3);
    l.push(6);
    l.push(5);
    l.push(7);

    l.print();

    l.print(l.merge(l.head, l.findMiddle(), l.findLast()));
}