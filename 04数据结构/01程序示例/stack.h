typedef int Status;
typedef struct SNode {
	int data;
	struct SNode *next;
} SNode, *LinkStack;

Status InitStack(LinkStack &S) {
	S = NULL;
	return OK;
}
bool StackEmpty(LinkStack S) {
	if (!S)
		return true;
	return false;
}
Status Push(LinkStack &S, int e) {
	LinkStack p;
	p = new SNode;
	if (!p) {
		return OVERFLOW;
	}
	p->data = e;
	p->next = S;
	S = p;
	return OK;
}
Status Pop(LinkStack &S, int &e) {
	LinkStack p;
	if (!S)
		return ERROR;
	e = S->data;
	p = S;
	S = S->next;
	delete p;
	return OK;
}