#include <iostream>
#include "Lista_jednokierunkowa2.h"


using namespace std;

static void Addvaluefirst(List& list, int value) {
	Node* first = new Node{ value, nullptr };

	if (list.head == nullptr)
		list.head = list.tail = first;
	else {
		first->next = list.head;
		list.head = first;
	}

}

static void Addvaluelast(List& list, int value) {
	Node* last = new Node{ value, nullptr };


	if (list.head == nullptr)
		list.head = list.tail = last;
	else {
		list.tail->next = last;
		list.tail = last;
	}
}

static void Addvalue(List& list, int value, int index) {
	Node* node = new Node{ value };

	if (list.head == nullptr) {
		list.head = node;
		list.tail = node;
		return;
	}

	if (index == 0) {
		node->next = list.head;
		list.head = node;
		return;
	}

	int i = 0;
	Node* current = list.head;
	while (current != nullptr) {
		if (index - 1 == i) {
			node->next = current->next;
			current->next = node;

			if (current == list.tail) {
				list.tail = node;
			}
			return;
		}

		i++;
		current = current->next;
	}

	list.tail->next = node;
	list.tail = node;
}

static void deletefirstvalue(List& list) {
	Node* first = list.head;

	if (list.head == nullptr) {
		cout << "brak wartosci" << endl;
	}
	else {
		Node* toDelete = list.head;
		list.head = list.head->next;
		delete toDelete;
		if (list.head == nullptr)
			list.tail = nullptr;
	}
}

static void deletelastvalue(List& list) {
	Node* last = list.head;

	if (list.head == nullptr) {
		cout << "brak wartosci" << endl;
	}
	else if (list.head == list.tail) {
		delete list.head;
		list.head = list.tail = nullptr;
	}
	else {
		while (last != nullptr) {
			if (last->next == list.tail) {
				Node* toDelete = list.tail;
				list.tail = last;
				delete toDelete;
				last->next = nullptr;
				return;
			}
			last = last->next;
		}

		if (list.head == nullptr)
			list.tail = nullptr;
	}
}

static void deletevalue(List& list, int value) {
	Node* current = list.head;

	if (current != nullptr && current->value == value) {
		list.head = current->next;
		delete current;

		if (list.head == nullptr) {
			list.tail = nullptr;
		}
		return;
	}

	while (current != nullptr && current->next != nullptr) {
		if (current->next->value == value) {
			Node* toDelete = current->next;
			current->next = toDelete->next;
			delete toDelete;

			if (current->next == nullptr) {
				list.tail = current;
			}
			return;
		}
		current = current->next;
	}
}

static Node* search(List& list, int value) {
	Node* point = list.head;
	while (point != nullptr && point->value != value)
		point = point->next;
	return point;
}

void PrintList(List& list) {
	Node* curr = list.head;
	while (curr != nullptr) {
		cout << curr->value << endl;
		curr = curr->next;
	}
}

int main() {

}

