#ifndef __LIST_H__
#define __LIST_H__
#pragma once
#include <iostream>
#include "iterator.h"
using namespace std;

template <typename T>
class List: private Iterator<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : next(nullptr), data(value) {};
    };
    Node* head;
    size_t size;
    Node* nodeN;
public:
    List() : head(nullptr), nodeN(nullptr), size(0) {}

    List(const List &_other) : head(nullptr), nodeN(nullptr), size(0) {
        for (int i = 0; i < _other.size; i++) {
            this->pushBack(_other[i]);
        }
    }

    ~List() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int getSize() const 
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    void pushFront(T _data) {
        Node* new_head = new Node(_data);
        if (head == nullptr) {
            head = new_head;
        } else {
            new_head->next = head;
            head = new_head;
        }
        size++;
    }

    void pushBack(T _data) {
        Node* newNode = new Node(_data);
        if (head == nullptr) {
            head = newNode;
            nodeN = head;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void addTo(int index, T _data) {
        if (index == 0) { 
            pushFront(_data);
        } else if (index == size) {
            pushBack(_data);
        } else {
            Node* node = head;
            for (int i = 0; i < index - 1; i++) {
                if (!node) throw out_of_range("out_of_range");
                node = node->next;
            }
            Node* new_node = new Node(_data);
            new_node->next = node->next;
            node->next = new_node;
            size++;
        }
    }

    void removeFrom(int index) {
        if (index < 0 || index > size - 1)
        {
            throw out_of_range("index out of range");
        }

        if(size != 0) {
            if (index == 0) {
                Node* node_1 = head;
                head = head->next;
                delete node_1;
            } else {
                Node* node = head;
                
                while (index-- > 1)
                    node = node->next;
                
                Node* node_1 = node->next;
                node->next = node_1->next;
                delete node_1;
            }
        }
        size--;
    }

    void print() {
            while (this->hasNext()) 
                cout << "(" << this->next() << ") ";
            nodeN = head;
        }

    T& operator[](int index) const 
    {
        if (index < 0) throw out_of_range("out_of_range");
        Node* node = head;
        for (int i = 0; i < index; i++) {
            if (!node) throw out_of_range("out_of_range");
            node = node->next;
        }
        return node->data;
    }

    List& operator=(const List& other)
    {
        if (this != &other)
        {
            while (head != nullptr)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            head = nullptr;
            size = 0;
            for (int i = 0; i < other.size; i++)
                this->pushBack(other[i]);
        }
        return *this;
    }

    private: bool hasNext() override 
    {
        return (nodeN != NULL);
    }

    private: T& next() override {
        Node* n = nodeN;
        nodeN = nodeN->next;
        return n->data;
    }
};
#endif
