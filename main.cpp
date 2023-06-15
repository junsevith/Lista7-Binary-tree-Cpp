#include <iostream>
#include <map>
#include <functional>
#include "Tree.h"
#include "ConsoleHandler.h"

int main() {
    std::map<std::string, std::function<void(void)>> typeMap;
    typeMap.emplace("integer",[](){
        ConsoleHandler<int> handler;
    });



    std::cout << "Wybierz rodzaj drzewa ";
    ConsoleHandler<int> handler;
    handler.startTerminal();




//    Tree<std::string> tree{};
//    tree.insertNode("5");
//    tree.insertNode("7");
//    tree.insertNode("3");
//    tree.insertNode("2");
//    tree.insertNode("4");
//    tree.insertNode("6");
//    tree.insertNode("8");
//    tree.drawLeaf();
//    tree.deleteNode("5");
//    tree.drawLeaf();
//    tree.search("12");

    return 0;
}
