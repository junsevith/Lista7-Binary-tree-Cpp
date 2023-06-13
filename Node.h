//
// Created by pawel on 08.06.2023.
//

#ifndef LISTA7C_NODE_H
#define LISTA7C_NODE_H


template<typename T>
class Node {
public:

    Node();

    Node(T t, Node<T> *parent);
    ~Node();

    T key;
    Node<T>* parent;
    Node<T>* left = nullptr;
    Node<T>* right = nullptr;

    void draw();


    void drawLine(const std::string& line);
};


#endif //LISTA7C_NODE_H

#include "Node.tpp"
