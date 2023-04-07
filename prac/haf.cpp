#include <iostream>
using namespace std;
struct node
{
    int data;
    node *right;
    node *left;

    node()
    {

        this->left = NULL;
        this->right = NULL;
    }
};

node *root = NULL;

int height(node *temp)
{
    int h = -1;
    if (temp != NULL)
    {
        int l_height = height(temp->left);
        int r_height = height(temp->right);
        int max_height;
        if (l_height > r_height)
        {
            max_height = l_height;
        }
        else
        {
            max_height = r_height;
        }
        return max_height+1;
    }
}

int diff(node *temp)
{
    int difference;
    int left;
    int right;

    left = height(temp->left);   // to find out the height of the left subtree
    right = height(temp->right); // to find out the height of the right subtree
    difference = left - right;

    return difference;
}
node *ll_rotation(node *root)
{
    node *temp;
    temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

node *rr_rotation(node *root)
{
    node *temp;
    temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}

node *rl_rotation(node *root)
{
    cout << "RL rotation" << endl;
    node *temp;
    temp = root->right;
    root->right = ll_rotation(temp);
    return rr_rotation(root);
}

node *lr_rotation(node *root)
{
    cout << "LR rotation" << endl;
    node *temp;
    temp = root->left;
    root->left = rr_rotation(temp);
    return ll_rotation(root);
}

void inorder(node *tree)
{
    if (tree == NULL)
    {
        return;
    }
    inorder(tree->left);
    cout << tree->data << ",";
    inorder(tree->right);
}

node *balance(node *temp)
{ // balance = left -right
    int bal_factor = diff(temp);
    cout << "Balance factor is:" << bal_factor;

    if (bal_factor > 1) // >1 means left
    {
        cout << "difference in balancing at the left is :" << diff(temp->left) << endl;

        if (diff(temp->left) > 0) //>0 means left
        {
            temp = ll_rotation(temp);
        }
        else
        {
            temp = lr_rotation(temp);
        }
        return temp;
    }
    else if (bal_factor < -1)
    {
        cout << "Difference factor at the right is: " << diff(temp->right) << endl;
        if (diff(temp->right) > 0)
        {
            temp = rl_rotation(temp);
        }
        else
        {
            temp = rr_rotation(temp);
        }
        return temp;
    }
    else
    {
        cout << endl
             << "The tree is balanced!";
        return temp;
    }
}

node *insert(node *root, int val)
{ // if tree is empty
    if (root == NULL)
    {
        node *root = new node;
        root->data = val;
        return root;
    }
    else if (val < root->data) // if value is less than data of root
    {
        root->left = insert(root->left, val); // recursive call
        root = balance(root);                 // to check the balance
        return root;
    }

    else // if value is greater than data of root
    {
        root->right = insert(root->right, val);
        root = balance(root);
        return root;
    }
}

int main()
{
    char choice = 'y';
    while (choice == 'y')
    {
        cout << "\n1. Enter data in tree" << endl;
        cout << "2. Inorder Traversal of tree" << endl;
        cout << "3. Height of tree" << endl;
        cout << "4.End session!\n";
        int select;
        cin >> select;
        cout << endl;
        int he = 0;

        if (select == 1)
        {
            int val;
            cout << "Enter data to insert" << endl;
            cin >> val;
            root = insert(root, val);
        }
        else if (select == 2)
        {
            cout << "Inorder traversal is: " << endl;
            inorder(root);
            cout << endl;
        }

        else if (select == 3)
        {
            he = height(root);
            cout << "The height of tree is: " << he << endl;
        }
        else if (select == 4)
            choice = 'n';

        else

            cout << "misinput please try again!";
    }

    return 0;
}
