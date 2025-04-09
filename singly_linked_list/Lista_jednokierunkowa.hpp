#ifndef LISTA_JEDNOKIERUNKOWA_HPP
#define LISTA_JEDNOKIERUNKOWA_HPP

#include <iostream>

class List {
private:
    struct Node {
        int value;
        Node* next;

        Node(int val, Node* nextNode = nullptr) : value(val), next(nextNode) {}
    };

    Node* head;
    Node* tail;

public:
    
    List();
    ~List();

  
    void addFirst(int value);
    void addLast(int value);
    void addAt(int value, int index);
    void deleteFirst();
    void deleteLast();
    void deleteValue(int value);
    void deleteAt(int index); 
    Node* search(int value) const;
    void print() const;
};

#endif // LISTA_JEDNOKIERUNKOWA_HPP
