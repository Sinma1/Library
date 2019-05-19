#include <iostream>

#include "Helpers/StringHelper.h"
#include "ConsoleInterface.h"

bool RequireLoginPassword();

int main()
{
    if (!RequireLoginPassword())
    {
        std::cout << "Nie udalo sie zalogowac" << std::endl;
        std::cout << "Wcisnij enter aby wyjsc.";
        std::cin.get();
        return -1;
    }

    auto interface = ConsoleInterface();
    interface.Run();
    return 0;
}

bool RequireLoginPassword()
{
    std::string login, password;

    std::cout << "Podaj login: ";
    std::cin >> login;

    std::cout << "Podaj haslo: ";
    std::cin >> password;

    std::fstream file;
    file.open("users.txt", std::ios::in);
    if (!file.good())
    {
        std::cout << "Nie mozna odczytac pliku " << std::endl;
        return false;
    }

    std::string credentials;
    while (std::getline(file, credentials))
    {
        auto fields = StringHelper::Split(credentials, ':');
        if (fields.size() != 2)
            continue;

        if (login == fields[0] && password == fields[1])
            return true;
    }

    std::cout << "Nieprawidlowy login lub haslo" << std::endl;
    return false;
}