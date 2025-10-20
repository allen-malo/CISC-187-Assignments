**1. Imagine you were to take an empty binary search tree and insert the following sequence of numbers in this order: [1, 5, 9, 2, 4, 10, 6, 3, 8]. Draw a diagram showing what the binary search tree would look like. Remember, the numbers are being inserted in the order presented here.**

Before we start going over what this structure is going to look like when we add these integers to the binary search tree in this order, we need to understand how adding an element to a binary search tree works. 

When we add an element to a binary search tree, elements with a lesser value than the value in their parent node are stored to the left, and greater values are stored to the right. So, when we add the first element in the array (1), this will be our root node. From this point on, any elements we add that are greater will go to the right, and lesser ones will go to the left. The structure will now go as follows:

Add 1 -> root<br>
Add 5 -> right of root<br>
Add 9 -> right of root -> right of 5<br>
Add 2 -> right of root -> left of 5<br>
Add 4 -> right of root -> left of 5 -> right of 2<br>
Add 10 -> right of root -> right of 5 -> right of 9<br>
Add 6 -> right of root -> right of 5 -> left of 9<br>
Add 3 -> right of root -> left of 5 -> right of 2 -> left of 4<br>
Add 8 -> right of root -> right of 5 -> left of 9 -> right of 6<br>

**2, If a well-balanced binary search tree contains 1000 values, what is the maximum number of steps it would take to search for a value within it?**

In order to find the maximum number of steps it would take to find a value in a binary search tree with 1000 elements, we'll have to determine the height of this binary search tree. The height of a binary search tree is the number of edges on the longest path from the root node to a leaf node. The height of a binary search tree can be found with the following formula: _ceil(log<sub>2</sub>(N + 1))_, where _N_ is the number of nodes in the tree. If we evaluate _ceil(log<sub>2</sub>(1000 + 1))_, it comes out to a height of 10. Therefore, the maximum number of steps it will take to search for a value in a well-balanced binary search tree of 1000 elements is 10 steps.

**3. Write an algorithm that finds the greatest value within a binary search tree.**

Since we know that the greater values in a binary tree are in the rightmost direction, we'll want to keep going to the right node until we reach the end in order to find the greatest value. For this to work, we'll start at the root node, and perform a while loop that checks if there is a node to the right. If there is a node to the right, then we'll move to that node. We'll keep doing this until there are no more nodes to the right. Once we hit the end, we can return the value stored in this node.

**4. Write code in C++ using the same array mentioned in #1 and implement a binary search tree. Only the insertion operation is required.**

For our binary search tree structure, we'll need some nodes, which should store a value, the left node in the structure, and the right node in the structure. Initially, the right and left nodes will be null pointers, which will represent the absence of a node at this position.

For our binary tree class, we're going to have a single private variable and method. The private variable will be our ```rootNode```, and the private method will be our ```destroyTree```. The ```rootNode``` will be what you think it is: this will be the root of our binary search tree. The ```destroyTree``` method will only be called during the destructor, and will destroy the binary search tree when we need to free up space. These are the only private members of this class, and everything else after this will be declared as public.

Constructor:
This will initialize our ```rootNode``` to be a null pointer.

Destructor:
This will call the ```destroyTree``` method mentioned earlier on the ```rootNode```. After, the ```rootNode``` will be declared as a null pointer.

insert:
This method will insert a value into the binary search tree in the appropriate position. First, we'll create a new node, and store the specified value in it. We'll first check if there is no root node. If there isn't a root node, then we'll assign this as the root node, and end our method here. If there is already a root node, then we'll have to traverse the tree in order to find the correct position. We'll declare two Node pointer variables, one that stores the current node we are on, and another that stores the parent node. We'll then use a while loop to traverse the tree until the current node is a null pointer. For every iteration, the parent node will become the current node, and we'll compare the values in the right and left node against the specified value. If the specified value is less than the value at the current node, then we'll move to the left node (current node becomes its left node), otherwise, we'll move to the right node (current node becomes its right node). Once there are no more nodes to traverse to, we'll exit the while loop, and compare the specified value with the value in the parent node. If the specified value is smaller than the value in the parent node, then the new node will be inserted in the left position, otherwise, it'll go to the right position.
