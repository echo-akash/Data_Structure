//final
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int flag=0;
class node
{
public:
    int item;
    node *left;
    node *right;
    node *parent;

    node(int n)
    {
        item=n;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};
class tree
{
    node *root;
public:
    //node *root;

    tree()
    {
        root=NULL;
        root= new node(5);
        node *node1=new node(3);
        node *node2=new node(4);
        node *node3=new node(7);
        node *node4=new node(9);
        node *node5=new node(11);
        node *node6=new node(2);

        root->left=node1;
        root->right=node4;
        node1->right=node2;
        node1->left=node6;
        node4->left=node3;
        node4->right=node5;
        node1->parent=root;
        node4->parent=root;
        node2->parent=node1;
        node6->parent=node1;
        node3->parent=node4;
        node5->parent=node4;
    }

    void inorder(node *n)
    {
        if(n==NULL)/// mane leaf er jnno left e NULL pabe. so then terminate krbe
        {
            return;
        }
        inorder(n->left);
        cout<<n->item<<" ";
        inorder(n->right);

    }

    void inorder()///used whn the root is private
    {
        inorder(root);/// function overloading used
        cout<<endl;
    }

    void preorder(node* n)
    {
        if(n==NULL) return;
        cout<<n->item<<" ";
        preorder(n->left);
        preorder(n->right);
    }

    void preorder()
    {
        preorder(root);
        cout<<endl;
    }

    void postorder(node* n)
    {
        if(n==NULL) return;
        postorder(n->left);
        postorder(n->right);
        cout<<n->item<<" ";
    }

    void postorder()
    {
        postorder(root);
        cout<<endl;
    }

    node* treeSearch(node *n, int key)
    {
        while(n!=NULL && key!=n->item)
        {
            if(key<n->item) n=n->left;
            else n=n->right;
        }
        return n;
    }

    node* treeSearch(int key)
    {
        treeSearch(root, key);
    }

    node* treeSearch2(node* n, int key)
    {
        if(n==NULL || key==n->item) return n;
        if(key<n->item) return treeSearch2(n->left,key);
        else return treeSearch2(n->right,key);
    }

    node* treeSearch2(int key)
    {
        treeSearch2(root, key);
    }

    node* treeInsert(int n)
    {
        node *newNode= new node(n);
        node* y;
        node* x;
        y=NULL;
        x=root;
        while(x!=NULL)
        {
            y=x;
            if(newNode->item<x->item) x=x->left;
            else x=x->right;
        }
        newNode->parent=y;
        if(y==NULL)///means the tree is empty
        {
            root=newNode;
        }
        else if(newNode->item<y->item) y->left=newNode;
        else y->right=newNode;
        return newNode;
    }

    node* treeInsert2(node* nod, int n)
    {

        node* newNode=new node(n);
        if(root==NULL)
        {
            root=newNode;
            return newNode;
        }
        if(n<nod->item)
        {
            if(nod->left!=NULL)
                treeInsert2(nod->left,n);
            else
            {
                nod->left=newNode;
                return newNode;
            }

        }
        else
        {
            if(nod->right!=NULL)
                treeInsert2(nod->right,n);
            else
            {
                nod->right=newNode;
                return newNode;
            }

        }


    }

    node* treeInsert2(int key)
    {
        treeInsert2(root,key);
    }

    node* treeMinimum(node* n)
    {
        while(n->left!=NULL) n=n->left;
        return n;
    }
    node* treeMinimum()
    {
        treeMinimum(root);
    }
    node* treeMaximum(node* n)
    {
        while(n->right!=NULL)
            n=n->right;
        return n;
    }
    node* treeMaximum()
    {
        treeMaximum(root);
    }

    node* Delete(node *root, int key)
    {
//        if(this->root==NULL) return NULL;
//        if(this->root->left==NULL && this->root->right!=NULL)
//        {
//            if(this->root->item!=data && this->root->right->item!=data)
//            {
//                flag=0;
//                return NULL;
//            }
//        }
//        if(this->root->right==NULL && this->root->left!=NULL)
//        {
//            if(this->root->item!=data && this->root->left->item!=data)
//            {
//                flag=0;
//                return NULL;
//            }
//        }
//        if(this->root->item==data && this->root->left==NULL && this->root->right==NULL)
//        {
//            flag=1;
//            this->root=NULL;
//            return NULL;
//        }
////        if(this->root->item==data)
////        {
////            this->root=NULL;
////            return root;
////        }
//
//
//        if(root == NULL) return root;
//        else if(data < root->item) root->left = Delete(root->left,data);
//        else if(data > root->item) root->right = Delete(root->right, data);
//        else
//        {
//            /// No Child
//            flag=1;
//            if(root->left == NULL && root->right == NULL)
//            {
//                delete root;
//                root = NULL;
//
//            }
//            /// one child
//            else if(root->left == NULL)
//            {
//                node *temp = root;
//                root = root->right;
//                delete temp;
//            }
//            else if(root->right == NULL)
//            {
//                node *temp = root;
//                root = root->left;
//                delete temp;
//            }
//            else
//            {
//                node *temp = treeMinimum(root->right);
//                root->item = temp->item;
//                root->right = Delete(root->right, temp->item);
//            }
//        }
//        return root;

        if (root == NULL)
            return root;
        else if (key < root->item)
            root->left = Delete(root->left, key);
        else if (key > root->item)
            root->right = Delete(root->right, key);
        else
        {
            if (root->left == NULL)
            {
                node *temp = root->right;
                delete []temp;
                return temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root->left;
                delete []temp;
                return temp;
            }
        node* temp = treeMinimum(root->right);
            root->item = temp->item;
            root->right = Delete(root->right, temp->item);
        }
        return root;


    }

    bool Delete(int n)
    {
//        if(treeDelete(root,n)!=NULL) return true;
//        else return false;
        if(Delete(root,n)==NULL || flag==0) return false;
        else return true;
    }

    void transplant(node *u,node *v)
    {
        if(u->parent==NULL) root=v;
        else if(u==u->parent->left) u->parent->left=v;
        else u->parent->right=v;
        if(v!=NULL) v->parent =u->parent;
    }
    int dlt(int s)
    {
        node *z=new node(0);
        node *y=new node(0);
        z=treeSearch(s);
        if(z==NULL) return -1;
        if(z->left==NULL) transplant(z,z->right);
        else if(z->right==NULL) transplant(z,z->left);
        else
        {
            y=treeMinimum(z->right);
            if(y->parent!=z)
            {
               transplant(y,y->right);
               y->right=z->right;
               y->right->parent=y;
            }
            else {
                transplant(z,y);
                y->left=z->left;
                y->left->parent=y;
            }
        }
        return s;
    }

    int Height(struct node* nod)
    {
//        struct node* nod;
//        nod=root;
        if (nod==NULL)
            return 0;
        else
        {
            ///depth of the subtrees
            int lDepth = Height(nod->left);
            int rDepth = Height(nod->right);

            if (lDepth >= rDepth)
                return(lDepth+1);
            else return(rDepth+1);
        }
    }
    int Height()
    {
        Height(root);
    }

    int rangeSearch(int leftmost, int rightmost, node* nod)
    {
        int a=0;
        if(nod==NULL) return 0;
        if(nod->item>=leftmost && nod->item<=rightmost)
        {
                //cout<<nod->item<<" ";
                a+=rangeSearch(leftmost,rightmost,nod->left);
                cout<<nod->item<<" ";
                a+=rangeSearch(leftmost,rightmost,nod->right);
                //cout<<nod->item<<" ";
                return a+1;
        }
        else if(nod->item<leftmost)
        {
            a+=rangeSearch(leftmost,rightmost,nod->right);
            return a;
        }

        else if(nod->item>rightmost)
        {
             a+=rangeSearch(leftmost,rightmost,nod->left);
            return a;
        }
       // cout<<endl;

    }
    int rangeSearch(int leftmost, int rightmost)
    {
        return rangeSearch(leftmost, rightmost, root);
    }

    int rangeSearch2(int l1,int r1, int l2, int r2)
    {
        int a,b,ans;

        if(l2<l1 && r2>r1)
        {
            a=rangeSearch(l2,r2);
            ans= a;
        }
        else if(l1<l2 && r1>r2)
        {
            a=rangeSearch(l1,r1);
            ans=a;
        }

        else if(r1>l2)
        {
            a=rangeSearch(l2,r1);
            b=rangeSearch(l1,r1);
            b+=rangeSearch(l2,r2);
            ans=b-a;
        }
        else if(l2<l1 && r2<r1)
        {
            a=rangeSearch(l1,r2);
            b=rangeSearch(l2,r2);
            b+=rangeSearch(l1,r1);
            ans=b-a;
        }

        else if(r1<l2)
        {
            a=rangeSearch(l1,r1);
            b=rangeSearch(l2,r2);
            ans=a+b;
        }
        return ans;
    }

    void findLCA (int i1,int i2)
    {
        if (root == NULL)
            return;
        node * curr = root;
        node * curr1 = root;
        int m=-1;
        while (1)
        {
            if (curr->item == curr1->item)
                m=curr1->item;
            if (curr == NULL || curr1 == NULL)
                break;
            if (curr->item > i1)
                curr=curr->left;
            else if (curr->item < i1)
                curr=curr->right;
            else
                break;
            if (curr1->item > i2)
                curr1=curr1->left;
            else if (curr1->item < i2)
                curr1=curr1->right;
            else
                break;
            if (curr->item != curr1->item)
                break;
        }
        cout << m << endl;
    }


    int isBST(node* node)
    {
        if (node == NULL)
        return 1;
        if (node->left!=NULL && treeMaximum(node->left)->item > node->item)
        return -1;
        if (node->right!=NULL && treeMinimum(node->right)->item < node->item)
        return -1;
        if (!isBST(node->left) || !isBST(node->right))
        return -1;
    return 1;
    }

    int issbst()
    {
        if(isBST(root)==1)
            return 1;
        else
            return -1;
    }
};

int main()
{
    tree t;
    //int ans=0;
    //int flag=0;
    //t.inorder(t.root);
    t.inorder();
    t.preorder();
    t.postorder();
    while(1)
    {
        printf("1. Inorder 2. Preorder 3. Postorder 4. search 5. insert\n");
        printf("6.recursiveSearch 7.  RecursiveInsert 8. Maximum 9. Minimum\n");
        printf("10. Delete 11. Height 12. rangeSearch 13. rangeSearch2 14.Exit 15.IsBst\n");
        int choice;
        cin>>choice;
        if(choice==1) t.inorder();
        else if(choice==2) t.preorder();
        else if(choice==3) t.postorder();
        else if(choice==4)
        {
            int n;
            cout<<"enter the node to search: ";
            cin>>n;
            if(t.treeSearch(n)!=NULL) cout<<"FOUND "<<n<<endl;
            else cout<<n<<" NOT FOUND"<<endl;
        }
        else if(choice==5)
        {
            cout<<"what to insert: ";
            int a;
            cin>>a;
            if(t.treeInsert(a)!=NULL) cout<<a<<" has been inserted"<<endl;
            else cout<<"could not insert"<<endl;
            t.inorder();
        }
        else if(choice==6)
        {
            int n;
            cout<<"enter the node to search: ";
            cin>>n;
            if(t.treeSearch2(n)!=NULL) cout<<"FOUND "<<n<<endl;
            else cout<<n<<" NOT FOUND"<<endl;
        }
        else if(choice==7)
        {
            cout<<"what to insert: ";
            int a;
            cin>>a;
            if(t.treeInsert2(a)!=NULL) cout<<a<<" has been inserted"<<endl;
            else cout<<"could not insert"<<endl;
            t.inorder();
        }

        else if(choice==8)
        {
            if(t.treeMaximum()!=NULL) cout<<t.treeMaximum()->item<<endl;
        }
        else if(choice==9)
        {
            if(t.treeMinimum()!=NULL) cout<<t.treeMinimum()->item<<endl;
        }
        else if(choice==10)
        {
            int a;
            cout<<"What to delete: ";
            cin>>a;
            int ans=t.dlt(a);
            if(ans==-1) cout<<"could not delete"<<endl;
            else cout<<a<<" has been deleted"<<endl;
//            if(t.Delete(a)) cout<<a<<" has been deleted"<<endl;
//            else cout<<"Could not delete"<<endl;
            t.inorder();
        }
        else if(choice==11)
        {
            cout<<t.Height()<<endl;
        }
        else if(choice==12)
        {
            int leftmost,rightmost;
            cin>>leftmost>>rightmost;
            int ans=t.rangeSearch(leftmost,rightmost);
            cout<<endl<<ans<<endl;
        }
        else if(choice==13)
        {
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            int ans=t.rangeSearch2(l1,r1,l2,r2);
            cout<<endl<<ans<<endl;
        }
        else if(choice==14)
        {
        return 0;
        }
        else if(choice==15)
        {
            if(t.issbst()==1)
            cout<<"Its BST\n";
            else
            cout<<"Its not BST\n";
        }
    }
}
