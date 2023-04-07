#include <iostream>
using namespace std;
struct node
{
    string data;
    node *next;
    node(string data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class queue
{
public:
    node *head = NULL;

    void enqueue(string str)
    {
        node *n = new node(str);

        n->next = head;
        head = n;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "Queue is empty!\n";
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

    void dequeue()
    {
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *to_delete = temp->next;
        temp->next = NULL;
        cout << to_delete->data << " has been deleted\n";
        delete to_delete;
    }
    void LengthOfString(queue *obj)
    {
         if (head == NULL)
        {
            cout << "Queue is empty!\n";
        }
        else
        {
            
            node *temp = head;
            int count=0;
            while (temp != NULL)
            {
                
                temp = temp->next;
                count++;
            } 
            cout <<"The size of the queue is "<<count;
        }

    }
// code will only work for integers

//     void prority_queue()
//     {
//         for(node *temp1=head;temp1!=NULL;temp1=temp1->next)
//           {
//             for(node *temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
//             {
//                 if(temp1->data>temp2->data)
//                 {
//                     int temp;
//                     temp=temp1->data;
//                     temp1->data=temp2->data;
//                     temp2->data=temp;
//                 }

//             }
//           }
//     }
};

int main()
{
    queue q;
    q.display();
    q.enqueue("a");
    q.enqueue("b");
    q.display();
    q.dequeue();
    q.display();
    q.LengthOfString(&q);
}