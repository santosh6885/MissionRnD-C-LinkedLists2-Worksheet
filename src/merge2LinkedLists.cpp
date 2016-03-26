/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	struct node *curr1=head1, *curr2=head2, *head=NULL, *curr=NULL;
	if (head1 == NULL && head2 == NULL)
		return NULL;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	while (1){
		if (curr1 == NULL && curr2!=NULL){
			curr->next = curr2;
			
			break;
		}
		if (curr2 == NULL && curr1!=NULL){
			curr->next = curr1;
	
			break;
		}
		if (curr1 == NULL && curr2 == NULL)
			break;

		if (curr1->num < curr2->num){
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = curr1->num;
			newnode->next = NULL;
			if (curr == NULL){
				head = newnode;
				curr = newnode;
			}
			else{
				curr->next = newnode;
				curr = newnode;
			}
			curr1 = curr1->next;
		}
		else if (curr1->num > curr2->num){
			struct node *newnode = (struct node *)malloc(sizeof(struct node));
			newnode->num = curr2->num;
			newnode->next = NULL;
			if (curr == NULL){
				head = newnode;
				curr = newnode;
			}
			else{
				curr->next = newnode;
				curr = newnode;
			}
			curr2 = curr2->next;
		}
		else{
			struct node *newnode1 = (struct node *)malloc(sizeof(struct node));
			newnode1->num = curr1->num;
			newnode1->next = NULL;
			struct node *newnode2 = (struct node *)malloc(sizeof(struct node));
			newnode2->num = curr2->num;
			newnode2->next = NULL;
			if (curr == NULL){
				head = newnode1;
				head->next = newnode2;
				curr = newnode2;
			}
			else{
				curr->next = newnode1;
				newnode1->next = newnode2;
				newnode2->next = NULL;
				curr = newnode2;
			}
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
	}
	return head;
	//return NULL;
}
