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

node* Insert(node* head, node* p)//将 p 指向的结点插入到 head 代表的链表中
{
	node* p1, * p2;
	if (head == 0) {//空链表,插入到链表首部
		head = p;
		/*1*/ head->next = 0;
		return head;
	}
	if (head->data >= p->data) {//非空链表,p 的数据项比首节点的数据项小,插入到链首
		p->next = head;
		/*2*/ head = p;
		return head;
	}
	p2 = p1 = head;
	while (/*3*/ p2->data < p->data) {//找到要插入的位置
		p1 = p2; 
		p2 = p2->next;
	}
	if (p2->data < p->data) {//p 代表的结点的数据项最大,插入到表尾
		p2->next = p; p->next = 0;
	}
	else {//插入到 p1 和 p2 指向的结点之间
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