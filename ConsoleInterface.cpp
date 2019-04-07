//
// Created by sinma on 04.04.19.
//

#include "ConsoleInterface.h"

void ConsoleInterface::Run()
{
    while (bRunning)
    {
        auto action = this->GetMenuOption();
        action();
    }
}

std::function<void()> ConsoleInterface::GetMenuOption()
{
    int option;
    cout << "Wybierz opcje:" << endl;
    for (auto const &action : this->actions)
        cout << action.num << " - " << action.description << endl;

    cout << ":> ";
    cin >> option;

    int action_index = this->GetActionIndexByOptionNum(option);
    if (action_index == -1)
        return []() { cout << "Nieznana opcja" << endl; };

    return this->actions[action_index].action;
}

void ConsoleInterface::AddBook()
{
    std::string title;
    std::string author;
    unsigned int year_published;
    std::string publisher;
    Book *book;

    do
    {
        cout << "Podaj tytul ksiazki: ";
        cin >> title;

        cout << "Podaj autora ksiazki: ";
        cin >> author;

        cout << "Podaj rok wydania: ";
        cin >> year_published;

        cout << "Podaj wydawce: ";
        cin >> publisher;

        book = new Book(title, author, year_published, publisher);
    } while (!Book::Validate(*book));

    this->library.AddNewBook(*book);
}

void ConsoleInterface::ListBooks()
{
    for (auto const &book : this->library.GetAllBooks())
    {
        this->DisplayBook(book);
    }
}

void ConsoleInterface::Exit()
{
    cout << "ByeBye" << endl;
    this->bRunning = false;
}

int ConsoleInterface::GetActionIndexByOptionNum(int num)
{
    for (int i = 0; i < this->actions.size(); i++)
    {
        if (this->actions[i].num == num)
            return i;
    }
    return -1;
}

void ConsoleInterface::GetBookDetails()
{
    int id;

    cout << "Podaj ID interesujacej cie ksiazki: ";
    cin >> id;

    try
    {
        auto book = this->library.GetBook(id);
        this->DisplayBook(book);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }

}

void ConsoleInterface::DisplayBook(Book const &book)
{
    cout << "ID: " << book.ID << "\t'" << book.title << "' - autora " << book.author
         << " wydana w " << book.year_published << " przez " << book.publisher << endl;
}

void ConsoleInterface::DeleteBook()
{
    int id;

    cout << "Podaj ID interesujacej cie ksiazki: ";
    cin >> id;

    try
    {
        this->library.DeleteBook(id);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
}
