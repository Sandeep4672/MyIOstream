#include "myiostream.h"

int main() {
    int x;
    char name[100];

    mycout << "Enter a number and a word: ";
    mycin >> x >> name;
    mycout << "You entered: " << x << " and " << name << '\n';

    return 0;
}
