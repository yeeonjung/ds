#include <stdio.h>
#include "LinkedPoly.h"

 
ListHead* createLinkedList(void) {
	ListHead* L;
	L = (ListHead*)malloc(sizeof(ListHead));
	L->head = NULL;
	return L;
}


void appendTerm(ListHead* L, float coef, int expo) {
	ListNode* newNode;
	ListNode* p;
	newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->link = NULL;

	if (L->head == NULL) {		// 다항식 리스트가 공백인 경우
		L->head = newNode;
		return;
	}
	else {						// 다항식 리스트가 공백이 아닌 경우
		p = L->head;
		while (p->link != NULL) {
			p = p->link;			// 리스트의 마지막 노드를 찾음 
		}
		p->link = newNode;		// 새 노드 연결 
	}
}


void addPoly(ListHead* A, ListHead* B, ListHead* C) {
	ListNode* pA = A->head;
	ListNode* pB = B->head;
	float sum;

	
	while (pA && pB) {
		
		if (pA->expo == pB->expo) {
			sum = pA->coef + pB->coef;
			appendTerm(C, sum, pA->expo);
			pA = pA->link; pB = pB->link;
		}
		
		else if (pA->expo > pB->expo) {
			appendTerm(C, pA->coef, pA->expo);
			pA = pA->link;
		}
		
		else {
			appendTerm(C, pB->coef, pB->expo);
			pB = pB->link;
		}
	}
	
	for (; pA != NULL; pA = pA->link)
		appendTerm(C, pA->coef, pA->expo);

	
	for (; pB != NULL; pB = pB->link)
		appendTerm(C, pB->coef, pB->expo);
}


void printPoly(ListHead* L) {
	ListNode* p = L->head;
	for (; p; p = p->link) {
		printf("%3.0fx^%d", p->coef, p->expo);
		if (p->link != NULL) printf(" +");
	}
}