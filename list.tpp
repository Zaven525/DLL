#pragma once
#include "list.hpp"

template <typename T>
List<T>::List(size_t count, const T& _data) 
{
    Node<T> dummy;
    Node<T>* tmp = &dummy;

    for (size_t i = 0; i < count; ++i)
    {
        tmp->_next = new Node<T>(_data);
        tmp->_next->_prev = tmp;
        tmp = tmp->_next;  
    }

    _head = dummy._next;

    if (_head)
    {
        _head->_prev = nullptr;
        _tail = tmp;
    }
}

template <typename T>
List<T>::List(const List& other) : _head{nullptr}, _tail{nullptr}
{
    Node<T>* cur = other._head;

    while(cur)
    {
        if (!_head)
        {
            _head = new Node<T>(cur->_data);
            _tail = _head;
            _head->_prev = nullptr;
        }

        else
        {
            _tail->_next = new Node<T>(cur->_data);
            _tail->_next->_prev = _tail;
            _tail = _tail->_next;

        }
        cur = cur->_next;

        if (_tail) _tail->_next = nullptr;

    }
}

template <typename T>
List<T>::List(List&& other) : _head{other._head}, _tail{other._tail}
{
    other._head = nullptr;
    other._tail = nullptr;
}

template <typename T>
List<T>& List<T>::operator=(const List& other) 
{
    if (*this != other)
    {
        Node<T>* cur = other._head;
        this->~List();
        while(cur)
        {
            
        }
    }
}


template <typename T>
List<T>::~List()
{
    while (_head)
    {
        Node<T>* next = _head->_next;
        delete _head;
        _head = next;
    }
}

template <typename T>
void List<T>::print_list()
{
    Node<T>* cur = _head;
    while (cur) { 
        std::cout << _head->_data; 
        cur = cur->_next;
    }
}