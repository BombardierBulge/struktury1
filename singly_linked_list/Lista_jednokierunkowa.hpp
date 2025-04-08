#pragma once

struct Node {
	int value;
	Node* next;
};

struct List {
	Node* head = nullptr;
	Node* tail = nullptr;
};

void Addvaluefirst(List& list, int value);
void Addvaluelast(List& list, int value);
void Addvalue(List& list, int value, int index);
void deletefirstvalue(List& list);
void deletelastvalue(List& list);
void deletevalue(List& list, int value);
Node* search(List& list, int value);
void PrintList(List& list);
