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

        if (node == nullptr) {
            return nullptr;
        }
    }
    return node;
}

template<typename T>
std::string Tree<T>::insertNode(T t) {
    return insertHere(t, root, anchor);
}

template<typename T>
std::string Tree<T>::insertHere(T t, Node<T> *&node, Node<T> *parent) {
    if (node == nullptr) {
        node = new Node<T>(t, parent);
        return "Dodano element";
    } else {
        if (t < node->key) {
            return insertHere(t, node->left, node);
        } else if (t > node->key) {
            return insertHere(t, node->right, node);
        } else {
            return "Podany element znajduje się już w drzewie";
        }
    }

}

template<typename T>
std::string Tree<T>::deleteNode(T t) {
    Node<T> *node = search(t);
    if (node == nullptr) {
        return "Nie znaleziono elementu do usunięcia";
    }

    if (node->left == nullptr && node->right == nullptr) {
        *inParent(node) = nullptr;
    } else {
        Node<T> *replacement;
        if (node->left == nullptr || node->right == nullptr) {
            replacement = (node->left != nullptr) ? node->left : node->right;
        } else {
            replacement = node->right;
            while (replacement->left != nullptr) {
                replacement = replacement->left;
            }
        }

        *inParent(replacement) = replacement->right;
        if (replacement->right != nullptr) {
            replacement->right->parent = replacement->parent;
        }

        *inParent(node) = replacement;
        if (node == root) {
            root = replacement;
        }

        replacement->parent = node->parent;
        replacement->right = (replacement != node->right) ? node->right : replacement->right;
        replacement->left = node->left;

        if (replacement->left != nullptr) {
            replacement->left->parent = replacement;
        }
        if (replacement->right != nullptr) {
            replacement->right->parent = replacement;
        }
    }
    node->left = nullptr;
    node->right = nullptr;
    delete node;
    return "Usunięto element";
}

template<typename T>
Node<T> **Tree<T>::inParent(Node<T> *node) {
    return (node == node->parent->left) ? &node->parent->left : &node->parent->right;
}

template<typename T>
void Tree<T>::draw() {
    root->draw();
//    std::cout << std::endl;
}

template<typename T>
void Tree<T>::drawLeaf() {
    root->drawLine("");
    std::cout << std::endl;
}

template<typename T>
Tree<T>::~Tree() {
//    std::cout << "dog";
    delete root;
}