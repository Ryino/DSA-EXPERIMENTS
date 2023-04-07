#include <iostream>
using namespace std;

struct treenode
{
    int data;
    treenode *left;
    treenode *right;

    treenode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    treenode *root = NULL;

public:
    treenode *insert(int val, treenode *t)
    {
        treenode *n = new treenode(val);
        if (t == NULL)
        {
            t = n;
        }
        else if (val < t->data)
        {
            t->left = insert(val, t->left);
        }
        else if (val > t->data)
        {
            t->right = insert(val, t->right);
        }
        else
        {
            return t;
        }
    }

    treenode *findmin(treenode *t)
    {
        if(t==NULL)
        {
            return 0;

        }
        else if(t->left==NULL)
        {
            return t;
        }
        else{
            t->left=findmin(t->left);
        }
    }

    
};

int main()
{
}