#include <stdio.h>
#include <stdlib.h>
#include "traversalBT.h"

treeNode* makeRootNode(elelment data, treeNode*leftNode, treeNode* rightNode){
    treeNode* root = (treeNode*)malloc(sizeod(treeNode));
    root->data = data;
    root->left = leftNode;
    root->right = rightNode;
    return root;
}

void perorder(treeNode* root){
    if (root){
        printf("%c", root->data);
        perorder(root->left);
        perorder(root->right);
    }
}

void inorder(treeNode* root){
    if (root){
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
    }
}

void postorder(treeNode* root){
    if (root){
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

