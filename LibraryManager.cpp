//
// Created by sinma on 04.04.19.
//

#include "LibraryManager.h"

void LibraryManager::AddNewBook(BookModel &book)
{
    book.ID = bookList.back().ID + 1;
    this->bookList.push_back(book);
}

BookModel LibraryManager::GetBook(unsigned int ID)
{
    for (auto const &book : this->bookList)
    {
        if (book.ID == ID)
        {
            return book;
        }
    }
    throw std::invalid_argument("Nie znaleziono ksiazki o danym ID");
}

bool LibraryManager::LoadBooksFromSource()
{
    return false;
}

std::list<BookModel> LibraryManager::GetAllBooks()
{
    return this->bookList;
}

void LibraryManager::DeleteBook(unsigned int ID)
{
    try
    {
        auto book = this->GetBook(ID);
        this->bookList.remove(book);
    }
    catch (const std::exception &e)
    {
        throw e;
    }
}

std::list<BookModel> LibraryManager::GetFilteredBooks(
        const std::string &field, const std::string &desiredValue, const bool &bExact
)
{
    auto books = this->GetAllBooks();
    std::list<BookModel> filteredBooks;

    for (auto book : books)
    {
        if (book.CheckFilter(field, desiredValue, bExact))
            filteredBooks.push_back(book);
    }

    return filteredBooks;
}
