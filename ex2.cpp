#include <iostream>
#include <stdexcept>
using namespace std;

class MyException : public exception {
public:
    virtual const char* what() const noexcept override {
        return "General exception occurred.";
    }
};

class MathException : public MyException {
public:
    const char* what() const noexcept override {
        return "Math error occurred.";
    }
};

class MemoryException : public MyException {
public:
    const char* what() const noexcept override {
        return "Memory allocation error.";
    }
};

class FileException : public MyException {
public:
    const char* what() const noexcept override {
        return "File operation error.";
    }
};

void TestExceptions(int scenario) {
    switch (scenario) {
    case 1:
        throw MathException();
    case 2:
        throw MemoryException();
    case 3:
        throw FileException();
    default:
        throw MyException();
    }
}

int main() {
    try {
        TestExceptions(2);
    } catch (const MyException& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}
