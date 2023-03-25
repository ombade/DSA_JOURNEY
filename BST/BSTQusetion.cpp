#include <iostream>
#include <queue>
#include <climits>
#include "mainBST.cpp"
using namespace std;

Node *searchBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }

    if (root->data > val)
    {
        return searchBST(root->left, val);
    }
    else
    {
        return searchBST(root->right, val);
    }
}

// vaild bst for the
// Approch 1
bool solve(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);
        return (right && left);
    }
    else
    {
        return false;
    }
}
bool isValidBST(Node *root)
{
    return solve(root, INT_MIN, INT_MAX);
}

// Approch 2
vector<int> v;
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    /// cout << root->val << "   ";
    v.push_back(root->data);
    inOrder(root->right);
}
bool isValidBST(Node *root)
{
    inOrder(root);
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i + 1] <= v[i])
            {
                return false; // if array is not strictly increasing
            }
        }
    }
    return true;
}