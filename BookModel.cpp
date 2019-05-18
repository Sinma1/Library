//
// Created by sinma on 04.04.19.
//

#include "BookModel.h"

BookModel::BookModel(
        std::string title,
        std::string author,
        unsigned int year_published,
        std::string publisher)
{
    this->title = title;
    this->author = author;
    this->year_published = year_published;
    this->publisher = publisher;
}

bool BookModel::Validate(BookModel const &book)
{
    if (book.title.length() <= 0 || book.title.length() > 100)
    {
        std::cout << "Dlugosc tytulu musi zawierac sie w przedziale <1; 100>" << std::endl;
        return false;
    }
    if (book.author.length() <= 0 || book.author.length() > 100)
    {
        std::cout << "Dlugosc authora musi zawierac sie w przedziale <1; 100>" << std::endl;
        return false;
    }
    if (book.year_published < 0)
    {
        std::cout << "Rok wydania nie moze byc liczba ujemna" << std::endl;
        return false;
    }
    if (book.publisher.length() <= 0 || book.publisher.length() > 100)
    {
        std::cout << "Dlugosc wydawcy musi zawierac sie w przedziale <1; 100>" << std::endl;
        return false;
    }

    return true;
}
//    "tytul", "autor", "wydanie", "wydawnictwo"

bool BookModel::CheckFilter(const std::string &strField, const std::string &strDesiredValue, const bool &bExact)
{
    std::string strFieldValue;
    if (strField == "tytul") strFieldValue = this->title;
    if (strField == "autor") strFieldValue = this->author;
    if (strField == "wydanie") strFieldValue = std::to_string(this->year_published);
    if (strField == "wydawnictwo") strFieldValue = this->publisher;

    return (strFieldValue == strDesiredValue) || (strFieldValue.find(strDesiredValue) != std::string::npos && !bExact);
}
