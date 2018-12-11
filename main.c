#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int height;
    struct node*left;
    struct node*right;
};
typedef struct node AVLTREE;
int height(AVLTREE *N){
    if (N == NULL)
        return -1;
    return N->height;
}
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int getBalance(AVLTREE*N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
AVLTREE*min(AVLTREE* node){
    AVLTREE* x = node;
    while (x->left != NULL)
        x = x->left;
    return x;
}
AVLTREE* newNode(int key){
    AVLTREE*node= (AVLTREE*)malloc(sizeof(AVLTREE));
    node->data= key;
    node->left= NULL;
    node->right= NULL;
    node->height= 0;  // new node is initially added at leaf
    return(node);
}
AVLTREE*rightRotate(AVLTREE*y){
    AVLTREE*x = y->left;
    AVLTREE*z = x->right;

    // Perform rotation
    x->right = y;
    y->left = z;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}
AVLTREE*leftRotate(AVLTREE*x){
    AVLTREE*y = x->right;
    AVLTREE*z = y->left;

    // Perform rotation
    y->left = x;
    x->right = z;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}
AVLTREE* insert(AVLTREE* node, int data){
    // 1.  Perform the normal BST insertion
    if (node == NULL)
        return(newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Equal keys are not allowed in BST
        return node;
    // 2. Update height of this ancestor node
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBalance(node);
    // If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    // Left Right Case
    if (balance > 1 && data > node->left->data){
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    if (balance < -1 && data < node->right->data){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    /* return the (unchanged) node pointer */
    return node;
}
AVLTREE* deleteNode(AVLTREE*root,int data){
if(root==NULL)
    return root;
if(data<root->data)
    root->left=deleteNode(root->left,data);
else if(data>root->data)
    root->right=deleteNode(root->right,data);
else{
    if((root->left==NULL)||(root->right==NULL)){//Silinecek veri kontrol ediliyor!!
        AVLTREE*temp=root->left ? root->left:root->right;
        // Eger cocuk yoksa temp NULL degerini alýyor fakat bir cocuk varsa,cocuk temp'e ataniyor!!
        if(temp==NULL){
            temp=root;
            root=NULL;
            }
        else
            *root=*temp;
        free(temp);
        }
    else{
        AVLTREE*temp=min(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
        }
    }
if(root==NULL)
    return root;
root->height=1+max(height(root->left),height(root->right));

int balance=getBalance(root);

if(balance>1&&getBalance(root->left)>=0)
    return rightRotate(root);
if(balance>1&&getBalance(root->left)<0){
    root->left=leftRotate(root->left);
    return rightRotate(root);
}
if(balance<-1&&getBalance(root->right)<=0)
    return leftRotate(root);
if(balance<-1&&getBalance(root->right)>0){
    root->right=rightRotate(root->right);
    return leftRotate(root);
}
return root;
}
void preOrder(AVLTREE*root){
    if(root != NULL)
    {

        preOrder(root->left);
        printf("%d ", root->data);
        preOrder(root->right);
    }
}

int main(){
AVLTREE *agac=NULL;
	int key,secim;
	printf("Veri giriniz... Cikis icin -1 basiniz..");
	scanf("%d",&key);
	while(key!=-1){
		agac=insert(agac,key);
		scanf("%d",&key);
	}
	do{
		printf("\n1-Insert\n2-Height\n3 Preorder\n4-Exit\nSeciminiz..?");
		scanf("%d",&secim);
		switch(secim){
			case 1:
				printf("Veri giriniz..");
				scanf("%d",&key);
				agac=insert(agac,key);
				printf("Veri Eklendi...");
				break;
			case 2:
				//printf("Height=%d",height(agac));
				printf("Height=%d",agac->height);
				break;
			case 3:
				preOrder(agac);
				break;
			case 4:
				exit(1);
			default:
				printf("Hatali Secim...");
				break;
		}
	}while(1);
	return 0;
}
