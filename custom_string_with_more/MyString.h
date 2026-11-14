// MyString.h
// Declares a string class that uses a dynamic character array.

#ifndef CS_MYSTRING_H
#define CS_MYSTRING_H

#include <ostream>
#include <istream>

namespace cs_mystring {

class MyString {
   public:
      // Maximum number of characters read by input functions.
      static const int MAX_INPUT_SIZE = 127;

      // Creates a string, or an empty string by default.
      MyString(const char* initialString = "");

      // Creates a deep copy of another string.
      MyString(const MyString& original);

      // Releases the character array.
      ~MyString();

      // Assigns a deep copy of another string.
      MyString& operator=(const MyString& right);

      // Returns the number of characters.
      int length() const;

      // Allows reading and changing a character.
      char& operator[](int index);

      // Allows reading a character from a const object.
      char operator[](int index) const;

      // Prints the string without adding a newline.
      friend std::ostream& operator<<(std::ostream& out,
                                      const MyString& value);

      // Reads one word, skipping leading whitespace.
      friend std::istream& operator>>(std::istream& in,
                                      MyString& value);

      // Reads through a delimiter and discards it.
      void read(std::istream& in, char delimiter);

      // Returns a new string containing both strings.
      friend MyString operator+(const MyString& left,
                                const MyString& right);

      // Appends the right string to this string.
      MyString& operator+=(const MyString& right);

      // Compares two strings.
      friend bool operator<(const MyString& left,
                            const MyString& right);

      friend bool operator<=(const MyString& left,
                             const MyString& right);

      friend bool operator>(const MyString& left,
                            const MyString& right);

      friend bool operator>=(const MyString& left,
                             const MyString& right);

      friend bool operator==(const MyString& left,
                             const MyString& right);

      friend bool operator!=(const MyString& left,
                             const MyString& right);

   private:
      // Stores the characters and null terminator.
      char* str;
};

} // namespace cs_mystring

#endif
