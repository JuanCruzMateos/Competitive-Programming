/*
106. Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given:
inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*/

/*
Success Details:
Runtime: 16 ms, faster than 56.00% of C online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
Memory Usage: 12 MB, less than 20.00% of C online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 8

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize);
void crearArbol(struct TreeNode** T, int* inorder, int inorderSize, int* postorder, int postorderSize);
int getIndexOf(int arr[], int x);
void inOrder(struct TreeNode* T);

int main()
{
    struct TreeNode* T;
    int inorder[DIM] = {1,3,4,5,19,13,12,14};
    int postorder[DIM] = {1,4,5,3,13,14,12,19};
    int inorderSize = 8;
    int postorderSize = 8;

//    T = buildTree(inorder, inorderSize, postorder, postorderSize);
//    inOrder(T);
//    T = NULL;
    crearArbol(&T, inorder, inorderSize, postorder, postorderSize);
    inOrder(T);

    return 0;
}

void inOrder(struct TreeNode* T) {

    if (T != NULL) {
        inOrder(T->left);
        printf("%d ", T->val);
        inOrder(T->right);
    }
}

void crearArbol(struct TreeNode** T, int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int p;

    if (inorderSize != 0) {
        *T = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        (*T)->val = postorder[postorderSize-1];
        (*T)->left = (*T)->right = NULL;
        p = getIndexOf(inorder, (*T)->val);
        crearArbol(&((*T)->left) , inorder, p, postorder, p);
        crearArbol(&((*T)->right), inorder + p + 1, inorderSize - p - 1, postorder + p, inorderSize - p - 1);
    }
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    struct TreeNode* T;
    int p;

    if (inorderSize == 0 || postorderSize == 0)
        return NULL;
    else {
        T = (struct TreeNode*) malloc(sizeof(struct TreeNode));
        T->val = postorder[postorderSize-1];
        p = getIndexOf(inorder, T->val);
        T->left  = buildTree(inorder, p, postorder, p);
        T->right = buildTree(inorder + p + 1, inorderSize - p - 1, postorder + p, inorderSize - p - 1);
    }
    return T;
}


int getIndexOf(int arr[], int x) {
    int i = 0;

    while (arr[i] != x)
        i += 1;
    return i;
}
