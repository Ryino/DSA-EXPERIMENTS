#include <iostream>
using namespace std;

struct treenode
{
    int data;

    treenode *right = NULL;
    treenode *left = NULL;

    treenode(int val)
    {
        this->data = val;
    }
};

class BST
{
public:
    treenode *root = NULL;

    treenode *insert(treenode *t, int x)
    {
        treenode *n = new treenode(x);
        if (t == NULL)
        {
            t = n;
        }
        else
        {
            if (x < t->data)
            {
                t->left = insert(t->left, x);
            }
            else if (x > t->data)
            {
                t->right = insert(t->right, x);
            }
            else
                return t;
        }
    }

    treenode *deleterec(treenode *t, int x)
    {

        if (t == NULL)
        {
            cout << "ERROR\n";
        }
        else
        {
            if (x < t->data)
            {
                t->left = deleterec(t->left, x);
            }
            else if (x > t->data)
            {
                t->right = deleterec(t->right, x);
            }
            else
            {
                if (t->right && t->left)
                {
                    treenode *temp;
                    temp = findmin(t->right);
                    t->data = temp->data;
                    t->right = deleterec(t->right, x);
                }
                else 
                {
                    if(t->right)
                }
            }
        }
    }

    void print_in_order(treenode *t)
    {
        if (t != NULL)
        {
            print_in_order(t->left);
            cout << t->data << "-> ";
            print_in_order(t->right);
        }
    }
};

int main()
{
    BST b;
    b.root = b.insert(b.root, 2);
    b.insert(b.root, 3);
    b.print_in_order(b.root);
    cout << "NULL\n";
}
