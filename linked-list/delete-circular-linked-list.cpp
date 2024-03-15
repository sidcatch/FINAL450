#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *insert(Node *tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return newNode;
}

Node *deleteNode(Node *head, int key)
{
    if (head == nullptr)
        return nullptr;

    Node *current = head;
    Node *prev = nullptr;

    do
    {
        if (current->data == key)
        {

            if (current == head)
            {
                Node *temp = head;
                while (temp->next != head)
                    temp = temp->next;
                temp->next = head->next;
                head = head->next;
                delete current;
                return head;
            }
            else
            {
                prev->next = current->next;
                delete current;
                return head;
            }
        }
        prev = current;
        current = current->next;
    } while (current != head);

    cout << "Node with value " << key << " not found!" << endl;
    return head;
}

void printList(Node *head)
{
    if (head == nullptr)
        return;

    Node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    head = insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);

    cout << "Circular Linked List: ";
    printList(head);

    head = deleteNode(head, 3);

    cout << "Circular Linked List after deletion: ";
    printList(head);

    return 0;
}
