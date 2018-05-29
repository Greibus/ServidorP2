//
// Created by tony on 09/05/18.
//

#include "AVLTree.h"


// Height of AVL Tree

template <class T>
int AVLTree<T>::height(avlNode<T> *temp)
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

template <class T>
int AVLTree<T>::diff(avlNode<T> *temp)
{
    int lHeight = height (temp->left);
    int rHeight = height (temp->right);
    int bFactor= lHeight - rHeight;
    return bFactor;
}


// Right- Right Rotation

template <class T>
avlNode<T> *AVLTree<T>::rrRotation(avlNode<T> *parent)
{
    avlNode<T> *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

// Left- Left Rotation

template <class T>
avlNode<T> *AVLTree<T>::llRotation(avlNode<T> *parent)
{
    avlNode<T> *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}


// Left - Right Rotation

template <class T>
avlNode<T> *AVLTree<T>::lrRotation(avlNode<T> *parent)
{
    avlNode<T> *temp;
    temp = parent->left;
    parent->left = rrRotation (temp);
    return llRotation (parent);
}


// Right- Left Rotation

template <class T>
avlNode<T> *AVLTree<T>::rlRotation(avlNode<T> *parent)
{
    avlNode<T> *temp;
    temp = parent->right;
    parent->right = llRotation (temp);
    return rrRotation (parent);
}


// Balancing AVL Tree

template <class T>
avlNode<T> *AVLTree<T>::balance(avlNode<T> *temp)
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

template <class T>
avlNode<T> *AVLTree<T>::insert(avlNode<T> *root, T value) {
    if (root == NULL) {
        root = new avlNode<T>;
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
        root = balance (root);
    }
    else if (value >= root->data) {
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

// Display AVL Tree

template <class T>
void AVLTree<T>::display(avlNode<T> *ptr, T level)
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

template <class T>
void AVLTree<T>::inorder(avlNode<T> *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

// Preorder Traversal of AVL Tree

template <class T>
void AVLTree<T>::preorder(avlNode<T> *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);

}

//  Postorder Traversal of AVL Tree

template <class T>
void AVLTree<T>::postorder(avlNode<T> *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}
