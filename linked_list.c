#include <stdio.h>
#include <stdlib.h>

//this program is to make a linked list with posibility to do with it such actions as:
//delete node, add new information to node, insert brand new node in any place in linked list
//count number of nodes in list, get needful node by index.
typedef struct node {
	void* element;
	struct node *next;	
} node; 

typedef struct LinkedList {
	node *head;
} LinkedList; 

//add new node to the end of the list
void add(LinkedList *linkedList, void* c)
{
	node *piece = NULL;

	if (linkedList->head) {
		// traverse to last node
		node *indexNode = linkedList->head;

		while (indexNode->next) {
			indexNode = indexNode->next;
		}

		piece = malloc(sizeof(node));
		piece->element = c;
		piece->next = NULL;
		indexNode->next = piece;
	//if there is no node in list just add brand new node
	} else {
		piece = malloc(sizeof(node));
		piece->element = c;
		piece->next = NULL;
		linkedList->head = piece;
	}
}

// count the number of nodes in the list
size_t count(LinkedList *linkedList) {
	size_t count = 0;
	node *indexNode = linkedList->head;
	while (indexNode) {
		count++;
		indexNode = indexNode->next;
	}
	return count;
}

//allocate space for list in memory with malloc()
LinkedList* get_linked_list() 
{
	LinkedList *list = malloc(sizeof(LinkedList));

	return list;
}

//get node by index
node* get_by_index(LinkedList *linkedList, int index)
{
	size_t count = 0;
	node *indexNode = linkedList->head;
	while (indexNode) {
		if (count == index) {
			return indexNode;
		}
		indexNode = indexNode->next;
		count++;
	}
}

//insert node in any place into list
void insert(LinkedList *linkedList, int index, void* data) {
	node *indexNode = NULL;
	node *indexNodePrevious = NULL;
	node *oldNode = NULL;
	node *piece = NULL;
	size_t number_of_nodes = count(linkedList);

	if (index == 0) {
		indexNode = get_by_index(linkedList, index);
		piece = malloc(sizeof(node));
		piece->element = data;
		piece->next = NULL;
		linkedList->head = piece;
		piece->next = indexNode;
	} else if (index > number_of_nodes - 1) {
		add(linkedList, data);
	} else {
		indexNode = get_by_index(linkedList, index);
		oldNode = indexNode;
		indexNodePrevious = get_by_index(linkedList, (index - 1));
		piece = malloc(sizeof(node));
		piece->element = data;
		piece->next = NULL;
		indexNodePrevious->next = piece;
		piece->next = oldNode;
	}
}

//function that delete any node in the list
void delete_node(LinkedList *linkedList, int index)
{
	node *indexNode = NULL;
	node *indexNodePrevious = NULL;
	node *indexNodeNext = NULL;
	size_t number_of_nodes = count(linkedList);

	if (index == 0) {
		indexNode = get_by_index(linkedList, index);
		free(indexNode);
		if (indexNode->next == NULL) {
			linkedList->head = NULL;
		} else {
			linkedList->head = indexNode->next;
		}
	} else if (index == number_of_nodes - 1) {
		indexNode = get_by_index(linkedList, index);
		free(indexNode);
		indexNodePrevious = get_by_index(linkedList, index - 1);
		indexNodePrevious->next = NULL;
	} else {
		indexNode = get_by_index(linkedList, index);
		indexNodePrevious = get_by_index(linkedList, index - 1);
		indexNodeNext = get_by_index(linkedList, index + 1);
		free(indexNode);
		indexNodePrevious->next = indexNodeNext;
	}
}

int main(int argc, char const *argv[])
{	
	node* part = NULL;
	LinkedList* list = get_linked_list();
	add(list, "tomato");
	add(list, "yohurt");
	add(list, "343434343434");
	add(list, "coconut");
	add(list, "banana");
	add(list, "jam");
	add(list, "Jack");
	insert(list, 0, "cheese");
	printf("count %zu\n", count(list) );
	delete_node(list, 0);
	printf("count %zu\n", count(list) );
	part = get_by_index(list, 0);
	printf("%s\n", (char*) part->element);
	
	return 0;
}
