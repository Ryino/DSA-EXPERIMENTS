#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Stack
{
    public:
    node *head = NULL;

    void traverse()
    {
        if(is_empty())
        {
            cout<<"Stack is empty!";

        }
        else
        {
            node *temp=head;
            while(temp!=NULL)
            {
                cout<<temp->data<<"-->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
    }

    void push(int val)
    {
         node *n = new node(val);
        
        if(head ==NULL)
        {
            head=n;
        }
        else
        {
            n->next=head;
            head=n;

        }
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"Stack is empty!";
        }
        else
        {
            node *to_pop=head;
            head=head->next;
            cout<<to_pop->data<<" has been deleted!";
            delete to_pop;
        }
    }

    //   node* pop(node*& to_delete)
    // {
    //     if(head==NULL)
    //     {
    //         return NULL;
    //     }
    //     else
    //     {
    //         node *to_pop=head;
    //         head=head->next;
    //         free( pop(to_pop->next));
    //         return head;
    //     }
    // }
    
    void top()
    {
        cout<<"data at the top is:";
        cout<<head->data<<"\n";
    }

    bool is_empty()
    {
        if(head==NULL)
         return true;
        else 
         return false; 
    }

};

 int main()
 {
    Stack s;
    
    s.traverse();cout<<endl;
    s.push(3);cout<<endl;
    s.push(4);cout<<endl;
    s.traverse();cout<<endl;
    s.pop(s.head);cout<<endl;
    s.traverse();cout<<endl;
   // s.top();cout<<endl;
    
    return 0;
}

//reverse a link list 
//