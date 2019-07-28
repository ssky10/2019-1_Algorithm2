#include <iostream>

using namespace std;

typedef struct Node {
	struct {
		int code;
		char grade;
	} s;
	struct Node *next;
} node;

node* head;

void print_node() {
	node* cur = head;
	while (cur != NULL)
	{
		cout << cur->s.code << '/' << cur->s.grade << endl;
		cur = cur->next;
	}
}

void delete_node(int _code) {
	node** pre = &head;
	node* cur = head;

	while (cur != NULL)
	{
		if (cur->s.code == _code) {
			*pre = cur->next;
			delete cur;
			break;
		}
		pre = &(cur->next);
		cur = cur->next;
	}
}

void insert_node(int _code, char _grade) {
	node* new_node = new node;
	new_node->s.code = _code;
	new_node->s.grade = _grade;
	new_node->next = NULL;

	node** pre = &head;
	node* cur = head;

	while (cur != NULL)
	{
		if (cur->s.code > _code) {
			break;
		}
		pre = &(cur->next);
		cur = cur->next;
	}

	new_node->next = cur;
	*pre = new_node;
}

int main() {
	insert_node(201901, 'A');
	insert_node(201903, 'B');
	insert_node(201902, 'C');

	print_node();

	cout << endl;

	delete_node(201902);

	print_node();
	return 0;
}