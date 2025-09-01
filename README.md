# C_Data_Structures

Implementation of the basic data structures written in C. All implementations include support for any data type.
The data_structures folder includes implementations of:

    1. Linked Lists -> Singly Linked, Doubly Linked
    2. Stacks -> Classic Linked Implementation, Dropout Stack, Array-Based Stack
    3. Queues -> Classic Linked Implementation, Deque (Double Ended Queue), Array-Based Queue, Circular Queue
    4. Hash Table -> With chaining used to resolve collisions
    5. Graphs -> Undirected Graph (Adjacency Matrix Implementation), Directed Graph (Adjacency Matrix Implementation)

Future versions will include tree and bitmap implementations. The concept of a Hashed Array Tree (HAT) will be used to implement an N-Ary tree.

## Compiling and Running a File Using the Library

To compile and run a .c file that uses any of these data structures, the file to compile, as well as the .c file which contains the function definitions of the prototypes can be compiled with gcc as follows:

    gcc file_to_compile.c header_definition_file.c -o desired_name_of_executable

For example, if using the singly_linked_list.h header file directly within the project, the following compilation statement would be used:

    gcc singly_linked_list_test.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c -o singly_linked_list

The following command will run the created executable

    .\singly_linked_list

If a data structure relies on another in the library as part of its implementation, the following syntax would be used:

    gcc file_to_compile.c header_definition_file.c additional_structure_definition_file_1.c ... -o desired_name_of_executable

The "..." before -o indicates that the preceding statement may need to be used multiple times if there are multiple data structures from the library used to implement the current structure.

For example, if using the dropout_stack.h header file directly within the project, the following compilation statement would be used as it relies on a singly linked list in its implementation:

    gcc dropout_stack_test.c ../data_structures/stacks/dropout_stack/dropout_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c -o dropout_stack_test
