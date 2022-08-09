# Learning-Data-Structures-DSA

In this repository, I implement all data structures in C programming language, including their applications

## Stack

Stack is a linear data structure which follows a particular order in which the operations are performed. The order may
be LIFO(Last In First Out) or FILO(First In Last Out). [Source](https://www.geeksforgeeks.org/stack-data-structure/)

![stack-gif](https://miro.medium.com/max/1680/0*SESFJYWU5a-3XM9m.gif)

### Implementation of Stack

* Using
  [Static array](https://stackoverflow.com/questions/2672085/what-is-the-difference-between-static-and-dynamic-arrays-in-c) [[See code](stack/implementation/static_stack.c)]
* Using
  [Dynamic array](https://stackoverflow.com/questions/2672085/what-is-the-difference-between-static-and-dynamic-arrays-in-c) [[See code](stack/implementation/dynamic_stack.c)]
* Using
  [Linked List](https://www.geeksforgeeks.org/data-structures/linked-list/) [[See code](stack/implementation/linked_stack.c)]

### Applications

* Whether the expression has balanced
  bracket [[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/stack/application/expression_parser.c#L21)]
* [Infix](https://www.codingninjas.com/blog/2021/09/06/infix-postfix-and-prefix-conversion/) to post fix
  conversion [[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/stack/application/expression_parser.c#L50)]
* [Infix](https://www.codingninjas.com/blog/2021/09/06/infix-postfix-and-prefix-conversion/) to pre fix
  conversion [[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/stack/application/expression_parser.c#L93)]
* Evaluation of
  prefix [[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/stack/application/expression_parser.c#L136)]
  and
  postfix [[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/stack/application/expression_parser.c#L157)]
  expression
* Conversion of decimal to binary [[code]()]

## Queue

A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First
In First Out (FIFO). A good example of a queue is any queue of consumers for a resource where the consumer that came
first is served first. The difference between stacks and queues is in removing. In a stack we remove the item the most
recently added; in a queue, we remove the item the least recently
added. [Source](https://www.geeksforgeeks.org/queue-data-structure/)

![queue-gif](https://res.cloudinary.com/practicaldev/image/fetch/s--LTu3kVda--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_66%2Cw_880/https://1.bp.blogspot.com/-N-v_FiIdQXM/XlkFCQQYtPI/AAAAAAAAHR0/zxkuX6WfQS8Y8Mkoj1nHZDWtMOD3MjsUwCLcBGAsYHQ/s1600/0_E33E-AjyAUTFjVmM.gif)

### Implementation of Queue

* Using
  [Static array](https://stackoverflow.com/questions/2672085/what-is-the-difference-between-static-and-dynamic-arrays-in-c)[[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/queue/implementation/static_queue.c#L7)]
* Circular Queue:
  using [Static array](https://stackoverflow.com/questions/2672085/what-is-the-difference-between-static-and-dynamic-arrays-in-c) [[code]()]

## Dynamic Arrays

A dynamic array is an array with a big **improvement**: automatic resizing.
One **limitation** of arrays is that they're fixed currSize, meaning you need to specify the number of elements your
array
will hold ahead of time.
A dynamic array expands as you add more elements. So you don't need to determine the currSize ahead of
time. [[Source](https://www.interviewcake.com/concept/java/dynamic-array)]

## Linked List

A linked list is a linear data structure, in which the elements are not stored at contiguous memory locations. The
elements in a linked list are linked using
pointers [[Source](https://www.geeksforgeeks.org/data-structures/linked-list/)]

![linked-list-gif](https://assets.digitalocean.com/articles/alligator/js/linked-lists-implementation/linked-list-insert.gif)

### Implementation [[code](https://github.com/ujjwalgarg100204/Learning-Data-Structures-DSA/blob/f331774d017bd1c7ea811fe311c0bc7366495fc1/linked_list/implementation/linked_list.c#L6)]
