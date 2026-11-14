/*
 * MyString.cpp
 *
 * Implements the MyString class in the cs_mystring namespace.
 * Each object owns a dynamically allocated, null-terminated
 * character array. Copying creates independent character storage.
 *
 * Requires matching declarations in MyString.h, including a private
 * char* named str and friend declarations for the nonmember operators.
 */

#include "MyString.h"
#include <cassert>
#include <cstring>
#include <ostream>

namespace cs_mystring {

/*
 * Constructs a string by copying initialString.
 * Precondition: initialString points to a valid, null-terminated
 * character array.
 * Allocates exactly enough space for the characters and terminator.
 */
MyString::MyString(const char* initialString) {
   str = new char[std::strlen(initialString) + 1];
   std::strcpy(str, initialString);
}

/*
 * Constructs an independent deep copy of original.
 * Changes to either object do not affect the other.
 */
MyString::MyString(const MyString& original) {
   str = new char[std::strlen(original.str) + 1];
   std::strcpy(str, original.str);
}

/*
 * Releases the dynamically allocated character array.
 */
MyString::~MyString() {
   delete[] str;
}

/*
 * Replaces this object's contents with a deep copy of right.
 * Handles self-assignment without changing the object.
 * Allocates the replacement before releasing the existing array.
 * Returns this object by reference to support chained assignment.
 */
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

/*
 * Returns the number of characters, excluding the null terminator.
 * Does not modify the object.
 */
int MyString::length() const {
   return static_cast<int>(std::strlen(str));
}

/*
 * Returns a modifiable reference to the character at index.
 * Precondition: 0 <= index < length().
 * Asserts the bounds condition; the null terminator is not accessible.
 */
char& MyString::operator[](int index) {
   assert(index >= 0 && index < length());
   return str[index];
}

/*
 * Returns the character at index for a const object.
 * Precondition: 0 <= index < length().
 * Asserts the bounds condition and does not permit modification.
 */
char MyString::operator[](int index) const {
   assert(index >= 0 && index < length());
   return str[index];
}

/*
 * Writes the string's characters to out without adding a newline.
 * Returns out by reference to support chained insertion.
 */
std::ostream& operator<<(std::ostream& out,
                         const MyString& value) {
   out << value.str;
   return out;
}

/*
 * Returns true if left precedes right according to strcmp().
 */
bool operator<(const MyString& left,
               const MyString& right) {
   return std::strcmp(left.str, right.str) < 0;
}

/*
 * Returns true if left precedes or equals right according to strcmp().
 */
bool operator<=(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) <= 0;
}

/*
 * Returns true if left follows right according to strcmp().
 */
bool operator>(const MyString& left,
               const MyString& right) {
   return std::strcmp(left.str, right.str) > 0;
}

/*
 * Returns true if left follows or equals right according to strcmp().
 */
bool operator>=(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) >= 0;
}

/*
 * Returns true if left and right contain identical character sequences.
 */
bool operator==(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) == 0;
}

/*
 * Returns true if left and right contain different character sequences.
 */
bool operator!=(const MyString& left,
                const MyString& right) {
   return std::strcmp(left.str, right.str) != 0;
}

} // namespace cs_mystring
