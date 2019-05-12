//
// Created by sinma on 04.04.19.
//
#include <string>
#include <iostream>

#ifndef BIBLIOTEKA_BOOK_H
#define BIBLIOTEKA_BOOK_H


class BookModel
{
public:
    BookModel(std::string title, std::string author, unsigned int year_published, std::string publisher);

    unsigned int ID{};
    std::string title;
    std::string author;
    unsigned int year_published;
    std::string publisher;

    static bool Validate(BookModel const &book);
};


#endif //BIBLIOTEKA_BOOK_H