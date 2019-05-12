//
// Created by Sinma on 07.04.2019.
//

#include "DataSource.h"

DataSource::DataSource()
{

}

void DataSource::CreateBook(BookModel book)
{
    this->book_list.push_back(book);
}

BookModel DataSource::ReadBook(int id)
{
    for (auto const &book : this->book_list)
    {
        if (book.ID == id)
        {
            return book;
        }
    }
    throw std::invalid_argument("Nie znaleziono ksiazki o danym ID");
}

void DataSource::DeleteBook(int id)
{

}

std::list<BookModel> DataSource::ListBooks()
{
    return this->book_list;
}
