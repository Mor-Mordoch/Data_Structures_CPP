#if 0

most STL containers use the iterator (to point at the memory addresses). If we iterate a container using iterator
and not via simple for loop, there is a way to get the index the iterator points to (for example in vector):
the result of it - vec.begin() will hold the index number.

set vs map in C++ STL : The difference is set is used to store only keys while map is used to store key value pairs.

set vs unordered_set : set - increasing order, search time: O(log n), Insertion/Deletion: log n + rebalance
unordered_set - no order, search time: O(1) average O(n) worst case, Insertion / Deletion: same as search

inserting to a map thorugh pair or access parenthesis: std::map<char, int> mymap;
mymap.insert(std::pair<char, int>('a', 100)); OR mymap['a'] = 100;
There are more options to insert to a map!

Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted 
or deleted, with their storage being handled automatically by the container.
Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators.

The array is a container for constant size arrays.This container wraps around fixed size arrays and also
doesn’t loose the information of its length when decayed to a pointer.


#endif
