#include <iostream>
using namespace std;

struct treenode
{
public:
    int data;
    treenode *left;
    treenode *right;

    treenode(int val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }
};

class bst
{

public:
    treenode *root = NULL;
    treenode *insert(int val, treenode *root)
    {
        treenode *n = new treenode(val);

        if (root == NULL)
        {
            root = n;
        }
        else
        {

            if (val < root->data)
            {
                root->left = insert(val, root->left);
            }
            else if (val > root->data)
            {
                root->right = insert(val, root->right);
            }
            else
            {
                return root;
            }
        }
    }

    treenode *findmin(treenode *t)
    {
        if (t == NULL)
        {
            return NULL;
        }
        else if (t->left == NULL)
        {
            return t;
        }
        else
            return findmin(t->left);
    }
    void inorder(treenode *t)
    {
        if (t != NULL)
        {

            inorder(t->left);
            cout << t->data << " ";
            inorder(t->right);
        }
    }

    treenode *delete_rec(treenode *t, int x)
    {
        if (t == NULL)
        {
            cout << "ERROR!\n";
        }
        else if (x < t->data)
        {
            t->left = delete_rec(t->left, x);
        }
        else if (x > t->data)
        {
            t->right = delete_rec(t->right, x);
        }
        else
        {
            treenode *temp;
            if (t->left && t->right)
            {

                temp = findmin(t->right);
                t->data = temp->data;
                t->right = delete_rec(t->right, t->data);
            }
            else
            {
                if (t->left)
                {
                    t = t->left;
                }
                else if (t->right)
                {
                    t = t->right;
                }
                delete (temp);
            }
        }
        return t;
    }
};

int main()
{
    bst b;

    b.root = b.insert(2, b.root);
    b.insert(7, b.root);
    b.insert(1, b.root);
    b.insert(8, b.root);
    b.delete_rec(b.root,7);
    b.inorder(b.root);
}