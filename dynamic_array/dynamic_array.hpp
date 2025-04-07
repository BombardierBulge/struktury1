#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <iostream>
#include <stdexcept>

class ArrayList{
private:
    int* data;       
    int size;        
    int capacity;    

    void resize(int newCapacity);

public:
	ArrayList(int initCapacity = 2);
    ~ArrayList();

    void add(int value);
	void addAt(int index, int value);
    void addFirst(int value);
    int get(int index) const;
	int find(int value) const;
    void display() const;
};

#endif // DYNAMIC_ARRAY_HPP
