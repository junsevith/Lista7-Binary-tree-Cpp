//
// Created by pawel on 08.06.2023.
//


template<typename T>
Node<T> *Tree<T>::search(T t) {
    Node<T> *node = root;
    while (node->key != t) {
        if (t < node->key) {
            node = node->left;
        } else if (t > node->key) {
            node = node->right;
        }
    }
    return node;
}

template<typename T>
void Tree<T>::insertNode(T t) {
    insertHere(t, root, nullptr);
}

template<typename T>
void Tree<T>::insertHere(T t, Node<T> *&node, Node<T> *parent) {
    if (node == nullptr) {
        node = new Node<T>(t, parent);
    } else {
        if (t < node->key) {
            insertHere(t, node->left, node);
        } else if (t > node->key) {
            insertHere(t, node->right, node);
        }
    }

}

template<typename T>
void Tree<T>::deleteNode(T t) {

}

template<typename T>
void Tree<T>::draw() {
    root->draw();
    std::cout << std::endl;
}

template<typename T>
Tree<T>::~Tree() {
//    std::cout << "dog";
    delete root;

};