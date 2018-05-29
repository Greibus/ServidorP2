//
// Created by tony on 09/05/18.
//

#include "BTree.h"


/* creating new node */
template<class T>
btreeNode<T> *BTree<T>::createNode(T val, btreeNode<T> *child) {
    btreeNode<T> *newNode = new btreeNode<T>;
    newNode->val[1] = val;
    newNode->count = 1;
    newNode->link[0] = roots;
    newNode->link[1] = child;
    return newNode;
}

/* Places the value in appropriate position */
template<class T>
void BTree<T>::addValToNode(T val, int pos, btreeNode<T> *node, btreeNode<T> *child) {
    int j = node->count;
    while (j > pos) {
        node->val[j + 1] = node->val[j];
        node->link[j + 1] = node->link[j];
        j--;
    }
    node->val[j + 1] = val;
    node->link[j + 1] = child;
    node->count++;
}

/* split the node */
template<class T>
void BTree<T>::splitNode(T val, T *pval, int pos, btreeNode<T> *node,
                         btreeNode<T> *child, btreeNode<T> **newNode) {
    int median, j;

    if (pos > MIN) {
        median = MIN + 1;
    } else {
        median = MIN;
    }

    *newNode = new btreeNode<T>;
    j = median + 1;
    while (j <= MAX) {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }
    node->count = median;
    (*newNode)->count = MAX - median;

    if (pos <= MIN) {
        addValToNode(val, pos, node, child);
    }
    else {
        addValToNode(val, pos - median, *newNode, child);
    }
    *pval = node->val[node->count];
    (*newNode)->link[0] = node->link[node->count];
    node->count--;
}

/* sets the value val in the node */
template<class T>
int BTree<T>::setValueInNode(T val, T *pval,btreeNode<T> *node, btreeNode<T> **child) {

    int pos;
    if (!node) {
        *pval = val;
        *child = NULL;
        return 1;
    }

    if (val < node->val[1]) {
        pos = 0;
    }
    else {
        for (pos = node->count;
             (val < node->val[pos] && pos > 1); pos--);
        if (val == node->val[pos]) {
            cout<<"Duplicates not allowed\n";
            return 0;
        }
    }
    if (setValueInNode(val, pval, node->link[pos], child)) {
        if (node->count < MAX) {
            addValToNode(*pval, pos, node, *child);
        }
        else {
            splitNode(*pval, pval, pos, node, *child, child);
            return 1;
        }
    }
    return 0;
}

/* insert val in B-Tree */
template<class T>
void BTree<T>::insertion(T val) {
    int flag, i;
    btreeNode<T> *child;

    flag = setValueInNode(val, &i, roots, &child);
    if (flag)
        roots = createNode(i, child);
}

/* copy successor for the value to be deleted */
template<class T>
void BTree<T>::copySuccessor(btreeNode<T> *myNode, int pos) {
    btreeNode<T> *dummy;
    dummy = myNode->link[pos];

    for (; dummy->link[0] != NULL;)
        dummy = dummy->link[0];
    myNode->val[pos] = dummy->val[1];
}

/* removes the value from the given node and rearrange values */
template<class T>
void BTree<T>::removeVal(btreeNode<T> *myNode, int pos) {
    int i = pos + 1;
    while (i <= myNode->count) {
        myNode->val[i - 1] = myNode->val[i];
        myNode->link[i - 1] = myNode->link[i];
        i++;
    }
    myNode->count--;
}

/* shifts value from parent to right child */
template<class T>
void BTree<T>::doRightShift(btreeNode<T> *myNode, int pos) {
    btreeNode<T> *x = myNode->link[pos];
    int j = x->count;

    while (j > 0) {
        x->val[j + 1] = x->val[j];
        x->link[j + 1] = x->link[j];
        j--;

    }
    x->val[1] = myNode->val[pos];
    x->link[1] = x->link[0];
    x->count++;

    x = myNode->link[pos - 1];
    myNode->val[pos] = x->val[x->count];
    myNode->link[pos] = x->link[x->count];
    x->count--;
}

/* shifts value from parent to left child */
template<class T>
void BTree<T>::doLeftShift(btreeNode<T> *myNode, int pos) {
    int j = 1;
    btreeNode<T> *x = myNode->link[pos - 1];

    x->count++;
    x->val[x->count] = myNode->val[pos];
    x->link[x->count] = myNode->link[pos]->link[0];

    x = myNode->link[pos];
    myNode->val[pos] = x->val[1];
    x->link[0] = x->link[1];
    x->count--;

    while (j <= x->count) {
        x->val[j] = x->val[j + 1];
        x->link[j] = x->link[j + 1];
        j++;
    }
}

/* merge nodes */
template<class T>
void BTree<T>::mergeNodes(btreeNode<T> *myNode, int pos) {
    int j = 1;
    btreeNode<T> *x1 = myNode->link[pos], *x2 = myNode->link[pos - 1];

    x2->count++;
    x2->val[x2->count] = myNode->val[pos];
    x2->link[x2->count] = myNode->link[0];

    while (j <= x1->count) {
        x2->count++;
        x2->val[x2->count] = x1->val[j];
        x2->link[x2->count] = x1->link[j];
        j++;
    }

    j = pos;
    while (j < myNode->count) {
        myNode->val[j] = myNode->val[j + 1];
        myNode->link[j] = myNode->link[j + 1];
        j++;
    }
    myNode->count--;
    free(x1);
}

/* adjusts the given node */
template<class T>
void BTree<T>::adjustNode(btreeNode<T> *myNode, int pos) {
    if (!pos) {
        if (myNode->link[1]->count > MIN) {
            doLeftShift(myNode, 1);
        }
        else {
            mergeNodes(myNode, 1);
        }
    }
    else {
        if (myNode->count != pos) {
            if (myNode->link[pos - 1]->count > MIN) {
                doRightShift(myNode, pos);
            }
            else {
                if (myNode->link[pos + 1]->count > MIN) {
                    doLeftShift(myNode, pos + 1);
                }
                else {
                    mergeNodes(myNode, pos);
                }
            }
        }
        else {
            if (myNode->link[pos - 1]->count > MIN)
                doRightShift(myNode, pos);
            else
                mergeNodes(myNode, pos);
        }
    }
}

/* delete val from the node */
template<class T>
int BTree<T>::delValFromNode(T val,btreeNode<T> *myNode) {
    int pos, flag = 0;
    if (myNode) {
        if (val < myNode->val[1]) {
            pos = 0;
            flag = 0;
        }
        else {
            for (pos = myNode->count;
                 (val < myNode->val[pos] && pos > 1); pos--);
            if (val == myNode->val[pos]) {
                flag = 1;
            }
            else {
                flag = 0;
            }
        }
        if (flag) {
            if (myNode->link[pos - 1]) {
                copySuccessor(myNode, pos);
                flag = delValFromNode(myNode->val[pos], myNode->link[pos]);
                if (flag == 0) {
                    cout<<"Given data is not present in B-Tree\n";
                }
            }
            else {
                removeVal(myNode, pos);
            }
        }
        else {
            flag = delValFromNode(val, myNode->link[pos]);
        }
        if (myNode->link[pos]) {
            if (myNode->link[pos]->count < MIN)
                adjustNode(myNode, pos);
        }
    }
    return flag;
}

/* delete val from B-tree */
template<class T>
void BTree<T>::deletion(T val,btreeNode<T> *myNode) {
    btreeNode<T> *tmp;
    if (!delValFromNode(val, myNode)) {
        cout<<"Given value is not present in B-Tree\n";
        return;
    }
    else {
        if (myNode->count == 0) {
            tmp = myNode;
            myNode = myNode->link[0];
            free(tmp);
        }
    }
    roots = myNode;
    return;
}

/* search val in B-Tree */
template<class T>
void BTree<T>::searching(T val, int *pos,btreeNode<T> *myNode) {
    if (!myNode) {
        return;
    }

    if (val < myNode->val[1]) {
        *pos = 0;
    }
    else {
        for (*pos = myNode->count;
             (val < myNode->val[*pos] && *pos > 1); (*pos)--);
        if (val == myNode->val[*pos]) {
            cout << "Given data is Found\n";
            return;
        }
    }
    searching(val, pos, myNode->link[*pos]);
    return;
}

//* B-Tree Traversal */
//template<class T>
//void BTree<T>::traversal(btreeNode<T> *myNode) {
//    int i;
//    if (myNode) {
//        for (i = 0; i < myNode->count; i++) {
//            traversal(myNode->link[i]);
//            cout<< myNode->val[i + 1]<<' ';
//        }
//        traversal(myNode->link[i]);
//    }
//}
