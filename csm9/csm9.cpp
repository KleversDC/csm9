#include <iostream>
using namespace std;

class String {
private:
    char* str;
    int length;

public:
    String() : str(nullptr), length(0) {}

    String(const char* s) {
        length = 0;
        while (s[length] != '\0') {
            length++;
        }

        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = s[i];
        }
        str[length] = '\0';
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        for (int i = 0; i < length; i++) {
            str[i] = other.str[i];
        }
        str[length] = '\0';
    }

    ~String() {
        delete[] str;
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str; 

            length = other.length;
            str = new char[length + 1];
            for (int i = 0; i < length; i++) {
                str[i] = other.str[i];
            }
            str[length] = '\0';
        }
        return *this;
    }
     
    char& operator[](int index) {
        if (index >= 0 && index < length) {
            return str[index];
        }
        else {
            throw out_of_range("Index out of range");
        }
    }
     
    int operator()(char ch) const {
        for (int i = 0; i < length; i++) {
            if (str[i] == ch) {
                return i; 
            }
        }
        return -1; 
    }
     
    operator int() const {
        return length; 
    }
     
    void display() const {
        cout << str << endl;
    }
};

int main() {
    String s("Hello, World!");
    cout << "String: ";
    s.display();
     
    try {
        cout << "Character at index 7: " << s[7] << endl;
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
     
    char searchChar = 'W';
    int index = s(searchChar);
    if (index != -1) {
        cout << "Character '" << searchChar << "' found at index: " << index << endl;
    }
    else {
        cout << "Character '" << searchChar << "' not found" << endl;
    }
     
    int length = s;
    cout << "Length of string: " << length << endl;
      
}
