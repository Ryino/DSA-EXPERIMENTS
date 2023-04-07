#include <iostream>
using namespace std;

struct avlnode
{
    int data;
    int height;
    avlnode *right;
    avlnode *left;

    avlnode()
    {
        this->left=NULL;
        this->right=NULL;
    }
};
class Avl
{
public:
avlnode *root=NULL;
    int height(avlnode *root)
    {
        int h = -1;
      
       if(root!=NULL)
        {
            int l_height = height(root->left);
            int r_height = height(root->right);
            int max_height = max(l_height, r_height);
            h = max_height + 1;
        }
        
        return h;
    }
    int diff(avlnode *r)
    {
        int dif = 0;
        if (r == NULL)
        {
            cout << "Tree is empty!";
        }
        else
        {

            dif = height(r->left) - height(r->right);
        }
        return dif;
    }
    avlnode *rr_rotation(avlnode *r) // left rotation
    {
        avlnode *t;
        t = r->right;

        r->right = t->left;
        t->left = r;

        return t;
        cout << "right right rotaiton\n";
    }

    avlnode *ll_rotation(avlnode *r) // right rotation
    {
        avlnode *t;
        t = r->left;

        r->left = t->right;
        t->right = t;

        return t;

        cout << "LEft left rotation\n";
    }

    avlnode *rl_rotation(avlnode *r)
    {
        r->right = ll_rotation(r->right);
        r = rr_rotation(r);
        return r;
    }
    avlnode *lr_rotation(avlnode *r)
    {
        r->left = rr_rotation(r->left);
        r = ll_rotation(r);
        return r;
    }

    avlnode *balance(avlnode *t)
    {
        int balance = diff(t);
        if (balance > 1)
        {
            if (diff(t->left) > 0)
                t = ll_rotation(t);
            else
                t = lr_rotation(t);
        }
        else if (balance < -1)
        {
            if (diff(t->right) > 0)
                t = rl_rotation(t);
            else
                t = rr_rotation(t);
        }
        return t;
    }
    // insert and inorder
    avlnode *insert(avlnode *r, int v)
    {
        if (r == NULL)
        {
           avlnode *r = new avlnode;
            r->data = v;
            
            return r;
        }
        else if (v < r->data)
        {
            r->left = insert(r->left, v);
            r = balance(r);
            return r;
        }
        else  
        {
            r->right = insert(r->right, v);
            r = balance(r);
            return r;
        }
        
    }

    void print(avlnode *r)
    {
        if (r == NULL)
        {
            return;
        }
        else
        {
            print(r->left);
            cout << r->data << " ";
            print(r->right);
        }
    }
};
int main()
{
    Avl a;
    avlnode *r ;

   r= a.insert(r, 3);
    r=a.insert(r, 4);
    a.insert(r, 2);
    a.insert(r, 0);
    a.insert(r, 43);
    a.insert(r, 23);
    a.insert(r, 1000);
    a.print(r);
}