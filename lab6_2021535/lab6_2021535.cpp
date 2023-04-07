//task 1 - 2021535 rayyan hassan
#include <iostream>
#include <ctime>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    };
};

class link_list
{
public:
    node *head = NULL;
    node *sorted;

    void traverse()
    {
        if (head == NULL)
        {
            cout << "List is empty!\n";
        }
        else
        {
            node *temp = head;

            while (temp != NULL)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
    void insert_at_head(int data)
    {
        node *n = new node(data);
        n->next = head;
        head = n;
    }
    void insert_element_after(int data, int val)
    {
        if (head == NULL)
        {
            insert_at_head(data);
        }
        else
        {
            node *temp = head;
            while (temp != NULL && temp->data != val)
            {
                temp = temp->next;
            }
            node *n = new node(data);
            n->next = temp->next;
            temp->next = n;
        }
    }
    void populate(int n)
    {
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            int random = rand() % 500 + 1;
            insert_at_head(random);
        }
    }

    void bubble_sort()
    {
        int temp;
        node *current = head;
        node *traverse;
        while (current != NULL)
        {
            traverse = head;
            while (traverse != NULL)
            {
                if (current->data < traverse->data)
                {
                    temp = current->data;
                    current->data = traverse->data;
                    traverse->data = temp;
                }
                traverse = traverse->next;
            }
            current = current->next;
        }
    }

    void insertionSort()
    {
        sorted = NULL;
        node *current = head;

        while (current != NULL)
        {
            node *next = current->next;
            sortedInsert(current);
            current = next;
        }
        head = sorted;
    }

    void sortedInsert(node *newnode)
    {
        if (sorted == NULL || sorted->data >= newnode->data)
        {
            newnode->next = sorted;
            sorted = newnode;
        }
        else
        {
            node *current = sorted;
            while (current->next != NULL && current->next->data < newnode->data)
            {
                current = current->next;
            }
            newnode->next = current->next;
            current->next = newnode;
        }
    }
};

int main()
{
    link_list l;
    cout << "\t-----WELCOME TO THE LINK LIST PROGRAM!-----\n";
    char choice ='y';

    while(choice =='y')
    {
    cout << "Kindly enter the operation you want to execute:\n";
    cout << "1.Populate\n2.traverse\n3.bubble sort \n4.insertion sort\n5.End session\n";


    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "Enter the size of the link list!";
        int size;
        cin >> size;
        l.populate(size);
    }

    else if (n == 2)
    {
        cout << "linked list is:   ";
        l.traverse();
    }
    else if (n == 3)
    {
        cout << "The bubble  sorted list is:   ";
        l.bubble_sort();
        l.traverse();
    }
    else if (n == 4)
    {
        cout << "The list after preforming insertion sort is:";
        l.insertionSort();
        l.traverse();
    }
    else if(n==5)
    {
        choice = 'n';
    }

    else
    {
        cout<<"Enter the correct option!";
    }
    }
    cout<<"\n\tYour session has ended!";
}