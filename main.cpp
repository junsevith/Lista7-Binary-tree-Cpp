#include <iostream>
#include "Tree.h"

int main() {
    Tree<std::string> tree{};
    tree.insertNode("5");
    tree.insertNode("7");
    tree.insertNode("3");
    tree.insertNode("2");
    tree.insertNode("4");
    tree.insertNode("6");
    tree.insertNode("8");
    tree.drawLeaf();
    tree.deleteNode("5");
    tree.drawLeaf();

    return 0;
}
