[Video Link](https://youtu.be/b2N-nLEkA4g)

**1. Draw what the following heap would look like after we insert the value 11 into it:**<br>
<img width="377" alt="image" src="https://user-images.githubusercontent.com/11669149/229943640-2f9f7951-a9c6-4e4a-86f2-ea5dcd4bc64a.png">

Given the structure of the tree, we can assume this is a max-heap, where the parent node of each node stores a value greater than itself. When we insert the value 11 into the heap, the important thing to keep in mind is that the structure of the heap **must** remain complete. A heap is considered complete if there are no nodes to the right of an empty node. 

So, in order for this heap to remain complete when we insert the value 11, we are going to start at the rightmost available position, which is to the right of the value 5. Since this is a max-heap, 11 has to "trickle" up the tree, so it swaps places with 5. Since 11 is greater than 9, it'll swap places with 9 as well. And since 11 is greater than 10, they will also swap places, thus making 11 the new root node of the heap.

**2. Draw what the previous heap would look like after we delete the root node.**

We will be starting with the original tree for this. When we delete the root node (10), the heap **must** stay complete (no nodes should appear to the right of an empty position in a level of the tree). So, we're going to start with placing the rightmost node at the lowest level of the tree at the root now. Since this is a max-heap, we're going to have 3 and 9 swap places in the tree. 

If you're asking why we can't swap with 8, it's because after having 3 "trickle" down the structure, we will have violated the structure of the heap; it will no longer be complete. Additionally, 9 is greater than 8, so swapping with 8 would lead to a double-violation. After we swap with 9, 3 is now the parent of 6 and 5. Since 6 is the greater of the two child nodes, 3 will swap places with 6. This keeps the heap's structure in-tact, and since 3 is greater than 2 and 1, this completes the deletion of the root node.

**3. Imagine you've built a brand-new heap by inserting the following numbers into the heap in this particular order: 55, 22, 34, 10, 2, 99, 68. If you then pop them from the heap one at a time and insert the numbers into a new array, in what order would the numbers now appear?**

Since 55 is the first element we are inserting, it will become the root node of the heap (for now). Inserting the next element (22), will place it directly to the left of the root. The next element (34), will go to the right of the root, keeping the complete structure of the heap. Our next value (10) will go to the bottom rightmost position of the heap, which is the left child of 22. Similarly, 2 will also start at the bottom rightmost position that keeps the heap structure, which is the right child of 22. Again, inserting 99 will have it start at the bottom rightmost position, which is the left child of 34. Since this is a max-heap, 99 has to "trickle up" the tree, so we swap its position with 34. Since 99 is also greater than 55, they will swap places as well. this makes 99 the new root node of the tree. The final value to add to the heap, 68, will start at the bottom rightmost position of the tree, which is the right child of 55. Since 68 is greater than 55, they will swap places, which now completes the creation of the heap from the given values, in order. 

With the heap now complete, when we pop elements from the heap, they will be inserted into an array in the following order (first popped -> last popped):<br>

[99, 68, 55, 34, 22, 10, 2]<br>

 You many notice that when when we pop the elements from the heap and place them into an array, they are organized from greatest -> smallest. This is because in a max-heap, the greatest value is always going to be in the root node, and popping an element from a heap removes the root node. So whenever we call 'pop', we are removing the greatest value from the heap
