//
// Created by pawel on 08.06.2023.
//

template<typename T>
Node<T>::Node(T t, Node<T> *parent) {
    this->key = t;
    this->parent = parent;
}

template<typename T>
Node<T>::~Node() {
//    std::cout << "cat";
    delete left;
    delete right;
}

template<typename T>
void Node<T>::draw() {
    std::cout << (parent != nullptr ? parent->key : 0) << "<-" << key << " ";
    if (left != nullptr) {
        left->draw();
    }
    if (right != nullptr) {
        right->draw();
    }
}
