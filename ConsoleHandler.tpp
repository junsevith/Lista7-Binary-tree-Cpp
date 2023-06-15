//
// Created by pawel on 15.06.2023.
//


#include <sstream>
#include <set>
#include "ConsoleHandler.h"

template<typename T>
ConsoleHandler<T>::ConsoleHandler() {
    commandMap.emplace("insert", [this](T t) -> std::string { return tree.insertNode(t); });
    commandMap.emplace("search", [this](T t) -> std::string {
        if (tree.search(t) != nullptr) {
            return "Znaleziono element";
        } else {
            return "Nie znaleziono elementu";
        }
    });
    commandMap.emplace("draw", [this](T t) -> std::string {
        tree.drawLeaf();
        return "";
    });
    commandMap.emplace("remove", [this](T t) -> std::string { return tree.deleteNode(t); });
    commandMap.emplace("exit", [](T t) {
        return "dog";
    });
}

template<typename T>
std::string ConsoleHandler<T>::handle(const std::string &command) {
    std::stringstream input;
    input << command;
    std::string arg;
    input >> arg;
    auto function = commandMap.at(arg);

    std::set<std::string> set = {"draw","exit"};
    T t;
    std::stringstream output;
    while (input >> t) {
        output << function(t) << " " << t << std::endl;
    }


    return output.str();
}

template<typename T>
void ConsoleHandler<T>::startTerminal() {
    std::cout << "Podaj komendę ";
    for (const auto &[k, v]: commandMap) {
        std::cout << k << " ";
    }
    std::cout << std::endl << ">> ";

    std::string command;
    while (!terminated) {
        std::getline(std::cin, command);
        std::cout << handle(command) + ">> ";
    }
}