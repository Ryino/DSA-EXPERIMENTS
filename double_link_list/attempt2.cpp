#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

class doubly
{
    public:
    node *head=NULL;
    

    void traverse()
    {
        if(head==NULL)
        {
            cout<<"List is empty!\n";

        }
        else
        {
            node *temp=head;
            while (temp!=NULL)
            {
                cout<<temp->data<<"-->";
                temp=temp->next;
                                
            }
            cout<<"NULL\n";


        }


    }

    void add_element_atstart(int val)
    {
        node *n = new node(val);
        if(head==NULL)
        {
            head=n;
                        
        }
        else
        {
            n->next=head;
            head->prev=n;
            head=n;
        }
    }

    void insert_after(int val,int index)
    {
        node *n=new node(val);
        node *temp=head;

        while(temp->data!=index && temp!=NULL)
        {
            temp=temp->next;

        }
       temp->next->prev=n;
       n->next=temp->next;
       temp->next=n;
       n->prev=temp;

    }

    void delete_node(int val)
    {
        node *temp=head;
        node *to_delete;

        if(head==NULL)
        {
            cout<<"List is empty!";

        }
        else
        {
            while(temp->data!=val&&temp!=NULL)
            {
                temp=temp->next;
            }
            
            if(temp==NULL)
            {
                cout<<"Element not found";
            }

           else if(temp->next==NULL)
            {
                to_delete=temp;
                temp->prev->next=NULL;
                delete to_delete;
                
            }
            else if(temp->prev==NULL)
            {   to_delete=temp;
                temp->next->prev=NULL;
                head=temp;
                delete to_delete;

            }
            else
            {
                to_delete=temp;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                
                delete to_delete;
            }


        }

    }

};
int main()
{
    doubly d;
   d.traverse(); 
    d.add_element_atstart(2);
    d.add_element_atstart(3);
    d.insert_after(7,3);
  d.delete_node(3);
    
    d.traverse();
}