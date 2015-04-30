/* main operations 
 
    1. Find minimum
    2. Find maximum
    3. Insert an element
    4. Delete an element
    5. Finding an element
 */


#include<stdio.h>
#include<stdlib.h>

struct BinarySearchTreeNode{
    int data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
};

struct BinarySearchTreeNode * Find(struct BinarySearchTreeNode *,int );
struct BinarySearchTreeNode * FindNonRecursive(struct BinarySearchTreeNode *,int);
struct BinarySearchTreeNode * FindMin(struct BinarySearchTreeNode *);
struct BinarySearchTreeNode * FindMinNonRecursive(struct BinarySearchTreeNode *);
struct BinarySearchTreeNode * FindMax(struct BinarySearchTreeNode *);
struct BinarySearchTreeNode * FindMaxNonRecursive(struct BinarySearchTreeNode *);
void Insert(struct BinarySearchTreeNode **,int );
struct BinarySearchTreeNode * Delete(struct BinarySearchTreeNode *,int );
void printInorderBST(struct BinarySearchTreeNode *);
int main(){
    struct BinarySearchTreeNode *root = NULL;
    struct BinarySearchTreeNode *retRoot = NULL;
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. printBST\n");
    printf("4. Exit\n");
    int n;
    int data;
    while (1) {
        printf("Enter an option:");
        scanf("%d",&n);
        while ((n<=0)||(n>=5)) {
            printf("Enter a valid option:");
            scanf("%d",&n);
        }
        switch (n) {
            case 1:
                //insert
                printf("Enter a number to insert:");
                scanf("%d",&data);
                Insert(&root,data);
                break;
            case 2:
                //delete
                printf("Enter the number to delete:");
                scanf("%d",&data);
                retRoot = Delete(root,data);
                if (Find(root,data)) {
                    root = retRoot;
                }
                break;
            case 3:
                //print BST
                printInorderBST(root);
                break;
            default:
                printf("Exit\n");
                return 0;
                break;
        }
    }
    
    return 0;
}
void printInorderBST(struct BinarySearchTreeNode *root){
    if (root != NULL) {
        printInorderBST(root->left);
        printf(" %d ",root->data);
        printInorderBST(root->right);
    }
    return;
}
struct BinarySearchTreeNode * Delete(struct BinarySearchTreeNode *root,int data){
    struct BinarySearchTreeNode *temp = NULL;
    if (root == NULL) {
        //no such element exists
        printf("Element not there in the tree\n");
    }else if(data < root->data){
        root->left = Delete(root->left,data);
    }else if(data > root->data){
        root->right = Delete(root->right,data);
    }else{//element found
        if (root->left && root->right) {
            //replace with largest in left subtree
            temp = FindMax(root->left);
            //printf("dd%d\n",temp->data);

            root->data = temp->data;
            root->left= Delete(root->left,temp->data);
        }else{//one child
            temp = root;
            //printf("one child %d\n",root->data);
            if (root->left == NULL) {
                root = root->right;
            }else if (root->right == NULL) {
                root = root->left;
            }
            free(temp);
        }
    }
    return root;
}
//insert into BST
void Insert(struct BinarySearchTreeNode **root,int data){
    if ((*root)==NULL) {
        struct BinarySearchTreeNode *newNode = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        (*root) = newNode;
        return;
    }
    struct BinarySearchTreeNode *x = (*root);
    struct BinarySearchTreeNode *y = NULL;
    while (x != NULL) {
        y = x;
        if (data < x->data) {
            x = x->left;
        }else{
            x = x->right;
        }
    }
    struct BinarySearchTreeNode *newNode = (struct BinarySearchTreeNode *)malloc(sizeof(struct BinarySearchTreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    if (data < y->data) {
        y->left = newNode;
    }else{
        y->right = newNode;
    }
    return;
}
//find maximum non recursive
struct BinarySearchTreeNode * FindMaxNonRecursive(struct BinarySearchTreeNode * root){
    if (root == NULL) {
        return NULL;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
// find maximum recursive
struct BinarySearchTreeNode * FindMax(struct BinarySearchTreeNode *root){
    if (root == NULL) {
        return NULL;
    }else if(root->right == NULL){
        //printf("%d\n",root->data);

        return root;
    }else{
        return FindMax(root->right);
    }
}
// find minimum recursive
struct BinarySearchTreeNode * FindMin(struct BinarySearchTreeNode *root){
    if (root==NULL) {
        return NULL;
    }else if(root->left == NULL){
        return root;
    }else{
        return FindMin(root->left);
    }
}
//find minimum non recursive
struct BinarySearchTreeNode * FindMinNonRecursive(struct BinarySearchTreeNode *root){
    if (root==NULL) {
        return NULL;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
// recursive find
struct BinarySearchTreeNode * Find(struct BinarySearchTreeNode *root,int data){
    if ((root)==NULL) {
        return NULL;
    }
    if (data < root->data) {
        return Find(root->left,data);
    }else if(data > root->data){
        return Find(root->right,data);
    }
    return root;
}
//non recursive find
struct BinarySearchTreeNode * FindNonRecursive(struct BinarySearchTreeNode *root,int data){
    if (root==NULL) {
        return NULL;
    }
    while (root) {
        if (data == root->data) {
            return root;
        }else if(data > root->data){
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return NULL;
}

