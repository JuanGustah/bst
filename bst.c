#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Tree add_node_bst(int value, Tree root){
	if(root == NULL){
		Tree nova = (Tree) malloc(sizeof(struct node));
		nova->value =  value;
		nova->left = NULL;
		nova->right = NULL;
		return nova;
	}else{
		if(value > root->value){
			root->right = add_node_bst(value, root->right);
		}else{
			root->left = add_node_bst(value,root->left);
		}
		return root;
	}
}

void pre_order_bst(Tree root){
	if(root!=NULL){
		printf("[%d]",root->value);
		pre_order_bst(root->left);
		pre_order_bst(root->right);
	}
}

void in_order_bst(Tree root){
	if(root!=NULL){
		in_order_bst(root->left);
		printf("[%d]",root->value);
		in_order_bst(root->right);
	}
}
void pos_order_bst(Tree root){
	if(root!=NULL){
		pos_order_bst(root->left);
		pos_order_bst(root->right);
		printf("[%d]",root->value);
	}
}

void reverse_bst(Tree root){
	if(root!=NULL){
		reverse_bst(root->right);
		printf("[%d]",root->value);
		reverse_bst(root->left);
	}
}
int prime_qtd_bst(Tree root){
	if(root==NULL){
		return 0;
	}else{
		int primesLeft = prime_qtd_bst(root->left);
		int primesRight = prime_qtd_bst(root->right);
		int isPrime = 1;
		
		for(int i=2;i<root->value;i++){
			if(root->value % i ==0){
				isPrime = 0;
			}
		}
		
		return primesLeft+primesRight+isPrime;
	}
}

int successor_bst(int value, Tree upperNode, Tree root){
	if(root==NULL){
		return -1;
	}else{
		if(root->value == value){
			if(root->right !=NULL){
				return smaller_number_bst(root->right);
			}
			if(upperNode !=NULL){			
				return upperNode->value;
			}
			return -1;
		}
		
		if(value > root->value){
			return successor_bst(value,upperNode,root->right);
		}else{
			return successor_bst(value,root,root->left);
		}
	}
}

int smaller_number_bst(Tree root){
	if(root->left ==NULL){
		return root->value;
	}else{
		smaller_number_bst(root->left);
	}
}

int bigger_number_bst(Tree root){
	if(root->right == NULL){
		return root->value;
	}else{
		bigger_number_bst(root->right);
	}
}

void path_bst(int value, Tree root){
	if(root == NULL){
		printf("Tem não");
	}else{
		printf("[%d]",root->value);
		
		if(root->value == value) return;
		
		if(value > root->value){
			path_bst(value, root->right);
		}else{
			path_bst(value, root->left);
		}
	}
}

Tree remove_bst(int value, Tree root) {
    if(root == NULL) {
        return root;
    }
    
    if(root->value == value) {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        if(root->left != NULL && root->right == NULL) {
            Tree aux = root->left;
            free(root);
            return aux;
        }

        //caso 2 (b): exatamente um filho direito
	if(root->right != NULL && root->left == NULL) {
            Tree aux = root->left;
            free(root);
            return aux;
        }
        
        //caso 3: dois filhos
        int biggerValueOnLeft= bigger_number_bst(root->left);
        root->value = biggerValueOnLeft;
        root->left = remove_bst(biggerValueOnLeft, root->left);

        return root;
    }
    if(value > root->value) {
       root->right = remove_bst(value, root->right);
    } else {
        root->left = remove_bst(value, root->left);
    }
    return root;
}

int sum_bst(Tree root){
	if(root==NULL){
		return 0;
	}else{
		int sumLeft = sum_bst(root->left);
		int sumRight = sum_bst(root->right);
		return sumLeft+sumRight+root->value;
	}
}
int exist_bst(int value, Tree root){
	if(root==NULL){
		return 0;
	}else{
		if(root->value == value) return 1;
		
		if(value > root->value){
			return exist_bst(value, root->right);
		}else{
			return exist_bst(value, root->left);
		}
	}
}
Tree readjustment_bst(Tree root, int percentage){
	if(root==NULL){
		return root;
	}else{
		root->left = readjustment_bst(root->left, percentage);
		root->right = readjustment_bst(root->right, percentage);
	
		root->value = (int) root->value +((float) root->value * ((float)percentage/100));	
		return root;
	}
}

void descendants_bst(int value,Tree root){
	if(root!=NULL){
		if(root->value == value){
			in_order_bst(root->left);
			in_order_bst(root->right);
			return;
		}
		
		if(value > root->value){
			descendants_bst(value,root->right);
		}else{
			descendants_bst(value,root->left);
		}
	}
}

int height_bst(Tree root){
	if(root==NULL){
		return 0;
	}else{
		int heightLeft = height_bst(root->left);
		int heightRight = height_bst(root->right);
		int maxHeight = heightLeft > heightRight ? heightLeft : heightRight;
		return maxHeight+1;
	}
}

Tree prune_bst(int value,Tree root){
	if(root==NULL){
		return root;
	}else{
		if(root->value == value){
			free_nodes_bst(root);
			return NULL;
		}
		
		if(value > root->value){
			root->right = prune_bst(value,root->right);
		}else{
			root->left = prune_bst(value,root->left);
		}
		return root;
	}
}

void free_nodes_bst(Tree root){
	if(root!=NULL){
		free_nodes_bst(root->left);
		free_nodes_bst(root->right);
		free(root);
	}
}
