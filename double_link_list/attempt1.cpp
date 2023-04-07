#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        this->data = val;
        next = NULL;
        prev = NULL;
    }
};
class Doubly_Link_list
{
public:
    node *head;
    Doubly_Link_list()
    {
        head = NULL;
    }
    void insert_at_head(int val)
    {
        node *n = new node(val);

        n->next = head;
        if (head == NULL)
        {
            n->prev = NULL;
        }
        else
        {
            head->prev = n;
        }
        head = n;
    }
    void insert_at_tail(int val)
    {
        if (head == NULL)
        {
            insert_at_head(val);
        }
        else
        {
            node *n = new node(val);
            node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }
    }
    void print_list()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }

    void delete_list(int val)
    {
        node *pointer_to_delete;
        pointer_to_delete = this->head;
        while (pointer_to_delete != NULL && pointer_to_delete->next->data != val)
        {
            pointer_to_delete = pointer_to_delete->next;
        }
        if (pointer_to_delete->prev == NULL)
        {
            void delete_at_head();
        }
        else if (pointer_to_delete->prev != NULL)
        {
            pointer_to_delete->prev->next = pointer_to_delete->next;
        }
        //edge case  tail 
        if (pointer_to_delete->next != NULL)
        {
            pointer_to_delete->next->prev = pointer_to_delete->prev;
            delete pointer_to_delete;
        }
        else if(pointer_to_delete->next==NULL)
        {
            pointer_to_delete->prev->next=NULL;
        }
    }

    void delete_at_head()
    {
        node *to_delete;
        to_delete = head;
        head = head->next;
        head->prev = NULL;

        delete to_delete;
    }
};

int main()

{

    Doubly_Link_list l;
    l.insert_at_head(5);
    l.insert_at_tail(2);
    l.insert_at_tail(3);
    l.print_list();
    l.delete_list(2);
    l.print_list();
}