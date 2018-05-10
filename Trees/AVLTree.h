//
// Created by tony on 09/05/18.
//

#ifndef SERVIDORPROYECTO2_AVLTREE_H
#define SERVIDORPROYECTO2_AVLTREE_H


#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))
using namespace std;


// Node Declaration

struct avlNode
{
    int data;
    struct avlNode *left;
    struct avlNode *right;
}*root;


// Class Declaration

class AVLTree
{
public:
    int height(avlNode *);
    int diff(avlNode *);
    avlNode *rrRotation(avlNode *);
    avlNode *llRotation(avlNode *);
    avlNode *lrRotation(avlNode *);
    avlNode *rlRotation(avlNode *);
    avlNode* balance(avlNode *);
    avlNode* insert(avlNode *, int );
    void display(avlNode *, int);
    void inorder(avlNode *);
    void preorder(avlNode *);
    void postorder(avlNode *);
    AVLTree()
    {
        root = NULL;
    }
};


// Height of AVL Tree

int AVLTree::height(avlNode *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int lHeight = height (temp->left);
        int rHeight = height (temp->right);
        int max_height = max (lHeight, rHeight);
        h = max_height + 1;
    }
    return h;
}


// Height Difference

int AVLTree::diff(avlNode *temp)
{
    int lHeight = height (temp->left);
    int rHeight = height (temp->right);
    int bFactor= lHeight - rHeight;
    return bFactor;
}


// Right- Right Rotation

avlNode *AVLTree::rrRotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation

avlNode *AVLTree::llRotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


// Left - Right Rotation

avlNode *AVLTree::lrRotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->left;
    parent->left = rrRotation (temp);
    return llRotation (parent);
}


// Right- Left Rotation

avlNode *AVLTree::rlRotation(avlNode *parent)
{
    avlNode *temp;
    temp = parent->right;
    parent->right = llRotation (temp);
    return rrRotation (parent);
}


// Balancing AVL Tree

avlNode *AVLTree::balance(avlNode *temp)
{
    int balFactor = diff (temp);
    if (balFactor > 1)
    {
        if (diff (temp->left) > 0)
            temp = llRotation (temp);
        else
            temp = lrRotation (temp);
    }
    else if (balFactor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rlRotation (temp);
        else
            temp = rrRotation (temp);
    }
    return temp;
}


// Insert Element into the tree

avlNode *AVLTree::insert(avlNode *root, int value)
{
    if (root == NULL)
    {
        root = new avlNode;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data)
    {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data)
    {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}


// Display AVL Tree

void AVLTree::display(avlNode *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        printf("n");
        if (ptr == root)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}


// Inorder Traversal of AVL Tree

void AVLTree::inorder(avlNode *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

// Preorder Traversal of AVL Tree

void AVLTree::preorder(avlNode *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}


//  Postorder Traversal of AVL Tree

void AVLTree::postorder(avlNode *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}



#endif //SERVIDORPROYECTO2_AVLTREE_H
