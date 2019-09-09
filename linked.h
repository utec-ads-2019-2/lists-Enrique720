#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : List<T>() {}

    T front() {
        if( this->head != nullptr){
            return this->head->data;
        } throw new out_of_range("The list is empty");
    }

    T back() {
        if( this->tail != nullptr){
            return this->tail->data;
        } throw new out_of_range("The list is empty");
    }

    void push_front(T value) {
        auto *temp = new Node<T>(value);
        if(empty()){
            this->head = temp;
            this->tail = temp;
        }
        else{
            temp->next = this->head;
            this->head->prev = temp;
            this->head = temp;
        }

        this->nodes += 1;
    }

    void push_back(T value) {
        auto *temp = new Node<T>(value);
        if(empty()){
            this->head = temp;
            this->tail = temp;
        }
        else{
            temp->prev = this->tail;
            this->tail->next = temp;
            this->tail = temp;
        }
        this->nodes +=1;
    }

    void pop_front() {
        if(empty()){
            throw new out_of_range("The list is empty");
        }else {
            auto *temp = this->head;
            this->head = this->head->next;
            this->head->prev = nullptr;
            delete temp;
            this->nodes -= 1;
        }
    }

    void pop_back() {
        if(empty()){
            throw new out_of_range("The list is empty");
        }else {
        auto *temp =this ->tail ;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        delete temp;
        this->nodes -=1;
    }
    }

    T operator[](int index) {
        if(index >= this->nodes){
            throw new out_of_range("Out of range");
        }
        else{
            auto*temp = this->head;
            for(int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp->data;
        }
    }

    bool empty() {
        return this->head == nullptr && this->tail == nullptr;
    }

    int size() {
        return this->nodes;
    }

    void clear() {
        auto *temp = this->tail;

    }

    void sort() {
        auto* temp = this->head;
        int size = this->nodes;
        T * arr = new T[size];
        for(int i  = 0; i <size; i++){
            arr[i] = temp->data;
            temp = temp->next;
        }
        // shell sort
        for (int gap =size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i += 1) {
                int t = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > t; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = t;
            }
        }
        temp = this->head;
        for(int i  = 0; i <size; i++){
            temp->data = arr[i];
            temp->next;
        }
    }

    void reverse() {
        auto* temp = this->head;
        int size=this->nodes;
        T * arr  = new T[size];
        for( int i = 0; i < size; i ++){
            arr[i] = temp->data;
            temp =temp->next;
        }
        temp = this->head;
        for(int i = size-1 ; i >= 0 ; i ++){
            temp->data = arr[i];
        }
    }

    string name() {
        return "Linked List";
    }

    BidirectionalIterator<T> begin() {
        // TODO
    }

    BidirectionalIterator<T> end() {
        // TODO
    }

    void merge(LinkedList<T> list) {
        int size = list.size();
        auto * temp = list.head;
        for(int i = 0; i < size; i++){
            this->push_back(temp->data);
            temp =temp->next;
        }
    }
};

#endif
