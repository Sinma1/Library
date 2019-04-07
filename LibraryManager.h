//
// Created by sinma on 04.04.19.
//
#include <list>
#include <stdexcept>

#include "Book.h"

#ifndef BIBLIOTEKA_LIBRARYMANAGER_H
#define BIBLIOTEKA_LIBRARYMANAGER_H


class LibraryManager
{
public:
    void AddNewBook(Book book);

    std::list<Book> GetAllBooks();

    Book GetBook(unsigned int ID);

    void DeleteBook(unsigned int ID);

private:
    std::list<Book> book_list;

    bool LoadBooksFromSource();
};


#endif //BIBLIOTEKA_LIBRARYMANAGER_H
