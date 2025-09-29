

**1. Assume you have a simple single-dimensional array. Linear search will take _O(N)_. Write a code in C++/Python to improve the search operation efficiency from _O(N)_ to _O(1)_.**

To improve the search time on this single-dimensional array from _O(N)_ to _O(1)_, we can create an unordered map and copy over the elements from our array into the map. We'll use the elements in the array as the key, and we can use just about any data type as the value (I've chosen to use "bool"s as the values).

Now that we have our data in an unordered map, we can use the "find" method to search for a key to a key-value pair. If the key-value pair is found, an iterator to the key-value pair is returned. If the key-value pair is not found, then the end iterator is returned. So, for this function that searches the unordered map and returns if it contains our key-value pair, we will just return true/false depending on if the end iterator was not found.

**2. Use C++ to generate a hash value of your name.**

To generate the hash value of my name, "Allen", we're going to need the ```std::hash``` template class. We can get this by using the ```#include <functional>``` header. Once we do this, we can create a hasher for string objects, and then get our hash value by calling the operator of the hasher object and passing in our string variable.

**3. With the help of a figure, explain the problem that occured due to introducing a tombstone to mark the deleted cell.**

The problem that occurs due to a tombstone happens when deleting a key-value pair from the hash table/dictionary/etc. When deleting a key-value pair from the data structure, the once-occupied cell cannot be marked as empty because then the search operation would halt once it passes over the empty cell. To solve this, a special marker, called a tombstone, is placed at that cell to indicate it was once occupied.

The problem that occurs when placing these tombstones is that even though the cell is meant to be deleted, the tombstones still occupy space and thus increase the storage footprint of the data structure. Lookup and iteration operations also still have to process and skip over these tombstones, which ultimately slows down performance. What this means is that, if there is a key-value pair at some position in the data structure, it is possible that any operations conducted would have to go thru and process these tombstones, which would be quicker if the spaces these tombstones occupied simply didn't exist.
