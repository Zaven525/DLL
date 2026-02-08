#pragma once
#include "list.hpp"

template <typename T>
List<T>::List(size_t count) 
{
    Node<T> dummy;
    Node<T>* tmp = dummy;

    for (size_t i = 0; i < count; ++i)
    {
        tmp->next = new Node T();
        tmp = tmp->next;  
    }

    _head = dummy->next;
}

