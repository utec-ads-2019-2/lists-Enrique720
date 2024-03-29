#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "iterators/forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

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
            // Es mejor usar los punteros en vez del contador
            if(empty()){
                this->head = temp;
                this->tail = temp;
            }
            else{
                temp->next = this->head;
                this->head = temp;
            }
            // this->nodes++;
            this->nodes += 1;
        }

        void push_back(T value) {
            auto *temp = new Node<T>(value);
            if(empty()){
                this->head = temp;
                this->tail = temp;
            }
            else{
                this->tail->next = temp;
                this->tail = temp;
            }
            this->nodes += 1;
        }

        void pop_front() {
            auto *temp = this->head;
            // No es necesario, pero no está mal
            if(empty()) {
                throw new out_of_range("The list is empty");
            }
            else if(this->nodes == 1){
                delete this->head;
                // Dónde igualas a nullptr?
            }
            else{
                // Dónde igualas a nullptr?
                this->head = this->head->next;
                delete temp;
                this->nodes -=1;
            }
        }

        void pop_back() {
            if(empty()) {
                throw new out_of_range("The list is empty");
            }
            else if(this->nodes == 1){
                delete this->tail;
            }
            else {
                auto *temp = this->tail;
                auto *rec = this->head;
                while (rec->next != this->tail) {
                    rec = rec->next;
                }
                rec->next = nullptr;
                this->tail = rec;
                delete temp;
                this->nodes -=1;
                // Dónde igualas a nullptr?
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
            // Solo es necesario validar 1
            return this->head == nullptr && this->tail == nullptr;
        }

        int size() {
           return this->nodes;
        }

        void clear() {
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
            // No es muy eficiente
            auto* temp = this->head;
            int size=this->nodes;
            T * arr  = new T[size];
            for( int i = 0; i < size; i ++){
                arr[i] = temp->data;
                temp =temp->next;
            }
            temp = this->head;
            for(int i = size-1 ; i >= 0 ; i --){
                temp->data = arr[i];
                temp = temp->next;
            }
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            // Podría ser en una línea
            ForwardIterator<T> it(this->head);
            return it;
        }

	    ForwardIterator<T> end() {
            // Es el siguiente de tail
            ForwardIterator<T> it(this->tail);
            return it;
        }

        void merge(ForwardList<T> list) {
            int size = list.size();
            auto * temp = list.head;
            for(int i = 0; i < size; i++){
                this->push_back(temp->data);
                temp =temp->next;
            }

        }
};

#endif
