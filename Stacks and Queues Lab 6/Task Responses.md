**1. Use Figure 17 as a model to illustrate the result of each operation in the sequence PUSH(S, 4), PUSH(S, 1), PUSH(S, 3), POP(S), PUSH(S, 8), POP(S) on an initially empty stack S stored in array S[1..6].**

For this example, we are starting with an empty stack that can contain 6 elements. The important thing to note here is that the stack data structure is FILO (First in, Last out), so whatever element we add first is going to be the one we access last. A better way to picture this is like a stack of plates. In order to get to the bottom plate (without breaking the others), you have to remove the plate on top first to get closer and closer to the bottom plate.

Our first operation adds 4 to the stack. The next operation adds 1 to the stack, so now 1 is at the top, and 4 is at the bottom. Next, we add 3, which puts 3 at the top, 1 in the second position, and 4 at the bottom. The next operation removes the top element, so 3 is now removed from the stack, leaving 1 at the top now. Next, 8 is placed in the stack, so now 8 is at the top, 1 is in the second position, and 4 remains at the bottom. The final operation removes the top element, so now 8 is removed from the top.

The stack after all the operations contains 1 and 4, with 1 being at the top, and 4 being at the bottom.

**2. Use Figure 18 as a model to illustrate the result of each operation in the sequence ENQUEUE(Q, 4), ENQUEUE(Q, 1), ENQUEUE(Q, 3), DEQUEUE(Q), ENQUEUE(Q, 8), DEQUEUE(S) on an initially empty queue Q stored in array Q[1..6].**

For this example, we are starting with an empty queue that can contain 6 elements. The important thing to note here is that the queue data structure is FIFO (First in, First out), so whatever element we add first is going to be the one we access first. You can picture this as like waiting in a line (first come, first serve). In order to get to the last person, we have to attend the people in front first.

The first three operations add 4, 1, and 3 to the queue, in that order. The next operation removes the element at the front, which is 4. The queue now contains 1 and 3, in that order. The next operation adds 8 to the queue, so now the queue contains 1, 3, and 8, in that order. The final operation removes the element at the front, which removes 1.

The queue after all the operations contains 3 and 8, with 3 being in the front, and 8 being in the back.

**3. Rewrite ENQUEUE and DEQUEUE to detect _underflow_ and _overflow_ of a queue.**

When we call enqueue or dequeue, we are attempting to add an element to the queue, or remove an element from the queue. Overflow happens when we try to add a new element to the queue when the queue is full, and underflow happens when we try to remove an element from the queue when the queue is empty. There are a few ways to combat this, and it depends on how you set up your enqueue/dequeue methods.

The first approach (which is described in the textbook) is to use the head/tail values to determine if the queue is full/empty. This does work, however, it comes at the cost of one space in the array. If the head and tail positions are next to each other in the sense that the array is a loop, then the queue is full. If the head and tail positions are equal, then the queue is empty. For this approach to work, you need to update the tail position before assigning the value in the array. I've used this for the deque structure.

The other approach (the one I've used here) is to keep a count of how many elements there are in the queue, which is much more explicit and allows you to use the full array. When the array is full, the value of your counter variable will be equal to the array size, and when the queue is empty, then the counter will be equal to 0. For this approach to work properly, you need to ensure that whenever an element is added/removed from the queue that the counter is updated properly, and that the tail position is updated after assigning the value in the array. I've used this for the queue structure.

**4. A stack allows insertion and deletion of elements at only end, a queue allows insertion at one end and deletion at the other end, and a deque (double-ended queue) allows insertion and deletion at both ends. Write four _O(1)_-time procedures to insert elements into and and delete elements from both ends of a deque implemented by an array.**

The deque is going to be _very_ similar to the queue, however, we are now granting this structure the ability to add/remove elements from the opposite end. Of course, when we add an element to the front, we move the head back a position in the array, and when we add an element to the back, we advance the tail a position in the array. For removing at the head, it's just moving the head position up a position, and removing the rear is just moving the tail back a position. Both the add and remove methods feature teh checks to prevent overflow and underflow as well.
