// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

struct abc
{
  int data;
  struct abc *left,*right;
};
struct abc* insert(struct abc*,int );
struct abc*create(int );
struct abc*search(struct abc*,int );
void inorder(struct abc*);
struct abc*delete(struct abc*,int );
int inorderS(struct abc*);
void main()
{
    int ch,d,y;
    struct abc *root=NULL;
    do
    {
    printf("Enter choice:\n");
    printf("1.insert\n2.search\n3.inorder\n4.delete\n");
    scanf("%d",&ch);
    switch(ch)
    {
       
        case 1:
        printf("Enter data to insert:\n");
        scanf("%d",&d);
        root= insert(root,d);
        break;

        case 2:
        printf("Enter data to search:\n");
        scanf("%d",&d);
        search(root,d);
        break;
       
        case 3:
        printf("Tree traversal:\n");
        inorder(root);
        break;
       
        case 4:
        /* printf("Enter data to be deleted :\n");
         scanf("%d",&d);*/
         delete(root,d);
         break;
    }
    printf("Do you want to continue?(0/1)\n");
    scanf("%d",&y);
    }
    while(y==1);
   
   
}
struct abc*insert(struct abc*root,int d)
{  
    if(root == NULL) //if n node is there
    {
        return create(d);
    }
    else if(d< root->data)  //if data is greater than root data
    {
    root->left = insert(root->left,d);
    }
    else
    {
    root->right=insert(root->right,d); //if data is less than root data
    }
    return root;
   
}
   
struct abc* create(int d)
{
    struct abc*new;
    new=(struct abc*)malloc(sizeof(struct abc));
    new->data=d;
    new->left=NULL;
    new->right=NULL;
    return new;
   
}
void inorder(struct abc*root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        if(root!=NULL)
        {
            inorder(root->left);
        }
        printf("%d\n",root->data);
        inorder(root->right);
    }
}
   
struct abc*search(struct abc*root,int d)
{
    if(root==NULL) //if root is NULL
    {
        return root;
       
    }
    else if (d== root->data){
        printf("\nData is found !!!\n"); //if entered data is same as root data
    }
   
        else if(d < root->data)
        {
            root->left =search(root->left,d); //if data is less than root data
        }
       else
       {
       
           root->right =search(root->right,d); //if data is greater than root data
       }
       

    }

   
    struct abc*delete(struct abc*root,int d)
    {
        if(root==NULL)
        {
            return root;
        }
        else if(d < root->data)
        {
        root->left=delete(root->left,d);
        }
        else if(d > root->data)
        {
        root->right =delete(root->right,d);
        }
       
        else{
            if(root->right==NULL)
            {
                struct abc*temp;
                temp=root->left;
                free(root);
                return temp;
            }
           
           else if(root->left == NULL)
           {
                struct abc*temp;
                temp=root->right;
                free(root);
                return temp;
            }
           
            else
            {
                struct abc *temp;
                temp=root->right;
                root->data=inorderS(temp);
                root->right=delete(root->right,root->data);
            }
            return root;
           
        }
    }
  
   int inorderS(struct abc *temp)
{
    while(temp && temp->left!=NULL)
    temp=temp->left;
    return temp->data;
}
