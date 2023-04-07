#include <iostream>
using namespace std;

struct avlnode
{
    int data;
    int height;
    avlnode *left = NULL;
    avlnode *right = NULL;
};

class AVL
{
public:
    int height(avlnode *a)
    {
        int h = 0;
        if (a == NULL)
        {
            return 0;
        }
        else
        {
            int l_height = height(a->left);
            int r_height = height(a->right);
            h = max(l_height, r_height) + 1;
        }
        return h;
    }
    int diff(avlnode *a)
    {
        if (a != NULL)
        {
            return height(a->right) - height(a->left);
        }
    }
    avlnode *rr_rotaion(avlnode *k2) // left rotate
    {
        avlnode *k1;
        k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k1->height = 1 + max(height(k1->right), height(k1->left));
        k2->height = 1 + max(height(k2->right), height(k2->left));
        return k2;
        cout<<"left rotation!\n";
    }
    avlnode ll_rotation(avlnode *)
};

int main()
{
}