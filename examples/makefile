#Make file for compilation of example files

CC=gcc
CFLAGS=-I.

#Specifies which files to compile
all: array_queue_example array_stack_example circular_queue_example deque_example directed_graph_example doubly_linked_list_example dropout_stack_example hash_table_example linked_list_queue_example linked_list_stack_example singly_linked_list_example undirected_graph_example 

#Compilation for array queue example
array_queue_example: array_queue_example.c ../data_structures/queues/array_queue/array_queue.c 
	$(CC) -o array_queue_example array_queue_example.c ../data_structures/queues/array_queue/array_queue.c 

#Compilation for array stack example
array_stack_example: array_stack_example.c ../data_structures/stacks/array_stack/array_stack.c
	$(CC) -o array_stack_example array_stack_example.c ../data_structures/stacks/array_stack/array_stack.c 

#Compilation for circular queue example
circular_queue_example: circular_queue_example.c ../data_structures/queues/circular_queue/circular_queue.c
	$(CC) -o circular_queue_example circular_queue_example.c ../data_structures/queues/circular_queue/circular_queue.c

#Compilation for directed graph traversal example
d_graph_traversal_example: d_graph_traversal_example.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/queues/array_queue/array_queue.c ../data_structures/stacks/array_stack/array_stack.c
	$(CC) -o d_graph_traversal_example d_graph_traversal_example.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/queues/array_queue/array_queue.c ../data_structures/stacks/array_stack/array_stack.c

#Compilation for deque example
deque_example: deque_example.c ../data_structures/queues/deque/deque.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c
	$(CC) -o deque_example deque_example.c ../data_structures/queues/deque/deque.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c

#Compilation for directed graph example
directed_graph_example: directed_graph_example.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c
	$(CC) -o directed_graph_example directed_graph_example.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c 

#Compilation for doubly linked list example
doubly_linked_list_example: doubly_linked_list_example.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c
	$(CC) -o doubly_linked_list_example doubly_linked_list_example.c ../data_structures/linked_lists/doubly_linked_list/doubly_linked_list.c

#Compilation for dropout stack example
dropout_stack_example: dropout_stack_example.c ../data_structures/stacks/dropout_stack/dropout_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o dropout_stack_example dropout_stack_example.c ../data_structures/stacks/dropout_stack/dropout_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for hash_table_example
hash_table_example: hash_table_example.c ../data_structures/hash_table/hash_table.c
	$(CC) -o hash_table_example hash_table_example.c ../data_structures/hash_table/hash_table.c

#Compilation for linked list queue example
linked_list_queue_example: linked_list_queue_example.c ../data_structures/queues/linked_list_queue/linked_list_queue.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o linked_list_queue_example linked_list_queue_example.c ../data_structures/queues/linked_list_queue/linked_list_queue.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for linked list stack example
linked_list_stack_example: linked_list_stack_example.c ../data_structures/stacks/linked_list_stack/linked_list_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o linked_list_stack_example linked_list_stack_example.c ../data_structures/stacks/linked_list_stack/linked_list_stack.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for singly linked list example
singly_linked_list_example: singly_linked_list_example.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c
	$(CC) -o singly_linked_list_example singly_linked_list_example.c ../data_structures/linked_lists/singly_linked_list/singly_linked_list.c

#Compilation for directed graph example
undirected_graph_example: undirected_graph_example.c ../data_structures/graphs/undirected_graph/undirected_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c
	$(CC) -o undirected_graph_example undirected_graph_example.c ../data_structures/graphs/undirected_graph/undirected_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c 



