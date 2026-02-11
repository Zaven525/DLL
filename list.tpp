#pragma once
#include "list.hpp"


//Member functions
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
    if (this == &other) return *this;
    
    while(_head)
    {
        Node<T>* _next = _head->_next;
        delete _head;
        _head = _next;
    }
    _tail = nullptr;

    Node<T>* cur = other._head;
    while(cur)
    {
        if (!_head)
        {
            _head = new Node<T>{cur->_data};
            _tail = _head;
            _head->_prev = nullptr;
        }
        
        else
        {
            _tail->_next = new Node<T>{cur->_data};
            _tail->_next->_prev = _tail;
            _tail = _tail->_next;
        }
        cur = cur->_next;
    }

    if (_tail) _tail->_next = nullptr;
    
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& other)
{
    if (this == &other) return *this;

    while (_head)
    {
        Node<T>* _next = _head->_next;
        delete _head;
        _head = _next;
    }
    _head = other._head;
    _tail = other._tail;
    other._head = other._tail = nullptr;
    return *this;
}


template <typename T>
List<T>::~List()
{
    clear();
}

template <typename T>
void List<T>::assign(size_t count, const T& value)
{
    Node<T>* cur = _head;
    size_t i = 0;
    while (cur && i < count)
    {
        cur->_data = value;
        cur = cur->_next;
        ++i;
    }

    while (i < count)
    {
        Node<T>* n = new Node<T>{value};

        if (!_head)
        {
            _head = _tail = n;
            n->_prev = nullptr;
        }

        else
        {
            n->_prev = _tail;
            _tail->_next = n;
            _tail = n;
        }

        i++;
    }

    while (cur)
    {
        Node<T>* next = cur->_next;
        delete cur;
        cur = next;
    }

    if (_tail) _tail->_next = nullptr;

}

// Element access

// Capacity
template <typename T>
size_t List<T>::size() const noexcept
{
    Node<T>* cur = _head;
    size_t size = 0;
    while (cur)
    {
        ++size;
        cur = cur->_next;
    }

    return size;
}


// Modifiers
template <typename T>
void List<T>::clear()
{
    while (_head)
    {
        Node<T>* next = _head->_next;
        delete _head;
        _head = next;
    }
}

template <typename T>
void List<T>::insert(size_t pos, const T& value)
{
    if (pos > size()) return;
    if (pos == 0) 
    {
        Node<T>* n = new Node<T>{value};
        n->_next = _head;
        n->_prev = nullptr;
        if(_head) _head->_prev = n;
        _head = n;
        if (!_tail) _tail = _head;
        return;
    }
    
    Node<T>* cur = _head;
    for (size_t i{0}; i < pos - 1; i++)
    {
        cur = cur->_next;
    } 

    Node<T>* n = new Node<T>{value};
    if (cur->_next) cur->_next->_prev = n;
    n->_next = cur->_next;
    n->_prev = cur;
    cur->_next = n;
    if (n->_next == nullptr) _tail = n;
}

template <typename T>
void List<T>::insert(size_t pos, T&& value)
{
    if (pos > size()) return;
    if (pos == 0) 
    {
        Node<T>* n = new Node<T>{std::move(value)};
        n->_next = _head;
        n->_prev = nullptr;
        if(_head) _head->_prev = n;
        _head = n;
        if (!_tail) _tail = _head;
        return;
    }
    
    Node<T>* cur = _head;
    for (size_t i{0}; i < pos - 1; i++)
    {
        cur = cur->_next;
    } 

    Node<T>* n = new Node<T>{std::move(value)};
    if (cur->_next) cur->_next->_prev = n;
    n->_next = cur->_next;
    n->_prev = cur;
    cur->_next = n;
    if (n->_next == nullptr) _tail = n;
}

template<typename T>
void List<T>::insert(size_t pos, size_t count, const T& value)
{
    for (size_t i{0}; i < count; ++i)
    {
        insert(i+pos, value);
    }
}

template <typename T>
void List<T>::print_list()
{
    Node<T>* cur = _head;
    while (cur) { 
        std::cout << cur->_data; 
        cur = cur->_next;
    }
}