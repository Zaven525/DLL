#pragma once
#include "list.hpp"

template <typename T>
List<T>::List(size_t count) 
{
    Node<T> dummy;
    Node<T>* tmp = &dummy;

    for (size_t i = 0; i < count; ++i)
    {
        tmp->_next = new Node<T>();
        tmp->_next->prev = tmp;
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
List<T>::List(const List& other)
{
    Node<T> dummy;
    Node<T>* tmp = &dummy;
    Node<T>* tmpo = other._head;
    
    while (tmpo != nullptr)
    {
        tmp->_next = new Node<T>(tmpo->_data);
        tmp->_next->_prev = tmp;
        tmpo = tmpo->_next;
        tmp = tmp->_next;
    }

    _head = dummy._next;
    if (_head)
    {
        _head->prev = nullptr;
        _tail = tmp;
    }
}

