#ifndef BINARYTREESTRUCT_H
#define BINARYTREESTRUCT_H

#include <algorithm>
#include <iostream>

using std::cout;
using std::max;

template <class T>
struct binaryTreeNode {
    T info;
    binaryTreeNode<T> llink;
    binaryTreeNode<T> rlink;
};

template <class T>
int height(const binaryTreeNode<T> *p) {
    if (p == NULL) {
        return 0;
    } else {
        return 1 + max(height(p->llink), height(p->rlink));
    }
}

template <class T>
void copyTree(binaryTreeNode<T> *&copiedTreeRoot,
              const binaryTreeNode<T> *otherTreeRoot) {
    if (otherTreeRoot == NULL) {
        copiedTreeRoot = NULL;
    } else {
        copiedTreeRoot = new binaryTreeNode<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
}

template <class T>
void inorder(const binaryTreeNode<T> *p) {
    if (p != NULL) {
        inorder(p->llink);
        cout << p->info << ' ';
        inorder(p->rlink);
    }
}

template <class T>
void preorder(const binaryTreeNode<T> *p) {
    if (p != NULL) {
        cout << p->info << ' ';
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class T>
void postorder(const binaryTreeNode<T> *p) {
    if (p != NULL) {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << ' ';
    }
}

#endif
