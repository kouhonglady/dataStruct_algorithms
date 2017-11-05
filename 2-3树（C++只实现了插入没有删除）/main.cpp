// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition" by Clifford A. Shaffer, Prentice Hall, 2007.
// Source code Copyright (C) 2006 by Clifford A. Shaffer.

// Partial implementation for 2-3 Trees

#include <iostream>
using namespace std;

#include "book.h"

// Include comparator functions
#include "compare.h"

#include "tt.h"

// Warning: This has horrible memory leaks.
// Everytime it does a remove to "it",
// the next time "it" gets used, that previous
// Int object gets clobbered.
int main()
{
  TTTree<int, Int*, intintCompare, getIntsKey > tree;
  Int* it;

  cout << "Size: " << tree.size() << "\n";
  tree.insert(new Int(100));
  tree.print();
  cout << "Size: " << tree.size() << "\n";
  tree.remove(10, it);
  tree.print();
  cout << "Size: " << tree.size() << "\n";
  tree.clear();
  cout << "Size: " << tree.size() << "\n";
  tree.insert(new Int(15));
  cout << "Size: " << tree.size() << "\n";
  if (tree.find(20, it))
    cout << "Found " << it << endl;
  else cout << "No key 20\n";
  if (tree.find(15, it))
    cout << "Found " << it << endl;
  else cout << "No key 15\n";
  tree.print();
  if (tree.remove(20, it))
    cout << "Removed " << it << endl;
  else cout << "No key 20\n";
  cout << "Now, insert 20\n";
  tree.insert(new Int(20));
  tree.print();
  if (tree.remove(20, it))
    cout << "Removed " << it << endl;
  else cout << "No key 20\n";
  tree.print();
  tree.insert(new Int(700));
  cout << "Size: " << tree.size() << "\n";
  tree.print();
  tree.insert(new Int(350));
  tree.print();
  tree.insert(new Int(201));
  tree.print();
  tree.insert(new Int(170));
  tree.print();
  tree.insert(new Int(151));
  tree.print();
  tree.insert(new Int(190));
  tree.print();
  tree.insert(new Int(1000));
  tree.print();
  tree.insert(new Int(900));
  tree.print();
  tree.insert(new Int(950));
  tree.print();
  tree.insert(new Int(10));
  tree.print();
  if (tree.find(1000, it))
    cout << "Found " << it << endl;
  else cout << "No key 1000\n";
  if (tree.find(999, it))
    cout << "Found " << it << endl;
  else cout << "No key 999\n";
  if (tree.find(20, it))
    cout << "Found " << it << endl;
  else cout << "No key 20\n";
  cout << "Now do some delete tests.\n";
  if (tree.remove(15, it))
    cout << "Removed " << it << endl;
  else cout << "No key 15\n";
  tree.print();
  if (tree.remove(151, it))
    cout << "Removed " << it << endl;
  else cout << "No key 151\n";
  tree.print();
  if (tree.remove(151, it))
    cout << "Removed " << it << endl;
  else cout << "No key 151\n";
  if (tree.remove(700, it))
    cout << "Removed " << it << endl;
  else cout << "No key 700\n";
  tree.print();
  tree.clear();
  tree.print();
  cout << "Size: " << tree.size() << "\n";

  cout << "Finally, test iterator\n";
  tree.insert(new Int(3500));
  tree.insert(new Int(2010));
  tree.insert(new Int(1700));
  tree.insert(new Int(1510));
  tree.insert(new Int(1900));
  tree.insert(new Int(10000));
  tree.insert(new Int(9000));
  tree.insert(new Int(9500));
  tree.insert(new Int(100));
  tree.print();
  while (tree.removeAny(it))
    cout << it << " ";
  cout << "\n";
  return 0;
}
