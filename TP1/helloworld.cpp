#include <string>
#include <iostream>
using namespace std;

int main()
{
    // int var;
    string name;

    /*
     * if (!(cin >> var))
     * {
     *    cerr << "not an integer" << endl;
     *    return 1;
     * }
    */
    cout << "What's your name ?" << endl;
    if (!(cin >> name))
    {
        cerr << "Input flux are closed" << endl;
        return 1;
    }
    cout << "Hello " << name << " !" << endl;
    return 0;
}