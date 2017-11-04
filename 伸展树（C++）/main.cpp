/**
 * C++ ����: ��չ��
 *
 */

#include <iostream>
#include "splay_tree.h"
using namespace std;

static int arr[]= {10,50,40,30,20,60};
#define TBL_SIZE(a) ( (sizeof(a)) / (sizeof(a[0])) )

int main()
{
    int i,ilen;
    SplayTree<int>* tree=new SplayTree<int>();

    cout << "== �������: ";
    ilen = TBL_SIZE(arr);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    cout << "\n== ǰ�����: ";
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

    i = 30;
    cout << "\n== ��ת�ڵ�(" << i << ")Ϊ���ڵ�";
    tree->splay(i);
    cout << "\n== ������ϸ��Ϣ: " << endl;
    tree->print();

    // ���ٶ�����
    tree->destroy();

    return 0;
}