/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

class BST
{
    private:
        int data;
    public:
    BST *root;          //Only for obj which hold root
    BST *left;
    BST *right;
    int get_data()
    {
        return data;
    }
    BST(int data_arg=0)
    {
        data=data_arg;
        left=NULL;
        right=NULL;
        root=NULL;
    }
    BST *BST_init(int data=0)
    {
        BST *root=new BST(data);
        root=root;
        return root;
    }
    
    BST *BST_addNode(BST *root,int data)
    {
        if(root == NULL)
        {
            BST *node= new BST(data);
            return node;
        }
        if(data > root->data)
        {
            root->right=BST_addNode(root->right,data);
        }
        else
        {
            root->left=BST_addNode(root->left,data);
        }
        return root;
    }
    
    void print_BST_inorder(BST *root)
    {
        if(root == NULL)
        {
            return;
        }
        print_BST_inorder(root->left);
        cout<<" "<<root->data;
        print_BST_inorder(root->right);
    }
    
    void print_BST_preorder(BST *root)               // Use inorder to print BST in sorted Way
    {
        if(root == NULL)
        {
            return;
        }
        cout<<" "<<root->data;
        print_BST_preorder(root->left);
        print_BST_preorder(root->right);
    }
    void print_BST_postorder(BST *root)                 // Use post order mechanisam to Delete Tree
    {
        if(root == NULL)
        {
            return;
        }
        print_BST_postorder(root->left);
        print_BST_postorder(root->right);
        cout<<" "<<root->data;
    }
    ~BST()
    {
        destroyBST(root);
        cout<<"\nDestructor called";
    }
    BST *delete_node(BST *root,int value);
    BST *findMinimum(BST *root);
    BST *findMaximum(BST *root);
    BST *destroyBST(BST *root);
};

BST * BST::destroyBST(BST *root)
{
       if(root == NULL)
        {
            return NULL;
        }
        destroyBST(root->left);
        destroyBST(root->right);
        delete root;
        root=NULL;
        return root;
}
BST* BST::delete_node(BST *root,int value)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(value > root->data)
    {
        root->right=delete_node(root->right,value);
    }
    else if(value < root->data)
    {
        root->left=delete_node(root->left,value);
    }
    else if(value == root-> data )
    {
        if(root->left == NULL && root->right == NULL )          // If it is leaf Node
        {
            delete root;
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL )          // If node has left end null
        {
            BST *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->left != NULL && root->right == NULL )          // If node has right end null
        {
            BST *temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left != NULL && root->right != NULL )          // If both ends are not null
        {
            /*
              Find Minumum Value from right side or Find Max value from left
              Replace Minumum/Maximum data with the deleting Node 
              Then delete the Node
            */
            BST *temp=findMinimum(root->right);
            root->data=temp->data;
            root->right=delete_node(root->right,temp->data);
           
        }
        
    }
    return root;
}

BST * BST::findMinimum(BST *root)
{
    while(root->left != NULL)
    {
        root=root->left;
    }
    return root;
}

BST * BST::findMaximum(BST *root)
{
    while(root->right != NULL)
    {
        root=root->right;
    }
    return root;
}

int main()
{
    BST obj;
    BST *root = NULL;
    root=obj.BST_init(6);
    obj.BST_addNode(root,4);
    obj.BST_addNode(root,2);
    obj.BST_addNode(root,5);
    obj.BST_addNode(root,1);
    obj.BST_addNode(root,3);
    obj.BST_addNode(root,7);
    obj.BST_addNode(root,8);
    obj.BST_addNode(root,9);
    cout<<"Inorder "<<endl;
    obj.print_BST_inorder(root);
    obj.delete_node(root,6);            // delete single Node, Node selection depends on Value
    cout<<"Inorder "<<endl;
    obj.print_BST_inorder(root);        //  Inorder Prints in sorted array Format
    
    // obj.destroyBST(root);
    // obj.delete_node(root,6);
    // cout<<"Inorder "<<endl;
    // cout<<"\n Pre order "<<endl;
    //  obj.print_BST_preorder(root);        //
    // cout<<"\n Post order "<<endl;
    // obj.print_BST_postorder(root);       // Post order traverse From Leaf Nodes, Used to destroy BST
    // cout<<"\n Min Number Tree"<<endl;
    // cout<<" "<< obj.findMinimum(root)->get_data()<<endl;
    // cout<<"\n Min Number right sub Tree";
    // cout<<" "<< obj.findMinimum(root->right)->get_data()<<endl;

    return 0;
}




