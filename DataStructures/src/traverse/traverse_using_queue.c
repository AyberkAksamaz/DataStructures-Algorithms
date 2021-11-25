#include <stdio.h>
#include <stdlib.h>

typedef struct TREE_NODE_s *TREE_NODE;
typedef struct TREE_NODE_s {
	TREE_NODE left;
	TREE_NODE right;
	unsigned long key;
	void  *data;
}TREE_NODE_t[1];

typedef struct {
	TREE_NODE root;
}TREE_t[1], *TREE;

typedef struct QUEUE_NODE_s *QUEUE_NODE;
typedef struct QUEUE_NODE_s {
	QUEUE_NODE next;
	void *data;
}QUEUE_NODE_t;

typedef struct QUEUE_s *QUEUE;
typedef struct QUEUE_s {
	QUEUE_NODE head;
	QUEUE_NODE tail;
}QUEUE_t[1];


QUEUE queue_init() {
	QUEUE new = (QUEUE)malloc(sizeof(QUEUE_t));

	if (new != NULL) {
		new->head = NULL;
		new->tail = NULL;
	}else {
		printf("Error: queue init\n");
	}
	return new;
}

void queue_free(QUEUE queue) {
	free(queue);
}

int queue_is_empty(QUEUE queue) {
	int c = 0;
	if(queue->head == NULL) {
		c = 1;
	}
	return c;
}

void queue_enqueue(QUEUE queue, void *data) {
	QUEUE_NODE node = (QUEUE_NODE)malloc(sizeof(QUEUE_NODE_t));

	if(node != NULL) {
		node->data = data;
		node->next = NULL;
		if(queue->head == NULL) {
			queue->head = node;
		}else {
			queue->tail->next = node;
		}
		queue->tail = node;
	}
}

void *queue_dequeue(QUEUE queue) {

	QUEUE_NODE node = (QUEUE_NODE)malloc(sizeof(QUEUE_NODE_t));
	void *key = NULL;
	node = queue->head;
	if(node != NULL) {
		if(node == queue->tail) {
			queue->head = NULL;
			queue->tail = NULL;
		}else {
			queue->head = node->next;
		}
		key = node->data;
		free(node);
	}else {
		printf("Queue empty!");
	}
	return key;
}



TREE tree_init() {
	TREE t = (TREE)malloc(sizeof(TREE_t));
	if(t == NULL) {
		printf("Error .... \n");
	} else {
		t->root = NULL;
	}

	return t;
}

void tree_kill(TREE t) {
	if(t == NULL) {
		printf("Error .... \n");
	}
	free(t);
}

TREE_NODE tree_node_init(unsigned long key, void *data) {
	TREE_NODE n = (TREE_NODE)malloc(sizeof(TREE_NODE_t));
	n->left = NULL;
	n->right = NULL;
	n->key = key;
	n->data = data;
	return n;
}

void tree_insert(TREE tree, unsigned long key, void *data) {
	TREE_NODE curr;
	if(tree->root == NULL) {
		tree->root = tree_node_init(key, data);
	} else {
		curr = tree->root;
		while(1) {
			if(key < curr->key) {
				if(curr->left == NULL) {
					curr->left = tree_node_init(key, data);
					break;
				} else {
				curr = curr->left;
				}
			}else if (key > curr->key) {
				if(curr->right == NULL) {
					curr->right = tree_node_init(key, data);
					break;
				}else {
				curr = curr->right;
				}
			}else {
				printf("Error: Duplicate node.\n");
			}
		}
	}
}


void traverse_function(TREE_NODE root) {
	QUEUE q = queue_init();
	TREE_NODE node;
	queue_enqueue(q, root);

	while(!queue_is_empty(q)) {
		node = queue_dequeue(q);
		printf("%d ", node->key);
		if(node->left != NULL) {
			queue_enqueue(q, node->left);
		}if(node->right != NULL) {
			queue_enqueue(q, node->right);
		}
	}
	queue_free(q);
}


int main() {

	TREE tree = tree_init();

	tree_insert(tree, 55, NULL);
	tree_insert(tree, 25, NULL);
	tree_insert(tree, 60, NULL);
	tree_insert(tree, 10, NULL);
	tree_insert(tree, 78, NULL);
	tree_insert(tree, 12, NULL);
	tree_insert(tree, 90, NULL);
	tree_insert(tree, 75, NULL);
	tree_insert(tree, 30, NULL);

	traverse_function(tree->root);



}
