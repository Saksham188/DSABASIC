///Here we will create a Binary tree and the three traversals inorder,preorder ,postorder

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

void PreOrderNonRec(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    s.push(root);

    while (!s.empty())
    {
        Node *val = s.top();
        s.pop();

        cout << val->data << " ";

        if (val->right)      ///Non recursive preorder ke lie phele right dalo tbhi pop krte hue phele left print hoga.
        {
            s.push(val->right);
        }
        if (val->left)
        {
            s.push(val->left);
        }
       
    }
}

///Post Order Formed easily using 2 stacks:
void PostOrderNonRec(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    stack<Node *> s2;
    s.push(root);
    Node* val;

    while (!s.empty())
    {
        val = s.top();
        s.pop();
        s2.push(val);

        if (val->left)  
        {
            s.push(val->left);  ///Non recursive postorder ke lie phele left dalo tbhi pop krte hue phele right print hoga.
        }

        if (val->right)      
        {
            s.push(val->right);
        }
       
    }
    while(!s2.empty())
    {
        val=s2.top();
         cout << val->data << " ";
         s2.pop();
    }
}



int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "PREORDER: ";
    PreOrder(root);
    cout << "\nINORDER: ";
    InOrder(root);
    cout << "\nPOSTORDER: ";
    PostOrder(root);
    cout << "\nLEVELORDER: ";
    LevelOrder(root);
    cout << "PREORDER NON RECURSIVE: ";
    PreOrderNonRec(root);
    cout << "POSTORDER NON RECURSIVE: ";
    PostOrderNonRec(root);
}

