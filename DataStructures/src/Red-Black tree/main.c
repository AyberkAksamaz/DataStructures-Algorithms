#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s {
	NODE left;
	NODE right;
	unsigned long key;
	void *data;
	int color;   // 1 = red, 0 = black;
}NODE_t[1];

typedef struct {
	NODE root;
}TREE_t[1], *TREE;

TREE tree_init() {
	TREE t = (TREE)malloc(sizeof(TREE_t));
	if(t == NULL) {
		printf("Error .... \n");
	}else {
		t->root = NULL;
	}
	return t;
}

void tree_kill(TREE t) {
	if(t == NULL) {
		printf("Error... \n");
	}
	free(t);
}

NODE tree_node_init(unsigned long key, void *data) {
	NODE n = (NODE)malloc(sizeof(NODE_t));
	n->left = NULL;
	n->right = NULL;
	n->key = key;
	n->data = data;
	n->color = 1;  // red
	return n;
}


//left rotate
NODE rotate_left(NODE node) {

	NODE n1,n2;

	n1 = node->right;
	n2 = n1->left;

	n1->left = node;
	node->right = n2;

	return n1;
}

//right rotate
NODE rotate_right(NODE node) {

	NODE n1, n2;

	n1 = node->left;
	n2 = n1->right;

	n1->right = node;
	node->left = n2;

	return n1;
}

void swap_colors(NODE node) {
	if(node->color == 1) {
		node->color = 0;
	}else {
		node->color = 1;
	}
}

NODE red_black_tree_insert_recursive(NODE node, unsigned long key, void *data) {
	if(node != NULL) {
		if(key < node->key) {
			node->left = red_black_tree_insert_recursive(node->left, key, data);
		}else if(key > node->key) {
			node->right = red_black_tree_insert_recursive(node->right, key, data);
		}else {
			return node;
		}
	}else {
		node = tree_node_init(key, data);
	}


	if(key < node->key) {
		if((node->left != NULL) && (node->left->color != 0)) {
			if((node->right != NULL) && (node->right->color == 1)) { // red uncle
				node->left->color = 0; //  black parent
				node->right->color = 0; // black uncle
				node->color = 1; // red gparent
			} else { // black uncle
				  	// LL rotation
				if((key < node->left->key) && (node->left->left->color == 1)) {
					node =  rotate_right(node);
					swap_colors(node);   //swap color gparent
					swap_colors(node->right); //swap color parent
					// LR rotation
				}else if((key > node->left->key) && (node->left->right->color == 1)) {
					node->left = rotate_left(node->left);
					node =  rotate_right(node);
					swap_colors(node);   //swap color gparent
					swap_colors(node->right); //swap color parent
				}

			}
	}
	}else if(key > node->key) {
		 if((node->right != NULL) && (node->right->color != 0)) {
				if((node->left != NULL) && (node->left->color == 1)) { // red uncle
					node->right->color = 0; // black parent
					node->left->color = 0; // black uncle
					node->color = 1; // red gparent
				} else { // black uncle
					// RR rotation
					if((node->right->right != NULL) && (node->right->right->color == 1)) {
						node =  rotate_left(node);
						swap_colors(node); //swap color gparent
						swap_colors(node->left); //swap color parent
					// RL rotation
					}else if((node->right->left != NULL) && (node->right->left->color == 1)) {
						node->right = rotate_right(node->right);
						node =  rotate_left(node);
						swap_colors(node); //swap color gparent
						swap_colors(node->left); //swap color parent
					}

				}
			}
	}else {
		node->key = key;

	}
	return node;
}


void tree_print(NODE node, int k) {
	int i;
	if(node != NULL) {
		tree_print(node->right, k+3);
		for(i = 0; i < k; i++) {
			printf(" ");
		}
		printf("%lu\n", node->key);
		fflush(stdout);
		tree_print(node->left, k+3);
	}
}

int main() {


//	TREE tree = tree_init();
//	NODE node;
//	node = red_black_tree_insert_recursive(tree->root, 80, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 70, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 60, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 50, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 90, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 100, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 120, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 130, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 140, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 150, NULL);
//	node->color = 0;
//	node = red_black_tree_insert_recursive(node, 125, NULL);
//	tree_print(node, 0);

	int m = 3;
	printf("max keys : %d\n", m-1);
	printf("max child : %d\n", m);
	printf("min keys : %d\n", (m/2)-1);
	printf("max keys : %d\n", m-1);
	printf("min child : %d\n", m/2);
}
