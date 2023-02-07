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

    void reverseInGroupsIterative(int k)
    {
        if (k == 1)
            return;

        Node *current = head;
        Node *next = nullptr;
        Node *prev = nullptr;

        bool isFirstGroup = true;
        Node *firstInPrevGroup = head;
        Node *nextFirstInPrevGroup = nullptr;

        int count = 0;
        while (current != nullptr)
        {
            next = current->next;

            //char place = 'i';
            if (count % k == 0)
            {
                nextFirstInPrevGroup = current;
                //place = 'f';
            }
            else if (count % k == k - 1)
            {

                if (isFirstGroup)
                {
                    head = current;
                    isFirstGroup = false;
                }
                else
                {
                    firstInPrevGroup->next = current;
                    firstInPrevGroup = nextFirstInPrevGroup;
                }

                //place = 'l';
            }

            if (current->next == nullptr)
                firstInPrevGroup->next = current;

            current->next = prev;
            prev = current;
            current = next;

            //cout << place << " ";
            count++;
        }
        nextFirstInPrevGroup->next = nullptr;

        //cout << endl;
    }

    Node *reverseInGroupsRecursive(Node *head, int k)
    {
        if (!head)
            return nullptr;

        Node *current = head;
        Node *next = nullptr;
        Node *prev = nullptr;

        int count = 0;
        while (current != nullptr && count < k)
        {

            next = current->next;

            current->next = prev;

            prev = current;
            current = next;
            count++;
        }

        if (next != nullptr)
            head->next = reverseInGroupsRecursive(next, k);

        return prev;
    }

    void print()
    {
        Node *p = head;

        int count = 0;
        while (p != nullptr && count < 50)
        {
            count++;
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

    // l.push(1);
    l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.push(6);
    l.push(7);
    l.push(8);
    l.push(9);

    l.print();

    l.reverseInGroupsIterative(3);
    l.print();

    l.head = l.reverseInGroupsRecursive(l.head, 5);
    l.print();
}