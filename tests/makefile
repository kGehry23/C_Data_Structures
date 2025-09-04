# /**
#  ********************************************************************************
#  * @file    tests/makefile
#  * @author  Kai Gehry
#  * @date    2025-09-04
#  *
#  * @brief   Make file for compilation of test files.
#  ********************************************************************************
#  */

#Compiler specification
CC=gcc
#Preprocessor macros
CFLAGS=-I.

#Specifies which files to compile
all: array_queue_tests array_stack_tests circular_queue_tests deque_tests directed_graph_tests doubly_linked_list_tests dropout_stack_tests hash_table_tests linked_list_queue_tests linked_list_stack_tests singly_linked_list_tests undirected_graph_tests 

#Compilation for array queue test
array_queue_tests: array_queue_tests.c ../data_structures/queues/array_queue/array_queue.c 
	$(CC) -o array_queue_tests array_queue_tests.c ../data_structures/queues/array_queue/array_queue.c 

#Compilation for array stack test
array_stack_tests: array_stack_tests.c ../data_structures/stacks/array_stack/array_stack.c
	$(CC) -o array_stack_tests array_stack_tests.c ../data_structures/stacks/array_stack/array_stack.c 

#Compilation for circular queue test
circular_queue_tests: circular_queue_tests.c ../data_structures/queues/circular_queue/circular_queue.c
	$(CC) -o circular_queue_tests circular_queue_tests.c ../data_structures/queues/circular_queue/circular_queue.c

#Compilation for directed graph traversal test
d_graph_traversal_tests: d_graph_traversal_tests.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/queues/array_queue/array_queue.c ../data_structures/stacks/array_stack/array_stack.c
	$(CC) -o d_graph_traversal_tests d_graph_traversal_tests.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/queues/array_queue/array_queue.c ../data_structures/stacks/array_stack/array_stack.c

#Compilation for deque test
deque_tests: deque_tests.c ../data_structures/queues/deque/deque.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c
	$(CC) -o deque_tests deque_tests.c ../data_structures/queues/deque/deque.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c

#Compilation for directed graph test
directed_graph_tests: directed_graph_tests.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c
	$(CC) -o directed_graph_tests directed_graph_tests.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c 

#Compilation for doubly linked list test
doubly_linked_list_tests: doubly_linked_list_tests.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c
	$(CC) -o doubly_linked_list_tests doubly_linked_list_tests.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c

#Compilation for dropout stack test
dropout_stack_tests: dropout_stack_tests.c ../data_structures/stacks/dropout_stack/dropout_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o dropout_stack_tests dropout_stack_tests.c ../data_structures/stacks/dropout_stack/dropout_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for hash_table_tests
hash_table_tests: hash_table_tests.c ../data_structures/hash_table/hash_table.c
	$(CC) -o hash_table_tests hash_table_tests.c ../data_structures/hash_table/hash_table.c

#Compilation for linked list queue test
linked_list_queue_tests: linked_list_queue_tests.c ../data_structures/queues/linked_list_queue/linked_list_queue.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o linked_list_queue_tests linked_list_queue_tests.c ../data_structures/queues/linked_list_queue/linked_list_queue.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for linked list stack test
linked_list_stack_tests: linked_list_stack_tests.c ../data_structures/stacks/linked_list_stack/linked_list_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o linked_list_stack_tests linked_list_stack_tests.c ../data_structures/stacks/linked_list_stack/linked_list_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for singly linked list test
singly_linked_list_tests: singly_linked_list_tests.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o singly_linked_list_tests singly_linked_list_tests.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for directed graph test
undirected_graph_tests: undirected_graph_tests.c ../data_structures/graphs/undirected_graph/undirected_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c
	$(CC) -o undirected_graph_tests undirected_graph_tests.c ../data_structures/graphs/undirected_graph/undirected_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c 



