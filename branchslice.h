#include <iostream>
#include <vector>
using namespace std;

// this function sorts items in the initial list by value
// requires: list of item masses, list of item values
// returns: nothing
void sortbyvalue (vector<int> &mass, vector<int> &value);

// this function finds a maximum value among itself and its descendants
// works recursively. descends if there are positions in witch to descend
// disinherite descendant if it goes beyond backpack limits
// requires: list of item masses, list of item values, current set of inclusions, size limit
// returns: largest value among itself and its descendants
int getmaxsplice (vector<int> &mass, vector<int> &value, vector<bool> inclusion, int limit);

// this function works like GETMAXSPLICE but has a maximum amount of items limitation
// it is not guarantied to find an exact maximum but serves as a faster alternative
// requires: list of item masses, list of item values, current set of inclusions, size limit, max count
// returns: largest value among itself and its descendants
int getnsplice (vector<int> &mass, vector<int> &value, vector<bool> inclusion, int limit, int m);
