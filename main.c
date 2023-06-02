#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	Tree tree = NULL;
	while(1){
		int opt;
		scanf("%d",&opt);
		switch(opt){
			case 1:
				int value;
				scanf("%d",&value);
				tree = add_node_bst(value,tree);
				break;
			case 2:
				pre_order_bst(tree);
				printf("\n");
				break;
			case 3:
				in_order_bst(tree);
				printf("\n");
				break;
			case 4:
				pos_order_bst(tree);
				printf("\n");
				break;
			case 5:
				reverse_bst(tree);
				printf("\n");
				break;
			case 6:
				printf("%d\n",prime_qtd_bst(tree));
				break;
			case 7:
				int sucessorValue;
				scanf("%d", &sucessorValue);
				printf("%d\n", successor_bst(sucessorValue,NULL, tree));
				break;
			case 8:
				int pathValue;
				scanf("%d",&pathValue);
				path_bst(pathValue,tree);
				printf("\n");
				break;
			case 9:
				int removeValue;
				scanf("%d",&removeValue);
				tree = remove_bst(removeValue,tree);
				break;
			case 10:
				printf("%d\n",sum_bst(tree));
				break;
			case 11:
				int pruneValue;
				scanf("%d",&pruneValue);
				tree = prune_bst(pruneValue,tree);
				break;
			case 12:
				int readjustmentValue;
				scanf("%d",&readjustmentValue);
				tree = readjustment_bst(tree,readjustmentValue);
				break;
			case 13:
				int existValue;
				scanf("%d",&existValue);
				printf("%d\n",exist_bst(existValue, tree));
				break;
			case 14:
				int descendantValue;
				scanf("%d",&descendantValue);
				descendants_bst(descendantValue,tree);
				printf("\n");
				break;
			case 15:
				printf("%d\n",height_bst(tree));
				break;
			case 99:
				exit(0);
				break;
		}
	}
}

