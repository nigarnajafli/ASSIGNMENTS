fgets is a function that returns a line from a document
char* fgets (char* str, int num, FILE* stream );
implement a similar function
bool readLine(char* buf, int num, FILE* stream);
that writes a line into buf, and returns true if a line could be read or whole buffer got filled.
return false if no character is read.

Since all leaf nodes will exist in this binary tree, ie. it is a perfect tree,
It is relatively easy to parse it and build a tree data structure out of it. Build a binary tree from an input file and find the largest sum on the Largest-Sum-Path
from the root to one of the leaf nodes.
Modify source code from WEEK10 and use it as a library for solving the binary tree for largest sum to a leaf.