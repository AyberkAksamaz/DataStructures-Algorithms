#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct LINKED_LIST_NODE_s *LINKED_LIST_NODE;
typedef struct LINKED_LIST_NODE_s {
	LINKED_LIST_NODE next;
	void *data;
}LINKED_LIST_NODE_t[1];

typedef struct LINKED_LIST_s *LINKED_LIST;
typedef struct LINKED_LIST_s {
	LINKED_LIST_NODE head;
}LINKED_LIST_t[1];

LINKED_LIST linked_list_init();
LINKED_LIST_NODE linked_list_node_init(LINKED_LIST_NODE node, void *data);
void linked_list_free(LINKED_LIST list);
void linked_list_prepend(LINKED_LIST list, void *data);
void linked_list_append(LINKED_LIST list, void *data);
void linked_list_insert(LINKED_LIST list, void *data, int idx);

#endif /* LINKED_LIST_H_ */
