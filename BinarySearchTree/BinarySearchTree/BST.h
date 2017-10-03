#pragma once

template<class T>
typedef struct Node_T
{
    int key;
    T value;
    Node_T* left;
    Node_T* right;
};

template <class T>
class BST
{
private:
    Node_T<T> Tree;

public:
    void Insert( int key, T val);
};
