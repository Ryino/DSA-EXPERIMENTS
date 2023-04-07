#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class link_list
{
public:
    node *head = NULL;

    void traverse()
    {
        node *temp = head;

        if (head == NULL)
        {
            cout << "The list is empty!";
        }
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    void insert_at_head(int val)
    {
        node *n = new node(val);
        n->next = head;
        head = n;
    }

    void add_element_after(int val, int index)
    {
        node *temp = head;
        node *n = new node(val);
        while (temp != NULL && temp->data != index)
        {
            temp = temp->next;
        }

        if (temp->data != index)
        {
            cout << "Element not found!";
        }
        else if (head == NULL)
        {
            head = n;
        }
        else
        {

            n->next = temp->next;
            temp->next = n;
        }
    }

    void selection_sort()
    {
        cout << "Descending order!";
        node *min_index;
        node *temp2;

        for (node *temp = head; temp != NULL; temp = temp->next)
        {
            min_index = temp;
            for (temp2 = temp->next; temp2 != NULL; temp2 = temp2->next)
            {
                if (temp->data < temp2->data)
                {
                    min_index = temp2;
                }
            }
            int c;
            c = min_index->data;
            min_index->data = temp->data;
            temp->data = c;
        }
    }

    void insertion_sort()
    { node* key;
    node *temp2;
    
    prev->next=head;
        for(node *temp=head;temp!=NULL;temp=temp->next)
        {
            key=head;
            temp2=head->prev


        }
    }
};

int main()
{
    link_list l;
    l.traverse();
    l.insert_at_head(2);
    l.insert_at_head(4);
    l.insert_at_head(4389);
    l.add_element_after(3, 2);
    l.traverse();
    l.selection_sort();
    l.traverse();
}