#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot){
	larger = NULL;
	smaller = NULL;
	if (head == NULL){return;}
	if (head->next != NULL){	
		llpivot(head->next, smaller, larger, pivot);
	}
	Node*& smarger = (head->val>pivot) ? larger : smaller;
	head->next=smarger;
	smarger = head;
	head = NULL;
}
