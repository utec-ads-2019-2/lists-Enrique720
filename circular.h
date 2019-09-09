#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            return this->head->data;
        }

        T back() {
            return this->tail->data;
        }

        void push_front(T value) {

        }

        void push_back(T value) {

        }

        void pop_front() {

        }

        void pop_back() {

        }

        T operator[](int index) {

        }

        bool empty() {
            return this->head == nullptr && this->tail == nullptr;
        }

        int size() {
            return this->nodes;
        }

        void clear() {

        }

        void sort() {

        }
    
        void reverse() {

        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {

        }

	    BidirectionalIterator<T> end() {

        }

        void merge(CircularLinkedList<T> list) {

        }
};

#endif
