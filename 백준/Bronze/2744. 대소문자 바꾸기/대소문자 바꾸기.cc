#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    for (char& c : str) {
        if (isupper(c))
            c = tolower(c);  
        else
            c = toupper(c);  
    }

    cout << str;

    return 0;
}