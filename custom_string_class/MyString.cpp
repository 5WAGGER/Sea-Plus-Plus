
// MyString.cpp

#include "MyString.h"
#include <cassert>
#include <cstring>
#include <ostream>

namespace cs_mystring {

MyString::MyString(const char* initialString) {
   str = new char[std::strlen(initialString) + 1];
   std::strcpy(str, initialString);
}

MyString::MyString(const MyString& original) {
   str = new char[std::strlen(original.str) + 1];
   std::strcpy(str, original.str);
}

MyString::~MyString() {
   delete[] str;
}

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

int MyString::length() const {
   return static_cast<int>(std::strlen(str));
}

char& MyString::operator[](int index) {
   assert(index >= 0 && index < length());
   return str[index];
}

char MyString::operator[](int index) const {
   assert(index >= 0 && index < length());
   return str[index];
}

std::ostream& operator<<(std::ostream& out,
                         const MyString& value) {
   out << value.str;
   return out;
}

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
