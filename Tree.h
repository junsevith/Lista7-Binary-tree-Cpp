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

    Node<T> *root;
    Node<T> *anchor = new Node<T>();

    Node<T> *search(T t);

    void insertNode(T t);

    void deleteNode(T t);

    void draw();

    void drawLeaf();

private:
    void insertHere(T t, Node<T> *&node, Node<T> *parent);

    Node<T> **inParent(Node<T> *node);


};


#endif //LISTA7C_TREE_H

#include "Tree.tpp"