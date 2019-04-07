#include <iostream>

#include "ConsoleInterface.h"

int main()
{
//    std::cout << "Hello, World!" << std::endl;
    auto interface = ConsoleInterface();
    interface.Run();
    return 0;
}