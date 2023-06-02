#ifndef BST_H
#define BST_H

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
} Node;

typedef Node* Tree;

Tree add_node_bst(int value, Tree root);

void in_order_bst(Tree root);

void pre_order_bst(Tree root);

void pos_order_bst(Tree root);

void reverse_bst(Tree root);

int prime_qtd_bst(Tree root);

int successor_bst(int value, Tree upperNode, Tree root);

int smaller_number_bst(Tree root);

int bigger_number_bst(Tree root);

void path_bst(int value, Tree root);

Tree remove_bst(int value, Tree root);

int sum_bst(Tree root);

Tree prune_bst(int value,Tree root);

void free_nodes_bst(Tree root);

Tree readjustment_bst(Tree root, int percentage);

int exist_bst(int value, Tree root);

void descendants_bst(int value,Tree root);

int height_bst(Tree root);

#endif
