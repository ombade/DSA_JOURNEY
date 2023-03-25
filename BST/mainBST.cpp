#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// function for get the Minimum Value form the BST
Node *minval(Node *root)
{
    Node *temp = root;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}
// function for get the Maximnm Value form the BST
Node *maxval(Node *root)
{
    Node *temp = root;
    while (temp->right != NULL)
    {

        temp = temp->right;
    }
    return temp;
}
void perOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << "   ";
    perOrder(root->left);
    perOrder(root->right);
}
void postOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << "   ";
}
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << "   ";
    inOrder(root->right);
}
// LevelOrder Traversal level by level
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // purana level complete traverse ho chuka hai
            cout << endl;
            if (!q.empty())
            {
                // queue still has some child ndoes
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

Node *insertBST(Node *root, int d)
{
    // base case condition
    if (root == NULL)
    {
        root = new Node(d);

        return root;
    }

    if (d > root->data)
    {
        // right part me insert karna h
        root->right = insertBST(root->right, d);
    }
    else
    {
        // left ke liye call karo
        root->left = insertBST(root->left, d);
    }

    return root;
}
void takeinput(Node *&root)
{
    int data;
    // cout<<"\n Enter the Data of the root -> ";
    cin >> data;
    while (data != -1)
    {
        root = insertBST(root, data);
        cin >> data;
    }
}

// function for the delete the Node for the BST
Node *DeleteNode(Node *&root, int val)
{
    // base condition that is root is NULL the
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == val)
    {
        // having 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // having 1 child  ]
        // it consist of two cases it is

        // case having child having at left and right as null
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // case having child having at right and left as null
        if (root->right != NULL && root->right == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // having 2 child
        if (root->right != NULL && root->right != NULL)
        {
            int Minval = minval(root->right)->data;
            root->data = Minval;
            root->right = DeleteNode(root->right, Minval);
            return root;
        }
    }
    else if (root->data > val)
    {
        root->left = DeleteNode(root->left, val);
        return root;
    }
    else
    {
        root->right = DeleteNode(root->right, val);
        return root;
    }
}
int main()

{
    int data;
    Node *root = NULL;
    cout << "\n Enter data to Create BST \n ";

    takeinput(root);
    cout << " BST is  \n ";
    levelOrderTraversal(root);
    cout << "\nPreorder \n";
    perOrder(root);
    cout << "\nPostorder \n";
    postOrder(root);
    cout << "\ninorder \n";
    inOrder(root);
    cout << "\n MIN value of the treee \n";
    cout << minval(root)->data;
    cout << "\n max value of the treee \n";
    cout << maxval(root)->data;
    cout << "Enter the value to be delelte in\n";
    int val;
    cin >> val;
    root = DeleteNode(root, val);
    levelOrderTraversal(root);
    return 0;
}
