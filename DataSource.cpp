//
// Created by Sinma on 07.04.2019.
//

#include <sstream>
#include "DataSource.h"

DataSource::DataSource()
{
    this->loadFromFile();
}

DataSource::~DataSource()
{
    this->saveToFile();
}

void DataSource::CreateBook(BookModel book)
{
    book.ID = (bookList.empty() ? 1 : bookList.back().ID + 1);
    this->bookList.push_back(book);
    this->saveToFile();
}

BookModel DataSource::ReadBook(int id)
{
    for (auto const &book : this->bookList)
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
    try
    {
        auto book = this->ReadBook(id);
        this->bookList.remove(book);
    }
    catch (const std::exception &e)
    {
        throw e;
    }
    this->saveToFile();
}

std::list<BookModel> DataSource::ListBooks()
{
    return this->bookList;
}

void DataSource::loadFromFile()
{
    std::fstream file;
    file.open(this->fileName, std::ios::in);
    if (!file.good())
    {
        std::cout << "Nie mozna odczytac pliku " << this->fileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> fields;
        std::stringstream ss(line);

        std::string str;
        while (std::getline(ss, str, ';'))
            fields.push_back(str);

        if (fields.size() != 5)
            continue;

        BookModel book(
                std::stoi(fields[0]),
                fields[1],
                fields[2],
                std::stoi(fields[3]),
                fields[4]
        );
        this->bookList.push_back(book);
    }
    file.close();
}

void DataSource::saveToFile()
{
    std::fstream file;
    file.open(this->fileName, std::ios::out | std::ios::trunc);
    if (!file.good())
    {
        std::cout << "Nie udalo zapisac do pliku " << this->fileName << std::endl;
        return;
    }

    for (const auto &book : this->bookList)
    {
        std::stringstream ss;
        ss << std::to_string(book.ID) << ";"
           << book.title << ";"
           << book.author << ";"
           << std::to_string(book.year_published) << ";"
           << book.publisher << std::endl;

        file << ss.str();
    }
    file.close();
}