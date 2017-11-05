// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition" by Clifford A. Shaffer, Prentice Hall, 2007.
// Source code Copyright (C) 2006 by Clifford A. Shaffer.

// A collection of various macros, constants, and small functions
// used for the software examples.
#include <time.h>  // Used by timing functions

// Return true iff x is even
inline bool EVEN(int x) { return (x % 2) == 0; }

// Return true iff x is odd
inline bool ODD(int x) { return (x & 1) != 0; }

const int DefaultListSize = 10; // Lists, etc. default size

// Assert: If boolean expression is false, print a message
//   and terminate the program
void Assert(bool val, char* string) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << string << endl;
    exit(-1);
  }
}

// Swap two elements in a generic array
template<class Elem>
inline void swap(Elem A[], int i, int j) {
  Elem temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

// Random number generator functions

inline void Randomize() // Seed the generator
  { srand(1); }

// Return a random value in range 0 to n-1
inline int Random(int n)
  { return rand() % (n); }

// Big enough for simple testing
#define INFINITY 9999

// Timing variables and functions
unsigned tstart = 0;  // Time at beginning of timed section

// Initialize the program timer
void Settime() { tstart = (unsigned) clock(); }

// Return the elapsed time since the last call to Settime
double Gettime() {
  unsigned tcurr = (unsigned) clock();
  return (double)(tcurr - tstart)/(double)CLOCKS_PER_SEC;
}

// Your basic int type as an object.
class Int {
private:
  int val;
public:
  Int(int input=0) { val = input; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return val; }
  // Overload = to support Int foo = 5 syntax
  Int operator= (int input) { val = input; }
};

// Let us print out Ints easily
ostream& operator<<(ostream& s, const Int& i)
  { return s << i.key(); }
ostream& operator<<(ostream& s, const Int* i)
  { return s << i->key(); }
