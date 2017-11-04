#ifndef _SPLAY_TREE_HPP_
#define _SPLAY_TREE_HPP_

#include <iomanip>
#include <iostream>
using namespace std;

template <class T>
class SplayTreeNode{
    public:
        T key;                // �ؼ���(��ֵ)
        SplayTreeNode *left;    // ����
        SplayTreeNode *right;    // �Һ���


        SplayTreeNode():left(NULL),right(NULL) {}

        SplayTreeNode(T value, SplayTreeNode *l, SplayTreeNode *r):
            key(value), left(l),right(r) {}
};

template <class T>
class SplayTree {
    private:
        SplayTreeNode<T> *mRoot;    // �����

    public:
        SplayTree();
        ~SplayTree();

        // ǰ�����"��չ��"
        void preOrder();
        // �������"��չ��"
        void inOrder();
        // �������"��չ��"
        void postOrder();

        // (�ݹ�ʵ��)����"��չ��"�м�ֵΪkey�Ľڵ�
        SplayTreeNode<T>* search(T key);
        // (�ǵݹ�ʵ��)����"��չ��"�м�ֵΪkey�Ľڵ�
        SplayTreeNode<T>* iterativeSearch(T key);

        // ������С��㣺������С���ļ�ֵ��
        T minimum();
        // ��������㣺���������ļ�ֵ��
        T maximum();

        // ��תkey��Ӧ�Ľڵ�Ϊ���ڵ㣬������ֵΪ���ڵ㡣
        void splay(T key);

        // �����(keyΪ�ڵ��ֵ)���뵽��չ����
        void insert(T key);

        // ɾ�����(keyΪ�ڵ��ֵ)
        void remove(T key);

        // ������չ��
        void destroy();

        // ��ӡ��չ��
        void print();
    private:

        // ǰ�����"��չ��"
        void preOrder(SplayTreeNode<T>* tree) const;
        // �������"��չ��"
        void inOrder(SplayTreeNode<T>* tree) const;
        // �������"��չ��"
        void postOrder(SplayTreeNode<T>* tree) const;

        // (�ݹ�ʵ��)����"��չ��x"�м�ֵΪkey�Ľڵ�
        SplayTreeNode<T>* search(SplayTreeNode<T>* x, T key) const;
        // (�ǵݹ�ʵ��)����"��չ��x"�м�ֵΪkey�Ľڵ�
        SplayTreeNode<T>* iterativeSearch(SplayTreeNode<T>* x, T key) const;

        // ������С��㣺����treeΪ��������չ������С��㡣
        SplayTreeNode<T>* minimum(SplayTreeNode<T>* tree);
        // ��������㣺����treeΪ��������չ��������㡣
        SplayTreeNode<T>* maximum(SplayTreeNode<T>* tree);

        // ��תkey��Ӧ�Ľڵ�Ϊ���ڵ㣬������ֵΪ���ڵ㡣
        SplayTreeNode<T>* splay(SplayTreeNode<T>* tree, T key);

        // �����(z)���뵽��չ��(tree)��
        SplayTreeNode<T>* insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z);

        // ɾ����չ��(tree)�еĽ��(��ֵΪkey)�������ر�ɾ���Ľ��
        SplayTreeNode<T>* remove(SplayTreeNode<T>* &tree, T key);

        // ������չ��
        void destroy(SplayTreeNode<T>* &tree);

        // ��ӡ��չ��
        void print(SplayTreeNode<T>* tree, T key, int direction);
};

/* 
 * ���캯��
 */
template <class T>
SplayTree<T>::SplayTree():mRoot(NULL)
{
}

/* 
 * ��������
 */
template <class T>
SplayTree<T>::~SplayTree() 
{
    destroy(mRoot);
}

/*
 * ǰ�����"��չ��"
 */
template <class T>
void SplayTree<T>::preOrder(SplayTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        cout<< tree->key << " " ;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

template <class T>
void SplayTree<T>::preOrder() 
{
    preOrder(mRoot);
}

/*
 * �������"��չ��"
 */
template <class T>
void SplayTree<T>::inOrder(SplayTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        inOrder(tree->left);
        cout<< tree->key << " " ;
        inOrder(tree->right);
    }
}

template <class T>
void SplayTree<T>::inOrder() 
{
    inOrder(mRoot);
}

/*
 * �������"��չ��"
 */
template <class T>
void SplayTree<T>::postOrder(SplayTreeNode<T>* tree) const
{
    if(tree != NULL)
    {
        postOrder(tree->left);
        postOrder(tree->right);
        cout<< tree->key << " " ;
    }
}

template <class T>
void SplayTree<T>::postOrder() 
{
    postOrder(mRoot);
}

/*
 * (�ݹ�ʵ��)����"��չ��x"�м�ֵΪkey�Ľڵ�
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::search(SplayTreeNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::search(T key) 
{
    return search(mRoot, key);
}

/*
 * (�ǵݹ�ʵ��)����"��չ��x"�м�ֵΪkey�Ľڵ�
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::iterativeSearch(SplayTreeNode<T>* x, T key) const
{
    while ((x!=NULL) && (x->key!=key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

template <class T>
SplayTreeNode<T>* SplayTree<T>::iterativeSearch(T key)
{
    return iterativeSearch(mRoot, key);
}

/* 
 * ������С��㣺����treeΪ��������չ������С��㡣
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::minimum(SplayTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T SplayTree<T>::minimum()
{
    SplayTreeNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}
 
/* 
 * ��������㣺����treeΪ��������չ��������㡣
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::maximum(SplayTreeNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T SplayTree<T>::maximum()
{
    SplayTreeNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return (T)NULL;
}


/* 
 * ��תkey��Ӧ�Ľڵ�Ϊ���ڵ㣬������ֵΪ���ڵ㡣
 *
 * ע�⣺
 *   (a)����չ���д���"��ֵΪkey�Ľڵ�"��
 *          ��"��ֵΪkey�Ľڵ�"��תΪ���ڵ㡣
 *   (b)����չ���в�����"��ֵΪkey�Ľڵ�"������key < tree->key��
 *      b-1 "��ֵΪkey�Ľڵ�"��ǰ���ڵ���ڵĻ�����"��ֵΪkey�Ľڵ�"��ǰ���ڵ���תΪ���ڵ㡣
 *      b-2 "��ֵΪkey�Ľڵ�"��ǰ���ڵ���ڵĻ�������ζ�ţ�key�������κμ�ֵ��С����ô��ʱ������С�ڵ���תΪ���ڵ㡣
 *   (c)����չ���в�����"��ֵΪkey�Ľڵ�"������key > tree->key��
 *      c-1 "��ֵΪkey�Ľڵ�"�ĺ�̽ڵ���ڵĻ�����"��ֵΪkey�Ľڵ�"�ĺ�̽ڵ���תΪ���ڵ㡣
 *      c-2 "��ֵΪkey�Ľڵ�"�ĺ�̽ڵ㲻���ڵĻ�������ζ�ţ�key�������κμ�ֵ������ô��ʱ�������ڵ���תΪ���ڵ㡣
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::splay(SplayTreeNode<T>* tree, T key)
{
    SplayTreeNode<T> N, *l, *r, *c;

    if (tree == NULL) 
        return tree;

    N.left = N.right = NULL;
    l = r = &N;

    for (;;)
    {
        if (key < tree->key)
        {
            if (tree->left == NULL)
                break;
            if (key < tree->left->key)
            {
                c = tree->left;                           /* rotate right */
                tree->left = c->right;
                c->right = tree;
                tree = c;
                if (tree->left == NULL) 
                    break;
            }
            r->left = tree;                               /* link right */
            r = tree;
            tree = tree->left;
        }
        else if (key > tree->key)
        {
            if (tree->right == NULL) 
                break;
            if (key > tree->right->key) 
            {
                c = tree->right;                          /* rotate left */
                tree->right = c->left;
                c->left = tree;
                tree = c;
                if (tree->right == NULL) 
                    break;
            }
            l->right = tree;                              /* link left */
            l = tree;
            tree = tree->right;
        }
        else
        {
            break;
        }
    }

    l->right = tree->left;                                /* assemble */
    r->left = tree->right;
    tree->left = N.right;
    tree->right = N.left;

    return tree;
}

template <class T>
void SplayTree<T>::splay(T key)
{
    mRoot = splay(mRoot, key);
}

/* 
 * �������뵽��չ���У������ظ��ڵ�
 *
 * ����˵����
 *     tree ��չ���ĸ����
 *     key ����Ľ��ļ�ֵ
 * ����ֵ��
 *     ���ڵ�
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::insert(SplayTreeNode<T>* &tree, SplayTreeNode<T>* z)
{
    SplayTreeNode<T> *y = NULL;
    SplayTreeNode<T> *x = tree;

    // ����z�Ĳ���λ��
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else
        {
            cout << "�����������ͬ�ڵ�(" << z->key << ")!" << endl;
            delete z;
            return tree;
        }
    }

    if (y==NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;

    return tree;
}

template <class T>
void SplayTree<T>::insert(T key)
{
    SplayTreeNode<T> *z=NULL;

    // ����½����ʧ�ܣ��򷵻ء�
    if ((z=new SplayTreeNode<T>(key,NULL,NULL)) == NULL)
        return ;

    // ����ڵ�
    mRoot = insert(mRoot, z);
    // ���ڵ�(key)��תΪ���ڵ�
    mRoot = splay(mRoot, key);
}

/* 
 * ɾ�����(�ڵ�ļ�ֵΪkey)�����ظ��ڵ�
 *
 * ����˵����
 *     tree ��չ���ĸ����
 *     key ��ɾ�����ļ�ֵ
 * ����ֵ��
 *     ���ڵ�
 */
template <class T>
SplayTreeNode<T>* SplayTree<T>::remove(SplayTreeNode<T>* &tree, T key)
{
    SplayTreeNode<T> *x;

    if (tree == NULL) 
        return NULL;

    // ���Ҽ�ֵΪkey�Ľڵ㣬�Ҳ����Ļ�ֱ�ӷ��ء�
    if (search(tree, key) == NULL)
        return tree;

    // ��key��Ӧ�Ľڵ���תΪ���ڵ㡣
    tree = splay(tree, key);

    if (tree->left != NULL)
    {
        // ��"tree��ǰ���ڵ�"��תΪ���ڵ�
        x = splay(tree->left, key);
        // �Ƴ�tree�ڵ�
        x->right = tree->right;
    }
    else
        x = tree->right;

    delete tree;

    return x;

}

template <class T>
void SplayTree<T>::remove(T key)
{
    mRoot = remove(mRoot, key);
}

/* 
 * ������չ��
 */
template <class T>
void SplayTree<T>::destroy(SplayTreeNode<T>* &tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy(tree->left);
    if (tree->right != NULL)
        destroy(tree->right);

    delete tree;
}

template <class T>
void SplayTree<T>::destroy()
{
    destroy(mRoot);
}

/*
 * ��ӡ"��չ��"
 *
 * key        -- �ڵ�ļ�ֵ 
 * direction  --  0����ʾ�ýڵ��Ǹ��ڵ�;
 *               -1����ʾ�ýڵ������ĸ���������;
 *                1����ʾ�ýڵ������ĸ������Һ��ӡ�
 */
template <class T>
void SplayTree<T>::print(SplayTreeNode<T>* tree, T key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree�Ǹ��ڵ�
            cout << setw(2) << tree->key << " is root" << endl;
        else                // tree�Ƿ�֧�ڵ�
            cout << setw(2) << tree->key << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right,tree->key,  1);
    }
}

template <class T>
void SplayTree<T>::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->key, 0);
}
#endif