///Here we create a Binary tree from an array ,as left child is arr[2*i+1] where i is parent index and right child is arr[2*i+2]
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* InsertLevelOrder(Node* root,int arr[],int i,int n)
{
    if(i<n)
    {
        Node* temp=new Node(arr[i]);
        root=temp;

        root->left=InsertLevelOrder(root->left,arr,2*i+1,n);
        root->right=InsertLevelOrder(root->right,arr,2*i+2,n);
    }
    return root;
}

void PreOrder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(Node *root)
{
    if (root == NULL)
        return;

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

void PostOrder(Node *root)
{
    if (root == NULL)
        return;

    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

void LevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp != NULL)
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
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}


int main()
{
    Node* root;
    int arr[]={1,2,3,4,5,6,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    root=InsertLevelOrder(root,arr,0,n);

    cout << "PREORDER: ";
    PreOrder(root);
    cout << "\nINORDER: ";
    InOrder(root);
    cout << "\nPOSTORDER: ";
    PostOrder(root);
    cout << "\nLEVELORDER: ";
    LevelOrder(root);
}