#include <iostream>
#include "Tree.h"

int main() {
//    auto* tree = new Tree<int>();
//    tree->insertNode(5);
    Tree<int> tree{};
    tree.insertNode(5);
    tree.insertNode(7);
    tree.insertNode(3);
    tree.insertNode(2);
    tree.insertNode(4);
    tree.insertNode(6);
    tree.insertNode(8);
    tree.draw();
    std::cout << tree.search(8);

    return 0;
}
