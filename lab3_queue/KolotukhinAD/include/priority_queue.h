#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__
#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Pair {
    T data;
    int priority;
};

template <typename T>
class TPriorityQueue
{
private:
    Pair<T>* array;
    Pair<T>* end;
    size_t arr_size;

    void addMem() {
        Pair<T>* tmp = new Pair<T>[arr_size * 2];
        std::copy(array, array + arr_size, tmp);
        delete[] array;
        array = tmp;
        end = array + arr_size;
        arr_size *= 2;
    }

    Pair<T>& getMem(int ind) {
        return array[ind];
    }

public:
    TPriorityQueue(size_t q_size = 5) {
        array = new Pair<T>[q_size];
        end = array;
        arr_size = q_size;
    }    

    TPriorityQueue(const TPriorityQueue<T> &_other) : arr_size(_other.arr_size) {
        array = new Pair<T>[arr_size];
        std::copy(_other.array, _other.array + _other.arr_size, array);
        end = array + (_other.end - _other.array);
    }

    ~TPriorityQueue() {
        delete[] array;
    }

    size_t getSize() const {
        return end - array;
    }

    bool isEmpty() const {
        return end - array == 0;
    }

    void push(const Pair<T>& pair) {
        if (end == array + arr_size) {
            addMem(); 
        }
        int i = end - array;
        while (i > 0 && array[i - 1].priority > pair.priority) {
            array[i] = array[i - 1];
            i--;
        }
        array[i] = pair;
        end++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("empty");
        }
        return (--end)->data;
    }
    
    T top() {
        if (isEmpty()) {
            throw std::out_of_range("empty");
        }
        return (end - 1)->data;
    }

    TPriorityQueue& operator=(const TPriorityQueue<T> &_other) {
        if (*this == _other) {
            return *this;
        }
        arr_size = _other.arr_size;
        delete[] array;
        array = new Pair<T>[arr_size];
        std::copy(_other.array, _other.array + _other.arr_size, array);
        end = array + (_other.end - _other.array);
        return *this;
    }

    bool operator==(const TPriorityQueue<T> &_other) const {
        if (end - array != _other.end - _other.array) {
            return false;
        }
        for (int i = 0; i < end - array; i++) {
            if (array[i].data != _other.array[i].data) {
                return false;
            }
        }
        return true;
    }

    friend ostream& operator<<(ostream& os, TPriorityQueue<T> &_queue) {
        for (size_t i = 0; i < _queue.end - _queue.array; i++) {
            os << _queue.getMem(i).data;
        }
        return os;
    }

};
#endif
