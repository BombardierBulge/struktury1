#pragma once

struct Node {
	int value;
	Node* next;
};

struct List {
	Node* head = nullptr;
	Node* tail = nullptr;
};
int main();

