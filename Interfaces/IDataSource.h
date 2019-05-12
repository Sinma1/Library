//
// Created by Sinma on 07.04.2019.
//

#include <list>
#include "../BookModel.h"

#ifndef BIBLIOTEKA_IDATASOURCE_H
#define BIBLIOTEKA_IDATASOURCE_H

class IDataSource
{
public:
    virtual void CreateBook(BookModel book) = 0;

    virtual BookModel ReadBook(int id) = 0;

    virtual void DeleteBook(int id) = 0;

    virtual std::list<BookModel> ListBooks() = 0;
};

#endif //BIBLIOTEKA_IDATASOURCE_H
