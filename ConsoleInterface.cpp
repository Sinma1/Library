//
// Created by sinma on 04.04.19.
//

#include "ConsoleInterface.h"
#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void ConsoleInterface::Run()
{
    while (bRunning)
    {
        auto action = this->GetMenuOption();
        action();
        cout << endl;
    }
}

std::function<void()> ConsoleInterface::GetMenuOption()
{
    std::string command;
    cout << "Wybierz komende:" << endl;
    for (auto const &action : this->actions)
        cout << action.command << " - " << action.description << endl;

    cout << ":> ";
    cin >> command;

    int actionIndex = this->GetActionIndexByCommand(command);
    if (actionIndex == -1)
        return []()
        { cout << "Nieznana komenda" << endl; };

    return this->actions[actionIndex].action;
}

void ConsoleInterface::AddBook()
{
    std::string title;
    std::string author;
    unsigned int yearPublished;
    std::string publisher;
    BookModel *book;

    do
    {
        cout << "Podaj tytul ksiazki: ";
        cin >> title;

        cout << "Podaj autora ksiazki: ";
        cin >> author;

        cout << "Podaj rok wydania: ";
        cin >> yearPublished;

        cout << "Podaj wydawce: ";
        cin >> publisher;

        book = new BookModel(title, author, yearPublished, publisher);
    } while (!BookModel::Validate(*book));

    this->library.AddNewBook(*book);
}

void ConsoleInterface::ListBooks()
{
    auto books = this->library.GetAllBooks();
    if (books.empty())
    {
        cout << "Brak ksiazek do wyswietlenia." << endl;
        return;
    }
    cout << "=================================" << endl;
    for (auto const &book : books)
    {
        this->DisplayBook(book);
    }
    cout << "=================================" << endl;
}

void ConsoleInterface::Exit()
{
    cout << "ByeBye" << endl;
    this->bRunning = false;
}

void ConsoleInterface::ClearScreen()
{
    system(CLEAR);
}

int ConsoleInterface::GetActionIndexByCommand(const std::string &command)
{
    for (int i = 0; i < this->actions.size(); i++)
    {
        if (this->actions[i].command == command)
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

void ConsoleInterface::DisplayBook(BookModel const &book)
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
        cout << "Ksiazka zostala usunieta.";
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
}

void ConsoleInterface::ListBooksByFilter()
{
    std::string filter;
    cout << "Podaj pole po jakim chcesz szukac";
    cout << "(";
    for (const auto &f : this->library.filters) cout << f << " ";
    cout << "): ";
    cin >> filter;

    auto it = std::find(std::begin(this->library.filters), std::end(this->library.filters), filter);
    if (it == this->library.filters.end())
    {
        cout << "Nie znaleziono takiego filtra" << endl;
        return;
    }

    std::string desiredValue;
    cout << "Podaj szukana wartosc: ";
    cin >> desiredValue;

    std::string exact;
    bool bExact;
    cout << "Czy dopasowanie ma byc czesciowe(n) czy dokladne(y): ";
    cin >> exact;

    if (exact == "y")
        bExact = true;
    else if (exact == "n")
        bExact = false;
    else
    {
        cout << "Nie rozpoznana opcja" << endl;
        return;
    }

    auto books = this->library.GetFilteredBooks(filter, desiredValue, bExact);
    for (const auto &book : books)
    {
        this->DisplayBook(book);
    }
}
