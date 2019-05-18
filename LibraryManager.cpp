//
// Created by sinma on 04.04.19.
//

#include "LibraryManager.h"

void LibraryManager::AddNewBook(BookModel book)
{
    this->book_list.push_back(book);
}

BookModel LibraryManager::GetBook(unsigned int ID)
{
    for (auto const &book : this->book_list)
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
    return this->book_list;
}

void LibraryManager::DeleteBook(unsigned int ID)
{
    BookModel *book;
    try
    {
        // TODO FIX THIS
        *book = this->GetBook(ID);
//        this->book_list.remove(*book);
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
