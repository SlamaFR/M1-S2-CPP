#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cerr << "Please give a valid number" << endl;
        return -1;
    }

    int length = stoi(argv[1]);
    vector<int> array;

    array.reserve(length);
    for (int i = 0; i < length; i++)
    {
        array.emplace_back(i + 1);
    }

    for (int number : array)
    {
        cout << number << endl;
    }

    return 0;
}
