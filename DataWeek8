#include <stdio.h>
#include <stdlib.h>
typedef struct BTREE{
int data;
struct node*left;
struct node*right;
}BTREE;
void preorder(BTREE *root){
if(root!=NULL){
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}
void inorder(BTREE *root){
if(root!=NULL){
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
    }
}
void postorder(BTREE *root){
if(root!=NULL){
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
    }
}
BTREE *new_node(int data){
BTREE *p=(BTREE*)malloc(sizeof(BTREE));
p->data=data;
p->left=NULL;
p->right=NULL;
return p;
}
BTREE *insert(BTREE*root,int data){
if(root!=NULL){
    if(data<root->data)
        root->left=insert(root->left,data);
    else
        root->right=insert(root->right,data);
    }
else
    root=new_node(data);
return root;
}
int size(BTREE*root){
if(root==NULL)
    return 0;
else
    return size(root->left)+1+size(root->right);
}
int height(BTREE *root){
if(root==NULL)
    return -1;
else{
    int lheight,rheight;
    lheight=height(root->left);
    rheight=height(root->right);
    if(rheight>lheight)
        return rheight+1;
    else
        return lheight+1;
    }
}
BTREE*delete_node(BTREE*root,int x){
BTREE *p,*q;
if(root==NULL)
    return NULL;
if(root->data==x){
    if(root->left==root->right){
        free(root);
        return NULL;
    }
    else{
        if(root->left==NULL){
            p=root->right;
            free(root);
            return p;
        }
        else if(root->right==NULL){
            p=root->left;
            free(root);
            return p;
        }
        else{
            p=q=root->right;
            while(p->left!=NULL)
                p=p->left;
            p->left=root->left;
            free(root);
            return q;
            }
        }
}
else if(root->data<x)
    root->right=delete_node(root->right,x);
else
    root->left=delete_node(root->left,x);
return root;
}
int minValue(BTREE*root){
if(root==NULL)
    return 0;
else
    while(root->left!=NULL)
    root=root->left;
return (root->data);
}
int maxValue(BTREE*root){
if(root==NULL)
    return 0;
else
    while(root->right!=NULL)
    root=root->right;
return (root->data);
}
int isSame(BTREE*a,BTREE*b){// aynı olup olmadıgını kontrol edıp true yada false dondurur
if(a==NULL&&b==NULL)
    return 1;
else if(a!=NULL&&b!=NULL)
    return (a->data==b->data&&isSame(a->left,b->left)&&isSame(a->right,b->right));
else
    return 0;
}
int path(BTREE*root,int x){//tum agacýn degerlerý toplamý verilen deger toplanýa esýt ýse true dondurur
int y;
if(root==NULL)
    return(x==0);//burda true yada false sekılde donduruyor
else{
    y=x-root->data;
    return(path(root->left,y)||path(root->right,y));// burda kod kontrol edıyor degerlrın toplamını esıtmı dıye
    }
}
BTREE *aramaYap(BTREE*root,int data){
if(root!=NULL){
    if(root->data==data)
        return root;
    else if(root->data > data)
        aramaYap(root->left,data);
    else
        aramaYap(root->right,data);
}
else
    return NULL;
}
int isBST(BTREE*root){
    if(root==NULL)
        return 1;
    else if(root->left!=NULL&&maxValue(root->left)>root->data)
        return 0;
    else if(root->right!=NULL&&minValue(root->right)<=root->data)
        return 0;
    else if(!isBST(root->left||!isBST(root->right)))
        return 0;
    else
        return 1;
}
BTREE *tekTest(BTREE*root,BTREE*root2){
if(root!=NULL){
    if(root->data%2==1)
        root2=insert(root2,root->data);
    root2=tekTest(root->left,root2);
    root2=tekTest(root->right,root2);
    }
return root2;
}
int findNumbersInLevel(BTREE*root, int level){ //A1
    if(root==NULL)
        return 0;
    if(level==0){
         return 1;
    }
    else{
        return findNumbersInLevel(root->left,level-1) + findNumbersInLevel(root->right,level-1);
    }
}

int main(){
BTREE *root=NULL;
BTREE *root2=NULL;

root=insert(root,15);
root=insert(root,14);
root=insert(root,13);
root=insert(root,12);
root=insert(root,11);
root=insert(root,10);
root=insert(root,28);

preorder(root);
printf("\n");

//root2=tekTest(root,root2);

//preorder(root2);
printf("\n");

printf("Level : %d ",findNumbersInLevel(root,1));

printf("\n");
printf("%d\n",size(root));
printf("%d\n",height(root));
printf("%d\n",minValue(root));
printf("%d\n",maxValue(root));

return 0;
}
