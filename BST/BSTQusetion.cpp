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
bool solve1(Node *root, int min, int max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data > min && root->data < max)
    {
        bool left = solve1(root->left, min, root->data);
        bool right = solve1(root->right, root->data, max);
        return (right && left);
    }
    else
    {
        return false;
    }
}
bool isValidBST(Node *root)
{
    return solve1(root, INT_MIN, INT_MAX);
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

//  Kth Smallest Element in a BST------------------------------------
int solve(Node *root, int &index, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int left = solve(root->left, index, k);
    if (left != -1)
    {
        return left;
    }
    // node case for the
    index++;
    if (index == k)
    {
        return root->data;
    }
    return solve(root->right, index, k);
}
int kthSmallest(Node *root, int k)
{
    int index = 0;
    int ans = solve(root, index, k);
    return ans;
}

// Lowest Common Ancestor of a Binary Search Tree--------------------------------------
// there are Two approch
// 1) iterative approch
Node *LCA(Node *root, int n1, int n2)
{
    // Your code
    // Node * temp = root;
    while (root != NULL)
    {
        if (root->data < n1 && root->data < n2)
        {
            root = root->right;
        }
        else if (root->data > n1 && root->data > n2)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
}

// 2) recursive approch

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (root == NULL || p->data == root->data || q->data == root->data)
        return root;
    if (p->data < root->data && q->data < root->data)
        return lowestCommonAncestor(root->left, p, q);
    if (p->data > root->data && q->data > root->data)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}

// Predecessor and Successor
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Base case
    if (root == NULL)
        return;

    // If key is present at root
    if (root->data == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node *tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp;
        }

        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node *tmp = root->right;
            while (tmp->left)
                tmp = tmp->left;
            suc = tmp;
        }
        return;
    }

    // If key is smaller than root's key, go to left subtree
    if (root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else // go to right subtree
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

// Two Sum IV - Input is a BST--------------

void inordersum(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inordersum(root->left, v);
    v.push_back(root->data);
    inordersum(root->right, v);
}
bool twoSumInBST(Node *root, int target)
{
    // Write your code here
    vector<int> v;
    inordersum(root, v);
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
            j--;

        else
            i++;
    }
    return false;
}
