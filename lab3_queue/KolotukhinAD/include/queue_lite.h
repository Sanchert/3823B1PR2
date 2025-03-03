#ifndef __QUEUE_LITE_H__
#define __QUEUE_LITE_H__
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class TQueue {
	T* mem;
	T* begin;
	T* end;
	size_t mem_size;

public:
	TQueue(size_t size = 1): mem_size(size) {
		mem = new T[mem_size];
		begin = mem;
		end = mem;
	}

	TQueue(const TQueue &_other): mem_size(_other.mem_size) {
		mem = new T[mem_size];
		size_t size = _other.end - _other.mem;
		std::copy(_other.mem, _other.mem + _other.mem_size, mem);
		begin = mem;
		end = mem + size;
	}

	~TQueue() {
		delete[] mem;
	}

	void Push(T element) {
		if (end == mem + mem_size) {
			T* copyMem = new T[mem_size * 2];
			std::copy(mem, end, copyMem);
			delete[] mem;
			mem = copyMem;
			begin = mem;
			end = mem + mem_size;
			mem_size *= 2;
		}
		*end = element;
		end++;
	}

	T top() {
		if (isEmpty()) {
			throw ("empty");
		}
		return *(begin);
	}

	T pop() {
		if (isEmpty()) {
			throw ("empty");
		}
		return *(++begin - 1);
	}
	
	bool isEmpty() const {
		return mem == end;
	}

	size_t getSize() const {
		return mem_size;
	}

	TQueue& operator=(const TQueue &_other) {
		if (this == &_other) {
			return *this;
		}
		delete[] mem;
		mem_size = _other.mem_size;
		mem = new T[mem_size];
		int elements = _other.end - _other.mem;
		std::copy(_other.mem, _other.mem + elements, mem);
		begin = mem;
		end = mem + elements;
		return *this;
	}

	bool operator==(const TQueue<T> &_other) const {
		if (end - mem != _other.end - _other.mem) {
			return false;
		}
		for (size_t i = 0; i < end - mem; i++) {
			if (mem[i] != _other.mem[i]) {
				return false;
			}
		}
		return true;
	}

	friend ostream& operator<<(ostream& os, const TQueue &_queue) {
		for (size_t i = 0; i < _queue.end - _queue.mem; i++) {
			os << _queue.mem[i] << " ";
		}
		return os;
	}
};
#endif