#ifndef BINARYTREEADT_H
#define BINARYTREEADT_H

#include <iostream>

using std::cout;

template <class T>
struct binaryTreeNode {
    T info;
    binaryTreeNode<T> *llink;
    binaryTreeNode<T> *rlink;
};

template <class T>
class binaryTreeType {
   public:
    // Overload the assignment operator
    const binaryTreeType<T> &operator=(const binaryTreeType<T> &);

    // Returns true if the binary tree is empty. Otherwise returns false.
    bool isEmpty() const;

    // Function to do an inorder traversal fo the binary tree.
    void inorderTraversal() const;
    // Function to do an preorder traversal fo the binary tree.
    void preorderTraversal() const;
    // Function to do an postorder traversal fo the binary tree.
    void postorderTraversal() const;

    // Returns the height of the binary tree.
    int treeHeight() const;
    // Returns the number of nodes in the binary tree.
    int treeNodeCount() const;
    // Returns the number of leaves in the binary tree.
    int treeLeavesCount() const;
    // Deallocates the memory space occupied by the binary tree.
    void destroyTree();

    // Copy constructor
    binaryTreeType(const binaryTreeType<T> &);

    // Default constructor
    binaryTreeType();

    // Destructor
    virtual ~binaryTreeType();

   protected:
    binaryTreeNode<T> *root;

   private:
    // Makes a copy of the binary tree to which otherTreeRoot points. The
    // pointer copiedTreeRoot points to the root of the copied binary tree.
    void copyTree(binaryTreeNode<T> *&copiedTreeRoot,
                  const binaryTreeNode<T> *otherTreeRoot);

    // Function to destroy the binary tree to which p points.
    // Postcondition: p = NULL;
    void destroy(binaryTreeNode<T> *&p);

    // Function to do an inorder traversal of the binary tree to which p points.
    void inorder(const binaryTreeNode<T> *p) const;
    // Function to do a preorder traversal of the binary tree to which p points.
    void preorder(const binaryTreeNode<T> *p) const;
    // Function to do a postorder traversal of the binary tree to which p
    // points.
    void postorder(const binaryTreeNode<T> *p) const;

    // Function to return the height of the binary tree to which p points.
    int height(const binaryTreeNode<T> *p) const;
    // Returns the larger of x and y;
    int max(int x, int y) const;
    // Function to return the number of nodes in the binary tree to which p
    // points.
    int nodeCount(const binaryTreeNode<T> *p) const;
    // Function to return the number of leaves in the binary tree to which p
    // points.
    int leavesCount(const binaryTreeNode<T> *p) const;
};

template <class T>
const binaryTreeType<T> &binaryTreeType<T>::operator=(
    const binaryTreeType<T> &p) {
    if (this != p) {
        if (root != NULL) {
            destory(root);
        }
        if (p.root == NULL) {
            root = NULL;
        }
    } else {
        copyTree(this, p.root);
    }

    return *this;
}

template <class T>
bool binaryTreeType<T>::isEmpty() const {
    return (root == NULL);
}

template <class T>
void binaryTreeType<T>::inorderTraversal() const {
    return inorder(root);
}

template <class T>
void binaryTreeType<T>::preorderTraversal() const {
    return preorder(root);
}

template <class T>
void binaryTreeType<T>::postorderTraversal() const {
    return postorder(root);
}

template <class T>
int binaryTreeType<T>::treeHeight() const {
    return height(root);
}

template <class T>
int binaryTreeType<T>::treeNodeCount() const {
    return nodeCount(root);
}

template <class T>
int binaryTreeType<T>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class T>
void binaryTreeType<T>::destroyTree() {
    destroy(root);
}

template <class T>
binaryTreeType<T>::binaryTreeType(const binaryTreeType<T> &otherTree) {
    if (otherTree.root == NULL) {
        root = NULL;
    } else {
        copyTree(root, otherTree.root);
    }
}

template <class T>
binaryTreeType<T>::~binaryTreeType() {
    destroyTree();
}

template <class T>
void binaryTreeType<T>::copyTree(binaryTreeNode<T> *&copiedTreeRoot,
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
void binaryTreeType<T>::destroy(binaryTreeNode<T> *&p) {
    if (p != NULL) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class T>
void binaryTreeType<T>::inorder(const binaryTreeNode<T> *p) const {
    if (p != NULL) {
        inorder(p->llink);
        cout << p->info << ' ';
        inorder(p->rlink);
    }
}

template <class T>
void binaryTreeType<T>::preorder(const binaryTreeNode<T> *p) const {
    if (p != NULL) {
        cout << p->info << ' ';
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class T>
void binaryTreeType<T>::postorder(const binaryTreeNode<T> *p) const {
    if (p != NULL) {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << ' ';
    }
}

template <class T>
int binaryTreeType<T>::height(const binaryTreeNode<T> *p) const {
    if (p != NULL) {
        return 1 + max(height(p->llink), height(p->rlink));
    } else {
        return 0;
    }
}

template <class T>
int binaryTreeType<T>::max(int x, int y) const {
    return (x >= y) ? x : y;
}

template <class T>
int binaryTreeType<T>::nodeCount(const binaryTreeNode<T> *p) const {
    if (p != NULL) {
        return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
    } else {
        return 0;
    }
}

template <class T>
int binaryTreeType<T>::leavesCount(const binaryTreeNode<T> *p) const {
    if (p != NULL) {
        if (height(p) == 0) {
            return 1;
        } else {
            return leavesCount(p->llink) + leavesCount(p->rlink);
        }
    } else {
        return 0;
    }
}

#endif
