#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int data, node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

struct LinkList
{
    node *head;
    //int size;

    LinkList()
    {
        head = nullptr;
    }

    node *reverseInGroups(int k)
    {
        if (k == 1)
            return head;

        node *current = head;
        node *next = nullptr;
        node *prev = nullptr;

        bool isFirstGroup = true;
        node *firstInPrevGroup = head;
        node *nextFirstInPrevGroup = nullptr;

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

        return head;
        //cout << endl;
    }

    void print()
    {
        node *p = head;

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
        node *p = new node(x, head);
        head = p;
    }
};

int main()
{
    LinkList l{};

    // l.push(1);
    //l.push(2);
    l.push(3);
    l.push(4);
    l.push(5);
    l.push(6);
    l.push(7);
    l.push(8);
    l.push(9);

    l.print();

    l.reverseInGroups(3);
    l.print();
}