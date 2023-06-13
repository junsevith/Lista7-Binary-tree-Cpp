//
// Created by pawel on 08.06.2023.
//

template<typename T>
Node<T>::Node(T t, Node<T> *parent) {
    this->key = t;
    this->parent = parent;
}
template<typename T>
Node<T>::Node() {
    this->parent = nullptr;
}

template<typename T>
Node<T>::~Node() {
//    std::cout << "cat";
    delete left;
    delete right;
}

template<typename T>
void Node<T>::draw() {
    std::cout << (parent != nullptr ? parent->key : "") << "<-" << key << " ";
    if (left != nullptr) {
        left->draw();
    }
    if (right != nullptr) {
        right->draw();
    }
}

template<typename T>
void Node<T>::drawLine(const std::string& line) {
    std::string message = line + key + " ";
    if (left == nullptr && right == nullptr){
        std::cout << message << std::endl;
    } else{
        if (right != nullptr) {
            right->drawLine(message + "⭧ ");
        }
        if (left != nullptr) {
            left->drawLine(message + "⭨ ");
        }
    }

}