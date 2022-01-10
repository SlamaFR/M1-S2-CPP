#include <iostream>
#include <string>

using namespace std;

int main()
{
    // int number = 0;
    string word;

    /*
    do
    {
        std::cout << "Enter a number: ";
        std::cin >> number;

        std::cout << "You entered " << number << std::endl;
    }
    while (number != -1);
    */

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter something: ";
        cin >> word;

        cout << "You entered " << word << endl;
    }
    return 0;
}
