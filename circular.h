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
            auto* temp = new Node<T>(value);
            if(empty()){
                this->head = temp;
                this->tail = temp;
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }
            else{
                temp->next = this->head;
                temp->prev = this->tail;
                this->head->prev = temp;
                this->tail->next = temp;
                this->head = temp;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto* temp = new Node<T>(value);
            if(empty()){
                this->head = temp;
                this->tail = temp;
                this->head->prev = this->tail;
                this->tail->next = this->head;
            }else{
                temp->prev = this->tail;
                this->tail->next= temp;
                temp->next = this->head;
                this->head->prev= temp;
                this->tail = temp;
            }
            this->nodes++;
        }

        void pop_front() {
            if(empty()) {
                throw new out_of_range("The list is empty");
            }
            else if(this->nodes ==1){
                delete this->head;
                this->head == nullptr;
                this->tail == nullptr;
                this->nodes = 0;
            }
            else{
                auto* temp = this->head;
                this->tail->next = this->head->next;
                this->head->next->prev = this->tail;
                this->head = this->head->next;
                delete temp;
                this->nodes--;
            }
        }

        void pop_back() {
            if(empty()) {
                throw new out_of_range("The list is empty");
            }
            else if(this->nodes ==1){
                delete this->head;
                this->head == nullptr;
                this->tail == nullptr;
                this->nodes = 0;
            }
            else{
                auto* temp = this->tail;
                this->head->prev = this->tail->prev;
                this->tail->prev->next = this->head;
                this->tail = this->tail->prev;
                delete temp;
                this->nodes--;
            }
        }

        T operator[](int index) {
                int lim = index % (this->nodes);
                auto *dat = this->head;
                for (int i = 0; i < lim; i++) {
                    dat = dat->next;
                }
                return dat->data;
        }
        bool empty() {
            return this->head == nullptr && this->tail == nullptr;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->tail->next = nullptr;
            this->head->killSelf();
            this->nodes = 0;
            this->head = nullptr;
            this->tail = nullptr;
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
                temp = temp->next;
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
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {

        }

	    BidirectionalIterator<T> end() {

        }

        void merge(CircularLinkedList<T> list) {
            int size = list.size();
            auto * temp = list.head;
            for(int i = 0; i < size; i++){
                this->push_back(temp->data);
                temp =temp->next;
            }
        }
};

#endif
