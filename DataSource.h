//
// Created by Sinma on 07.04.2019.
//

#ifndef BIBLIOTEKA_DATASOURCE_H
#define BIBLIOTEKA_DATASOURCE_H

#include <list>
#include <fstream>
#include <vector>

#include "Interfaces/IDataSource.h"
#include "BookModel.h"

class DataSource : IDataSource
{
public:
    DataSource();

    ~DataSource();

    void CreateBook(BookModel book) override;

    BookModel ReadBook(int id) override;

    void DeleteBook(int id) override;

    std::list<BookModel> ListBooks() override;

private:
    std::list<BookModel> bookList;

    void loadFromFile();

    void saveToFile();

    std::string fileName = "books.txt";
};


#endif //BIBLIOTEKA_DATASOURCE_H
