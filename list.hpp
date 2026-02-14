#pragma once
#include <iostream>
#include <initializer_list>
#include <type_traits>

template <typename T>
T&& forward(std::remove_reference_t<T>& arg)
{
  return static_cast<T&&> (arg);
}
template <typename T>
T&& forward(std::remove_reference_t<T>&& arg)
{
  return static_cast<T&&> (arg);
}

template <typename T>
struct Node
{
    T _data;
    Node<T>* _prev;
    Node<T>* _next;
    
    Node(T data = T()) : _data(data), _next(nullptr), _prev(nullptr) {}
    Node(Node<T>* next, T data = T())  : _data(data), _prev(nullptr), _next(next) {}
    Node(Node<T>* prev, Node<T>* next, T data = T()) : _data(data), _prev(prev), _next(next) {}
    Node(const Node& other) : _data{other._data}, _prev{nullptr}, _next{nullptr} {}
    Node(Node&& other) noexcept : _data(std::move(other._data)), _prev(nullptr), _next(nullptr) {}
    ~Node() = default;
};

template <typename T>
class List
{
    private:
        Node<T>* _head;
        Node<T>* _tail;
    public:
        // Member functions
        List() : _head{nullptr}, _tail{nullptr} {};
        List(size_t count, const T& _data = T());
        List(const List& other);
        List(List&& other);
        List& operator=(const List& other);
        List& operator=(List&& other);
        ~List();
        void assign(size_t count, const T& value);

        // Element access
        T& front() { if (_head) return _head->_data; }
        const T& front() const { if (_head) return _head->_data; }
        T& back() { if (_tail) return _tail->_data; }
        const T& back() const { if (_tail) return _tail->_data; }
        
        // Capacity
        bool empty() const noexcept { return !_head; }
        size_t size() const noexcept;
        
        // Modifiers
        void clear();
        void insert(size_t pos, const T& value);
        void insert(size_t pos, T&& value);
        void insert(size_t pos, size_t count, const T& value );
        void erase(size_t pos);
        void erase(size_t from, size_t to);
        void push_back(const T& data);
        void push_back(T&& data);
        void pop_back();
        void push_front(const T& data);
        void push_front(T&& data);
        void pop_front();
        void swap(List<T>& other);

        template<typename ... Args>
        void emplace(size_t pos, Args&&...args);

        // Operations
        void sort();
        void merge(List<T>& other);
        void reverse();
        void print_list();
        
};

#include "list.tpp"





