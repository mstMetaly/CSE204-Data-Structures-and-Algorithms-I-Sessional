#include<iostream>
#include<fstream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;


    Node()
    {
        data=NULL;
        left=NULL;
        right=NULL;
    }

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }

};


class BST
{

public:
    Node* root;
    int nodeCount=0;
    BST()
    {
        root=new Node;
    }


    void Insert(int value)
    {
        if(root->data==NULL)
        {
            nodeCount++;
            root=new Node(value);
        }

        else if(root->data==value)
            return;

        Node * temp=root;

        while(temp!=NULL)
        {

            if(value < temp->data && temp->left==NULL)
            {
                temp->left=new Node(value);
                nodeCount++;
                break;
            }

            else if(value < temp->data)
            {
                temp=temp->left;
            }

            else if(value > temp->data && temp->right==NULL)
            {
                temp->right=new Node(value);
                nodeCount++;
                break;
            }

            else
            {
                temp=temp->right;
            }


        }

    }



    Node* deleteLeafNode(Node* root,int value,int &flag)
    {

        if (root == NULL)
            return NULL;

        if(root->left==NULL && root->right==NULL && root->data==value && nodeCount==1)
        {
            nodeCount--;
            flag=1;
            delete[] root;
            root=new Node();
            return NULL;
        }


        root->left = deleteLeafNode(root->left, value,flag);
        root->right = deleteLeafNode(root->right, value,flag);

        if (root->data == value && root->left == NULL && root->right == NULL)
        {
            nodeCount--;
            flag=1;
            return NULL;
        }

        return root;

    }


    bool Delete(int value)
    {
        Node* temp;
        int flag=0;
        deleteLeafNode(root,value,flag);
        if(flag==0)
            return false;
        else
            return true;

    }



    bool Find(int value)
    {
        if(root==NULL)
            return false;
        Node* temp=root;
        while(temp!=NULL)
        {
            if(value==temp->data)
                return true;

            else if(value< temp->data)
            {
                temp=temp->left;
            }
            else if(value> temp->data )
            {
                temp=temp->right;
            }

        }

        return false;


    }



    void inOrder(Node* root,ofstream& out)
    {
        if(nodeCount==0)
        {
            cout << "Empty Tree";
            out << "Empty Tree";
            return;
        }
        if(root==NULL)
        {
            return ;
        }

        inOrder(root->left,out);
        cout << root->data<< "  ";
        out << root->data << "  ";
        inOrder(root->right,out);

    }

    void InOrderTravarsal(ofstream& out)
    {
        inOrder(root,out);
        cout << endl;
        out << endl;
    }


    void preOrder(Node* root,ofstream &out)
    {
        if(nodeCount==0)
        {
            cout << "Empty Tree";
            out << "Empty Tree";
            return;
        }

        if(root==NULL )
        {
            return;
        }

        cout << root->data << "  ";
        out << root->data << "  ";
        preOrder(root->left,out);
        preOrder(root->right,out);
    }

    void PreOrderTravarsal(ofstream& out)
    {
        preOrder(root,out);
        cout << endl;
        out << endl;
    }

    void postOrder(Node* root,ofstream& out)
    {
        if(nodeCount==0)
        {
            cout << "Empty Tree";
            out << "Empty Tree";
            return;
        }
        if(root==NULL)
        {
            return;
        }
        postOrder(root->left,out);
        postOrder(root->right,out);
        cout << root->data << "  ";
        out << root->data << "  ";

    }

    void PostOrderTravarsal(ofstream& out)
    {
        postOrder(root,out);
        cout << endl;
        out << endl;
    }

    void print()
    {
        print(root);
        cout << endl;
    }

    void print(Node* root)
    {
        if(nodeCount==0)
        {
            cout << "Empty Tree";
            return;
        }
        if(root==NULL)
        {
            return;
        }
        cout << root->data << " ";
        if(root->left==NULL && root->right==NULL)
            return;
        cout<< "(";
        print(root->left);
        cout << ") ";
        cout<< "(";
        print(root->right);
        cout << ") ";

    }


    void write(Node* root,ofstream &out)
    {
        if(nodeCount==0)
        {
            out << "Empty Tree";
            return;
        }
        if(root==NULL)
        {
            return;
        }
        out << root->data << " ";
        if(root->left==NULL && root->right==NULL)
            return;
        out<< "(";
        write(root->left,out);
        out << ") ";
        out<< "(";
        write(root->right,out);
        out << ") ";

    }

    void write(ofstream &out)
    {

        write(root,out);
        out<< endl;
    }





};
