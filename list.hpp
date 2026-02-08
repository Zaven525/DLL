#pragma once
#include <iostream>
#include <initializer_list>


template <typename T>
struct Node
{
    T _data;
    Node<T>* _prev;
    Node<T>* _next;
    
    Node(T data) : _data(data), _next(nullptr), _prev(nullptr) {}
    Node(T data, next) : _data(data), _prev(nullptr), _next(next) {}
    Node(T data, prev, next) : _data(data), _prev(prev), _next(next) {}
};

template <typename T>
class List
{
    private:
        Node<T>* _head;
    public:
        List() : _head(T());
        List(size_t count);
        List(size_t count, const T& _data = T());
        List(const List& oter);
        List(List&& other);
        List& operator=(const List& other);
        List& operator=(List&& other);

        void assign(size_t count, const T& value);
        void assign(std::initializer_list<T> list);

};

#include "list.tpp"