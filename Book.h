//
// Created by sinma on 04.04.19.
//
#include <string>
#include <iostream>

#ifndef BIBLIOTEKA_BOOK_H
#define BIBLIOTEKA_BOOK_H


class Book
{
public:
    Book(std::string title, std::string author, unsigned int year_published, std::string publisher);

    unsigned int ID{};
    std::string title;
    std::string author;
    unsigned int year_published;
    std::string publisher;

    static bool Validate(Book const &book);
};


#endif //BIBLIOTEKA_BOOK_H
