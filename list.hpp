#pragma once
#include <iostream>
#include <initializer_list>


template <typename T>
struct Node
{
    T _data;
    Node<T>* _prev;
    Node<T>* _next;
    
    Node(T data = T()) : _data(data), _next(nullptr), _prev(nullptr) {}
    Node(Node<T>* next, T data = T())  : _data(data), _prev(nullptr), _next(next) {}
    Node(Node<T>* prev, Node<T>* next, T data = T()) : _data(data), _prev(prev), _next(next) {}
};

template <typename T>
class List
{
    private:
        Node<T>* _head;
        Node<T>* _tail;
    public:
        List() : _head{nullptr}, _tail{nullptr} {};
        List(size_t count, const T& _data = T());
        List(const List& other);
        List(List&& other);
        List& operator=(const List& other);
        List& operator=(List&& other);
        ~List();

        void assign(size_t count, const T& value);
        void assign(std::initializer_list<T> list);

        void print_list();
};

#include "list.tpp"