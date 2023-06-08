//
// Created by pawel on 08.06.2023.
//

#ifndef LISTA7C_TREE_H
#define LISTA7C_TREE_H


#include "Node.h"

template<typename T>
class Tree {
public:
    Tree() = default;
    ~Tree();

    Node<T>* root;

    Node<T>* search(T t);

    void insertNode(T t);

    void deleteNode(T t);

    void draw();

private:
    void insertHere(T t, Node<T> *&node, Node<T> *parent);
};


#endif //LISTA7C_TREE_H

#include "Tree.tpp"