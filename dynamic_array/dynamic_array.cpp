#include "dynamic_array.hpp"

ArrayList::ArrayList(int initCapacity) : size(0), capacity(initCapacity)
{
	data = new int[capacity];
}

ArrayList::~ArrayList()
{
	delete[] data;
}

void ArrayList::resize(int newCapacity)
{
	int *temp = new int[newCapacity];
	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}
	delete[] data;
	data = temp;
	capacity = newCapacity;
}

void ArrayList::add(int value)
{
	if (size >= capacity)
	{
		resize(2 * capacity);
	}
	data[size++] = value;
}

void ArrayList::addFirst(int value)
{
	addAt(0, value); 
}

void ArrayList::addAt(int index, int value)
{
	if (index < 0 || index > size)
	{
		add(value);
	}
	if (size == capacity)
	{
		resize(2 * capacity);
	}
	for (int i = size; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = value;
	size++;
}

int ArrayList::get(int index) const
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index z poza zakresu tablicy");
	}
	return data[index];
}

int ArrayList::find(int value) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void ArrayList::display() const
{
	std::cout << "Ilosc elementow: " << size << std::endl
			  << "Rozmiar tablicy: " << capacity << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void ArrayList::removeLast()
{
	if (size == 0)
	{
		throw std::out_of_range("Lista jest pusta, nie można usunąć ostatniego elementu.");
	}
	size--;
}
void ArrayList::removeAt(int index)
{
	if (index < 0 || index >= size)
	{
		throw std::out_of_range("Index z poza zakresu tablicy");
	}

	for (int i = index; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
}
void ArrayList::removeFirst()
{
	if (size == 0)
	{
		throw std::out_of_range("Lista jest pusta, nie można usunąć pierwszego elementu.");
	}

	for (int i = 0; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
}