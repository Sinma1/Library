//
// Created by sinma on 04.04.19.
#include <functional>
#include <iostream>
#include <vector>

#include "BookModel.h"
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
    Action(const std::function<void()> &action, const std::string &command, const std::string &description)
    {
        this->action = action;
        this->command = command;
        this->description = description;
    }

    std::function<void()> action;
    std::string command;
    std::string description;
};

class ConsoleInterface
{
public:
    ConsoleInterface()
    {
        this->library = LibraryManager();

        this->actions = {
                Action(std::bind(&ConsoleInterface::AddBook, this), "1", "Dodaj ksiazke"),
                Action(std::bind(&ConsoleInterface::ListBooks, this), "2", "Wypisz wszystkie ksiazki"),
                Action(std::bind(&ConsoleInterface::GetBookDetails, this), "3", "Pokaz ksiazke po ID"),
                Action(std::bind(&ConsoleInterface::DeleteBook, this), "4", "Usun ksiazke"),
                Action(std::bind(&ConsoleInterface::ListBooksByFilter, this), "5", "Wyszukaj ksiazke"),

                Action(std::bind(&ConsoleInterface::ClearScreen, this), "clear", "Wyczysc konsole"),
                Action(std::bind(&ConsoleInterface::Exit, this), "exit", "Wyjdz z programu")
        };
    }

    void Run();

private:
    std::function<void()> GetMenuOption();

    void AddBook();

    void DisplayBook(BookModel const &book);

    void ListBooks();

    void GetBookDetails();

    void DeleteBook();

    void Exit();

    void ClearScreen();

    void ListBooksByFilter();

    int GetActionIndexByCommand(const std::string &command);

    LibraryManager library;
    bool bRunning = true;
    std::vector<Action> actions;
};


#endif //BIBLIOTEKA_CONSOLEINTERFACE_H
