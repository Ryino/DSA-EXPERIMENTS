#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    int count;

    node(int value)
    {
        this->data = value;
        this->next = NULL;
    }
};

class link_list
{

public:
    node *head;
    void count_of_nodes(node *head) // transverse
    {
        int count = 0;
        if (head == NULL)
            cout << "Linked list is empty!";
        node *ptr;
        ptr = head;
        while (ptr != NULL)
        {
            count++;
            ptr = ptr->next;
        }
        cout << "\nCount: " << count;
    }

    void print_list(node *head) // print
    {
        node *ptr;
        if (head == NULL)
            cout << "list is empty";

        else
        {
            while (ptr != NULL)
            {
                cout << ptr->data <<"\n";
                ptr = ptr->next;
            }
        }
    }

    void add_at_start(node *&head, int value) // add at start
    {
        node *n = new node(value);
        n->next = head;
        head = n;
    }

    void addAfter(node *&head, int val, int key)
    {
        node *n = new node(val);
        node *temp = head;
        while (temp != NULL && temp->data != val)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Node not found" << endl;
        }
        else if (temp->data = val)
        {
            temp->next = n;
        }
        
    }
};

int main()
{

   
    link_list l;
   
    l.add_at_start(head, 5);
    cout << endl;
    l.add_at_start(head,6);
    
    l.print_list(head);
    cout << endl;
    l.addAfter(head, 10, 5);
    l.print_list(head);

    return 0;
}
