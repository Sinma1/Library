//
// Created by sinma on 04.04.19.
//
#include <list>
#include <stdexcept>

#include "BookModel.h"
#include "DataSource.h"

#ifndef BIBLIOTEKA_LIBRARYMANAGER_H
#define BIBLIOTEKA_LIBRARYMANAGER_H


class LibraryManager
{
public:
    void AddNewBook(BookModel book);

    std::list<BookModel> GetAllBooks();

    BookModel GetBook(unsigned int ID);

    void DeleteBook(unsigned int ID);

private:
    std::list<BookModel> book_list;

    DataSource data_source = DataSource();

    bool LoadBooksFromSource();
};


#endif //BIBLIOTEKA_LIBRARYMANAGER_H
