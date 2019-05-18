//
// Created by sinma on 04.04.19.
//
#include <list>
#include <stdexcept>
#include <vector>

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

    std::list<BookModel> GetFilteredBooks(
            const std::string &strField, const std::string &strDesiredValue, const bool &bExact);

    std::vector<std::string> filters = {"tytul", "autor", "wydanie", "wydawnictwo"};

private:
    std::list<BookModel> book_list;

    DataSource data_source = DataSource();

    bool LoadBooksFromSource();
};


#endif //BIBLIOTEKA_LIBRARYMANAGER_H
