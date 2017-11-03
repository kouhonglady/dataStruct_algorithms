/**
 * C++ ����: ������Ĳ���
 *
 */

#include <iostream>
#include "RBTree.h"
using namespace std;

int main()
{
    int a[]= {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int check_insert=0;    // "����"�����ļ�⿪��(0���رգ�1����)
    int check_remove=0;    // "ɾ��"�����ļ�⿪��(0���رգ�1����)
    int i;
    int ilen = (sizeof(a)) / (sizeof(a[0])) ;
    RBTree<int>* tree=new RBTree<int>();

    cout << "== ԭʼ����: ";
    for(i=0; i<ilen; i++)
        cout << a[i] <<" ";
    cout << endl;

    for(i=0; i<ilen; i++) 
    {
        tree->insert(a[i]);
        // ����check_insert=1,����"��Ӻ���"
        if(check_insert)
        {
            cout << "== ��ӽڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->print();
            cout << endl;
        }

    }

    cout << "== ǰ�����: ";
    tree->preOrder();

    cout << "\n== �������: ";
    tree->inOrder();

    cout << "\n== �������: ";
    tree->postOrder();
    cout << endl;

    cout << "== ��Сֵ: " << tree->minimum() << endl;
    cout << "== ���ֵ: " << tree->maximum() << endl;
    cout << "== ������ϸ��Ϣ: " << endl;
    tree->print();

    // ����check_remove=1,����"ɾ������"
    if(check_remove)
    {
        for(i=0; i<ilen; i++)
        {
            tree->remove(a[i]);

            cout << "== ɾ���ڵ�: " << a[i] << endl;
            cout << "== ������ϸ��Ϣ: " << endl;
            tree->print();
            cout << endl;
        }
    }

    // ���ٺ����
    tree->destroy();

    return 0;
}