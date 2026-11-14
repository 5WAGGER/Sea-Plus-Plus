// MyString.cpp

#include "MyString.h"
#include <cassert>
#include <cstring>
#include <ostream>

namespace cs_mystring {

// Constructor
MyString::MyString(const char* initialString) {
   str = new char[std::strlen(initialString) + 1];
   std::strcpy(str, initialString);
}

// Copy constructor
MyString::MyString(const MyString& original) {
   str = new char[std::strlen(original.str) + 1];
   std::strcpy(str, original.str);
}

// Destructor
MyString::~MyString() {
   delete[] str;
}

// Assignment
MyString& MyString::operator=(const MyString& right) {
   if (this != &right) {
      char* replacement =
         new char[std::strlen(right.str) + 1];

      std::strcpy(replacement, right.str);

      delete[] str;
      str = replacement;
   }

   return *this;
}

// Length
int MyString::length() const {
   return static_cast<int>(std::strlen(str));
}

// Change characters
char& MyString::operator[](int index) {
   assert(index >= 0 && index < length());
   return str[index];
}

// Read characters
char MyString::operator[](int index) const {
   assert(index >= 0 && index < length());
   return str[index];
}

// Output
std::ostream& operator<<(std::ostream& out,
                         const MyString& value) {
   out << value.str;
   return out;
}

// Input
std::istream& operator>>(std::istream& in,
                         MyString& value) {
   char temp[MyString::MAX_INPUT_SIZE + 1] = "";

   in.width(MyString::MAX_INPUT_SIZE + 1);
   if (in >> temp) {
      char* replacement =
         new char[std::strlen(temp) + 1];

      std::strcpy(replacement, temp);

      delete[] value.str;
      value.str = replacement;
   }

   return in;
}

// Read through a delimiter
void MyString::read(std::istream& in, char delimiter) {
   char temp[MAX_INPUT_SIZE + 1] = "";

   in.getline(temp, MAX_INPUT_SIZE + 1, delimiter);

   char* replacement =
      new char[std::strlen(temp) + 1];

   std::strcpy(replacement, temp);

   delete[] str;
   str = replacement;
}

// Concatenation
MyString operator+(const MyString& left,
                   const MyString& right) {
   MyString result;

   char* replacement =
      new char[std::strlen(left.str) + std::strlen(right.str) + 1];

   std::strcpy(replacement, left.str);
   std::strcat(replacement, right.str);

   delete[] result.str;
   result.str = replacement;

   return result;
}

// Concatenation assignment
MyString& MyString::operator+=(const MyString& right) {
   *this = *this + right;
   return *this;
}

// Comparisons
bool operator<(const MyString& left,
               const MyString& right) {
   return std::strcmp(left.str, right.str) < 0;
}

bool operator<=(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) <= 0;
}

bool operator>(const MyString& left,
               const MyString& right) {
   return std::strcmp(left.str, right.str) > 0;
}

bool operator>=(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) >= 0;
}

bool operator==(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) == 0;
}

bool operator!=(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) != 0;
}

} // namespace cs_mystring
