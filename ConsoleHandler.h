//
// Created by pawel on 15.06.2023.
//

#ifndef LISTA7C_CONSOLEHANDLER_H
#define LISTA7C_CONSOLEHANDLER_H

#include <functional>
#include <map>
#include <string>
#include "Tree.h"

template<typename T>
class ConsoleHandler {
private:
    Tree<T> tree;
    std::map<std::string, std::function<std::string(T)>> commandMap;

public:
    bool terminated = false;

    ConsoleHandler();

    std::string handle(const std::string &command);

    void startTerminal();
};



#include "ConsoleHandler.tpp"


#endif //LISTA7C_CONSOLEHANDLER_H
