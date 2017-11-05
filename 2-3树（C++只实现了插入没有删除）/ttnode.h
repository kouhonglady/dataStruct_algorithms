template <typename Elem>
class TTNode {       // 2-3 tree node structure
public:
  Elem lval;         // The node's left record
  Elem rval;         // The node's right record
  TTNode* left;      // Pointer to left child
  TTNode* center;    // Pointer to middle child
  TTNode* right;     // Pointer to right child
  int keycount;      // Number of keys stored

  TTNode()
    { center = left = right = NULL; keycount = 0; }
  ~TTNode() { }
  bool isLeaf() { return left == NULL; }
};
