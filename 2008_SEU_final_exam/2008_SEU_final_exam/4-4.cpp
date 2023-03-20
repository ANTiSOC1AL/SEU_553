#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* next;
};

void printList(node* head) {
	node* p = head;
	while (p != 0) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

node* Insert(node* head, node* p)//�� p ָ��Ľ����뵽 head �����������
{
	node* p1, * p2;
	if (head == 0) {//������,���뵽�����ײ�
		head = p;
		/*1*/ head->next = 0;
		return head;
	}
	if (head->data >= p->data) {//�ǿ�����,p ����������׽ڵ��������С,���뵽����
		p->next = head;
		/*2*/ head = p;
		return head;
	}
	p2 = p1 = head;
	while (/*3*/ p2->data < p->data) {//�ҵ�Ҫ�����λ��
		p1 = p2; 
		p2 = p2->next;
	}
	if (p2->data < p->data) {//p ����Ľ������������,���뵽��β
		p2->next = p; p->next = 0;
	}
	else {//���뵽 p1 �� p2 ָ��Ľ��֮��
		/*4*/
		p->next = p2;
		p1->next = p;
	}
}

int main() {
	node* p3 = new node, * p1 = new node, * p2 = new node;
	p3->data = 1; p1->data = 4; p2->data = 2;
	p3->next = nullptr; p1->next = nullptr; p2->next = nullptr;

	node* head = 0;
	head = Insert(head, p1);
	printList(head);
	head = Insert(head, p2);
	printList(head);
	head = Insert(head, p3);
	printList(head);

	return 0;
}