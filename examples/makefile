all: array_queue_example directed_graph_example undirected_graph_example

#Compilation for array queue example
array_queue_example: array_queue_example.c ../data_structures/queues/array_queue/array_queue.c
	gcc -o array_queue_example array_queue_example.c ../data_structures/queues/array_queue/array_queue.c -I.

#Compilation for directed graph example
directed_graph_example: directed_graph_example.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c
	gcc -o directed_graph_example directed_graph_example.c ../data_structures/graphs/directed_graph/directed_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c -I.

#Compilation for directed graph example
undirected_graph_example: undirected_graph_example.c ../data_structures/graphs/undirected_graph/undirected_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c
	gcc -o undirected_graph_example undirected_graph_example.c ../data_structures/graphs/undirected_graph/undirected_graph.c ../data_structures/stacks/array_stack/array_stack.c ../data_structures/queues/array_queue/array_queue.c -I.


