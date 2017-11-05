// The Dictionary abstract class.  Class Compare compares
// two keys. Class getKey gets a key from an element.
template <class Key, class Elem, class Comp, class getKey>
class  Dictionary {
public:
  // Reinitialize dictionary
  virtual void clear() = 0;

  // Insert an element.  Return true if insert is
  // successful, false otherwise.
  virtual bool insert(const Elem&) = 0;

  // Remove some element matching Key.  Return true if such
  // exists, false otherwise.  If multiple entries match
  // Key, an arbitrary one is removed.
  virtual bool remove(const Key&, Elem&) = 0;

  // Remove and return an arbitrary element from dictionary.
  // Return true if some element is found, false otherwise.
  virtual bool removeAny(Elem&) = 0;

  // Return a copy of some element matching Key.  Return
  // true if such exists, false otherwise.  If multiple
  // elements match Key, return an arbitrary one.
  virtual bool find(const Key&, Elem&) const = 0;

  // Return the number of elements in the dictionary.
  virtual int size() = 0;
};
