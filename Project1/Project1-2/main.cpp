#include <iostream>

using namespace std;

typedef struct node
{
	struct student
	{
		int id;
		char grade;
	} d;
	struct node* next;
} node;

node* head = NULL;

void print_node(void) {
	node* cur = head;
	while (cur != NULL)
	{
		cout << cur->d.id << " / " << cur->d.grade << endl;
		cur = cur->next;
	}
}

void insert_node(int _id, char _grade) {

	node* new_node = new node;
	new_node->d.id = _id;
	new_node->d.grade = _grade;
	new_node->next = NULL;

	if (head == NULL) head = new_node;
	else
	{
		node* cur = head;
		node* pre = head;
		while (cur != NULL)
		{
			if ((cur->d.id) > _id) break;
			pre = cur;
			cur = cur->next;
		}
		new_node->next = cur;
		if (cur != pre) pre->next = new_node;
		else head = new_node;
	}
}

void delete_node(int _id) {
	node* cur = head;
	node* pre = head;
	while (cur != NULL)
	{
		if ((cur->d.id) == _id) {
			if (cur == head) head = cur->next;
			else pre->next = cur->next;

			delete cur;
			break;
		}
		pre = cur;
		cur = cur->next;
	}
}

int main(void) {
	insert_node(201901, 'A');
	insert_node(201903, 'B');
	insert_node(201902, 'C');
	insert_node(201905, 'F');

	print_node();
	cout << endl;
	delete_node(201905);

	print_node();
	return 0;
}