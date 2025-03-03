#ifndef __QUEUE_TWO_STACK_H__
#define __QUEUE_TWO_STACK_H__
#pragma once

#include <stack>

using namespace std;

template <typename T>
class TTwoStackQueue
{
private:
    size_t size;
    stack<T> leftStack;
    stack<T> rightStack;
public:
    TTwoStackQueue() : size(0) {}

    TTwoStackQueue(const TTwoStackQueue<T> &_other) : size(_other.size), leftStack(_other.leftStack), rightStack(_other.rightStack) {}

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void push(const T& val) {
        leftStack.push(val);
        size++;
    }

    T pop() {
        if (size == 0) {
            throw "empty";
        }
        if (rightStack.empty()) {
            while (!leftStack.empty()) {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        }
        T val = rightStack.top();
        rightStack.pop();
        size--;
        return val;
    }
    
    T top() {
        if (size == 0) {
            throw "empty";
        }
        if (rightStack.empty()) {
            while (!leftStack.empty()) {
                rightStack.push(leftStack.top());
                leftStack.pop();
            }
        }
        return rightStack.top();
    }

    TTwoStackQueue<T>& operator=(const TTwoStackQueue<T> &_other) {
		if (this == &_other) {
		    return *this;
		}
		rightStack = _other.rightStack;
        leftStack = _other.leftStack;
        size = _other.size;
        return *this;
    }

    bool operator==(const TTwoStackQueue<T> &_other) const {
        if (size != _other.size) {
            return false;
        }
        if (areStacksEqual(leftStack, _other.leftStack) && areStacksEqual(rightStack, _other.rightStack)) {
            return true;
        }
        return true;
	}
private:
    bool areStacksEqual(stack<T> stack1, stack<T> stack2) const {
        if (stack1.size() != stack2.size()) {
            return false;
        }
        while (!stack1.empty()) {
            if (stack1.top() != stack2.top()) {
                return false;
            }
            stack1.pop();
            stack2.pop();
        }
        return true;
    }
};
#endif