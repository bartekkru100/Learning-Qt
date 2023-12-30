#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    std::string test = "4106085912";
    std::cout << std::atol(test.c_str()) << '\n';
    return 0;
}
