// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition" by Clifford A. Shaffer, Prentice Hall, 2007.
// Source code Copyright (C) 2006 by Clifford A. Shaffer.

// 2-3 tree class implementation

#include "dictionary.h"

#include "ttnode.h"

// 2-3 Tree implementation for the Dictionary ADT
template <typename Key, typename Elem, typename Comp, typename getKey>
class TTTree : public Dictionary<Key, Elem, Comp, getKey> {
private:
  TTNode<Elem>* root;          // Root of the tree
  int reccount;          // Number of records stored
  // Private "helper" functions
  void clearhelp(TTNode<Elem>*)                // Helper functions
    { cout << "Clearhelp not yet defined\n"; }
  bool inserthelp(TTNode<Elem>*&, const Elem&, Elem&, TTNode<Elem>*&);
  void splitnode(TTNode<Elem>* root, const Elem& inval, TTNode<Elem>*inptr,
                               Elem& retval, TTNode<Elem>*& retptr);
  bool findhelp(TTNode<Elem>*, const Key&, Elem&) const;
  void printhelp(TTNode<Elem>*, int) const;
public:
  TTTree() { root = NULL; reccount = 0; }
  ~TTTree() { clearhelp(root); }

  void clear()
    { clearhelp(root);  root = NULL; reccount = 0; }

  bool insert(const Elem& e) { // Insert node with value val
    Elem retval;               // Smallest value in newly created node
    TTNode<Elem>* retptr = NULL; // Newly created node
    bool isSuccess = inserthelp(root, e, retval, retptr);
    if (retptr != NULL) {      // Root overflowed: make new root
      TTNode<Elem>* temp = new TTNode<Elem>; temp->lval = retval;
      temp->left = root; temp->center = retptr;
      root = temp; root->keycount = 1;
    }
    if (isSuccess) reccount++;
    return isSuccess;
  }

  bool remove(const Key& K, Elem& e) {
    cout << "Remove not implemented\n";
    return false;
  }

  bool removeAny(Elem& e) {
    cout << "RemoveAny not implemented\n";
    return false;
  }

  bool find(const Key& K, Elem& e) const
    { return findhelp(root, K, e); }

  int size() { return reccount; }

  void print() const {
    cout << "Print tree: \n";
    if (root == NULL) cout << "The 2-3 Tree is empty.\n";
    else printhelp(root, 0);
  }
};


// Print out a 2-3 Tree
template <typename Key, typename Elem, typename Comp, typename getKey>
void TTTree<Key, Elem, Comp, getKey>::
printhelp(TTNode<Elem>* root, int level) const 
{
  if (root == NULL) return;
  for (int i=0; i<level; i++) cout << "   "; // indent
  cout << root->lval;
  if (root->keycount == 2)
    cout << "  " << root->rval << "\n";
  else cout << "\n";
  printhelp(root->left, level+1);
  printhelp(root->center, level+1);
  if (root->keycount == 2)
    printhelp(root->right, level+1);
}

// Insert an Elem into the 2-3 tree.  Root is the current
// node, e is the Elem to be inserted, retval and retptr are
// return values for promoted element and child node when
// current node is split. 
template <typename Key, typename Elem, typename Comp, typename getKey>
bool TTTree<Key, Elem, Comp, getKey>::
inserthelp(TTNode<Elem>*& root, const Elem& e,
           Elem& retval, TTNode<Elem>*& retptr) 
{
  Elem myretv;  TTNode<Elem>* myretp = NULL; // local copies
  Key eKey = getKey::key(e); // The key being inserted
  if (root == NULL)          // Empty tree: make new node
    { root = new TTNode<Elem>(); root->lval = e; root->keycount = 1; }
  else if (root->isLeaf())   // At leaf node: insert here
    if (root->keycount == 1) { // There's room for the record
      if (Comp::gt(eKey, getKey::key(root->lval)))
        root->rval = e;
      else
        {root->rval = root->lval; root->lval = e; }
      root->keycount = 2;
    }
    else splitnode(root, e, NULL, retval, retptr);
  else if (Comp::lt(eKey, getKey::key(root->lval)))
    inserthelp(root->left, e, myretv, myretp);  // To child
  else if ((root->keycount == 1) ||
           (Comp::lt(eKey, getKey::key(root->rval))))
    inserthelp(root->center, e, myretv, myretp);
  else inserthelp(root->right, e, myretv, myretp);
  if (myretp != NULL) // Child split: receive promoted value
    if (root->keycount == 2) // Full: split
      splitnode(root, myretv, myretp, retval, retptr);
    else { // Not full: add to this node
      if (Comp::lt(getKey::key(myretv),
                   getKey::key(root->lval))) {
        root->rval = root->lval;
        root->lval = myretv;
        root->right = root->center;
        root->center = myretp;
      }
      else { root->rval = myretv; root->right = myretp; }
      root->keycount = 2;
    }
  return true;
}

// Split a node in 2-3 tree.  Root is node being split,
// e is the Elem being inserted, inptr is child node
// being added (if root is an internal node), retval and
// retptr are the promoted value and child, respectively.
template <typename Key, typename Elem, typename Comp, typename getKey>
void TTTree<Key, Elem, Comp, getKey>::
splitnode(TTNode<Elem>* root, const Elem& e,
          TTNode<Elem>*inptr, Elem& retval,
          TTNode<Elem>*& retptr) 
{
  retptr = new TTNode<Elem>();  // Node created by split
  if (Comp::lt(getKey::key(e), getKey::key(root->lval))) {
    // Add at left
    retval = root->lval;  root->lval = e;
    retptr->lval = root->rval;
    retptr->left = root->center;
    retptr->center = root->right;
    root->center = inptr;
  }
  else if (Comp::lt(getKey::key(e),
                    getKey::key(root->rval))) { // Center
    retval = e;  retptr->lval = root->rval;
    retptr->left = inptr;
    retptr->center = root->right;
  }
  else { // Add at right
    retval = root->rval;  retptr->lval = e;
    retptr->left = root->right;
    retptr->center = inptr;
  }
  root->keycount = retptr->keycount = 1;
}

// Find the record in a 2-3 tree that matches a given key value
template <typename Key, typename Elem, typename Comp, typename getKey>
bool TTTree<Key, Elem, Comp, getKey>::
findhelp(TTNode<Elem>* root, const Key& K, Elem& e) const 
{
  if (root == NULL) return false;         // value not found
  if (Comp::eq(K, getKey::key(root->lval)))
    { e = root->lval; return true; }         // Found it
  if ((root->keycount == 2) &&
      (Comp::eq(K, getKey::key(root->rval))))
    { e = root->rval; return true; }         // Found it
  if (Comp::lt(K, getKey::key(root->lval)))  // Go left
    return findhelp(root->left, K, e);
  else if (root->keycount == 1)              // 2 child
    return findhelp(root->center, K, e);     // Center
  else if (Comp::lt(K, getKey::key(root->rval)))
    return findhelp(root->center, K, e);     // Center
  else return findhelp(root->right, K, e);   // Right
}
