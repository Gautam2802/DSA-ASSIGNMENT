// Name-Gautam Singal
// SID-21104078
// Branch-EE

#include <iostream>
#include <queue>
using namespace std;

// Creating structure of Node of a tree
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
        : val(val), left(NULL), right(NULL)
    {
    }
};

// Function to insert data in a BST
Node *insert(Node *root, int data)
{

    if (root == NULL)
    {
        Node *new_node = new Node(data);
        root = new_node;
        return root;
    }

    if (data < root->val)
    {
        root->left = insert(root->left, data);
    }

    else if (data > root->val)
    {
        root->right = insert(root->right, data);
    }

    else
    {
        return root;
    }

    return root;
}

// Function to print a tree using Level Order Traversal
void level_order_traversal(Node *root)
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
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            };
        }

        else
        {
            cout << temp->val << " ";
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

// Function for min value node in a BST
Node *min_node(Node *node)
{
    Node *current = node;

    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Function to delete a node in Binary Search Tree
Node *delete_node(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->val)
        root->left = delete_node(root->left, key);

    else if (key > root->val)
        root->right = delete_node(root->right, key);

    else
    {
        if (root->left == NULL and root->right == NULL)
            return NULL;

        else if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp =min_node(root->right);
        root->val = temp->val;
        root->right = delete_node(root->right, temp->val);
    }
    return root;
}

// Function to print an array
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // Taking number of element in array as input and forming it.
    int n;
    cout << "\nEnter number elements in the array to form Binary Search Tree: ";
    cin >> n;
    int arr[n];
    cout << "\nEnter elements in the array to form BST: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    // printing the array
    cout << "\nArray:[";
    print_array(arr, n);
    cout << "]";
    cout << endl;

    // root is the top most node of Binary Search Tree
    Node *root = NULL;
    // Inserting element of the array in Binary Search Tree
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    // Displaying Binary Search Tree using Level Order Traversal
    cout << "\nBinary Search Tree using Level Order Traversal\n"<< endl;
    level_order_traversal(root);


    // key is the data to be deleted from Binary Search Tree
    int key;
    cout << "\nEnter data to be deleted from BST:";
    cin >> key;
    // deleting key from Binary Search Tree
    root = delete_node(root, key);
    // Displaying Binary Search Tree after deletion of key
    cout << "\nBinary Search Tree after deleting of key:" << key << endl;
    cout << endl;
    level_order_traversal(root);
}

/*
the tree has space complexity of O(n) and 
the array has also the space complexity of O(n)
*/
