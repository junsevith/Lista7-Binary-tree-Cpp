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

    std::string insertNode(T t);

    std::string deleteNode(T t);

    void draw();

    void drawLeaf();

private:
    std::string insertHere(T t, Node<T> *&node, Node<T> *parent);

    Node<T> **inParent(Node<T> *node);


};

#include "Tree.tpp"

#endif //LISTA7C_TREE_H

