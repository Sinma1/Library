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

    unsigned int ID;
    std::string title;
    std::string author;
    unsigned int year_published;
    std::string publisher;

    static bool Validate(BookModel const &book);

    bool CheckFilter(const std::string &field, const std::string &desiredValue, const bool &bExact);

    bool operator==(const BookModel &book) const;
    bool operator!=(const BookModel &book) const;
};


#endif //BIBLIOTEKA_BOOK_H
