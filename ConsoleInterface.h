//
// Created by sinma on 04.04.19.
#include <functional>
#include <iostream>
#include <vector>

#include "Book.h"
#include "LibraryManager.h"
//

#ifndef BIBLIOTEKA_CONSOLEINTERFACE_H
#define BIBLIOTEKA_CONSOLEINTERFACE_H

using std::cout;
using std::endl;
using std::cin;

class Action
{
public:
    Action(std::function<void()> action, int num, std::string description)
    {
        this->action = action;
        this->num = num;
        this->description = description;
    }

    std::function<void()> action;
    int num;
    std::string description;
};

class ConsoleInterface
{
public:
    ConsoleInterface()
    {
        this->library = LibraryManager();

        this->actions = {
                Action(std::bind(&ConsoleInterface::AddBook, this), 1, "Dodaj ksiazke"),
                Action(std::bind(&ConsoleInterface::ListBooks, this), 2, "Wypisz wszystkie ksiazki"),
                Action(std::bind(&ConsoleInterface::GetBookDetails, this), 3, "Pokaz ksiazke po ID"),
                Action(std::bind(&ConsoleInterface::DeleteBook, this), 3, "Usun ksiazke"),
                Action(std::bind(&ConsoleInterface::Exit, this), 0, "Wyjdz z programu")
        };
    }

    void Run();

private:
    std::function<void()> GetMenuOption();

    void AddBook();

    void DisplayBook(Book const &book);

    void ListBooks();

    void GetBookDetails();

    void DeleteBook();

    void Exit();

    int GetActionIndexByOptionNum(int num);

    LibraryManager library;
    bool bRunning = true;
    std::vector<Action> actions;
};


#endif //BIBLIOTEKA_CONSOLEINTERFACE_H
