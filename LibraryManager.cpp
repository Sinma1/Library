//
// Created by sinma on 04.04.19.
//

#include "LibraryManager.h"

void LibraryManager::AddNewBook(BookModel &book)
{
    this->dataSource.CreateBook(book);
}

BookModel LibraryManager::GetBook(unsigned int ID)
{
    return this->dataSource.ReadBook(ID);
}

std::list<BookModel> LibraryManager::GetAllBooks()
{
    return this->dataSource.ListBooks();
}

void LibraryManager::DeleteBook(unsigned int ID)
{
    this->dataSource.DeleteBook(ID);
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