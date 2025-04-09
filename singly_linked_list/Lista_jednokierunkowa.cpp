#include "Lista_jednokierunkowa.hpp"
#include <string>

List::List() : head(nullptr), tail(nullptr) {}

List::~List()
{
	Node *current = head;
	while (current != nullptr)
	{
		Node *toDelete = current;
		current = current->next;
		delete toDelete;
	}
}

void List::addFirst(int value)
{
	Node *newNode = new Node(value);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

void List::addLast(int value)
{
	Node *newNode = new Node(value);
	if (head == nullptr)
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

void List::addAt(int value, int index)
{
	if (index == 0)
	{
		addFirst(value);
		return;
	}

	Node *current = head;
	for (int i = 0; i <= index - 1; i++)
	{
		if (current == nullptr)
		{
			throw std::out_of_range("Index out of range: " + std::to_string(index));
		}
		current = current->next;
	}

	Node *newNode = new Node(value, current->next);
	current->next = newNode;

	if (newNode->next == nullptr)
	{
		tail = newNode;
	}
}

void List::deleteFirst()
{
	if (head == nullptr)
	{
		throw std::runtime_error("List is empty");
	}

	Node *toDelete = head;
	head = head->next;
	delete toDelete;

	if (head == nullptr)
	{
		tail = nullptr;
	}
}

void List::deleteLast()
{
	if (head == nullptr)
	{
		throw std::runtime_error("List is empty");
	}

	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
		return;
	}

	Node *current = head;
	while (current->next != tail)
	{
		current = current->next;
	}

	delete tail;
	tail = current;
	tail->next = nullptr;
}

void List::deleteValue(int value)
{
	if (head == nullptr)
	{
		throw std::runtime_error("List is empty");
	}

	if (head->value == value)
	{
		deleteFirst();
		return;
	}

	Node *current = head;
	while (current->next != nullptr && current->next->value != value)
	{
		current = current->next;
	}

	if (current->next == nullptr)
	{
		throw std::runtime_error("Value not found in the list");
	}

	Node *toDelete = current->next;
	current->next = toDelete->next;
	delete toDelete;

	if (current->next == nullptr)
	{
		tail = current;
	}
}

void List::deleteAt(int index)
{
	if (index < 0)
	{
		throw std::out_of_range("Index out of range");
	}

	if (head == nullptr)
	{
		throw std::runtime_error("List is empty");
	}

	if (index == 0)
	{
		deleteFirst();
		return;
	}

	Node *current = head;
	for (int i = 0; i < index - 1; i++)
	{
		if (current == nullptr || current->next == nullptr)
		{
			throw std::out_of_range("Index out of range");
		}
		current = current->next;
	}

	Node *toDelete = current->next;
	if (toDelete == nullptr)
	{
		throw std::out_of_range("Index out of range");
	}

	current->next = toDelete->next;
	delete toDelete;

	if (current->next == nullptr)
	{
		tail = current;
	}
}

List::Node *List::search(int value) const
{
	Node *current = head;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

void List::print() const
{
	Node *current = head;
	while (current != nullptr)
	{
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}