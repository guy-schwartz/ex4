//
// Created by Guy Schwartz on 09/06/2022.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H
#include <exception>
#include <string>


//-----------------DeckFileNotFound (cant open)----------------

class DeckFileNotFound : public std::runtime_error {

public:
    DeckFileNotFound() : std::runtime_error("Deck File Error: File not found") {}

};

//--------------------foundDeckFileFormatErrorDeck (error in text)-----------------


class DeckFileFormatError : public std::runtime_error {

public:
    explicit DeckFileFormatError(int number) : std::runtime_error("Deck File Error: File format error in line "+std::to_string(number)) {}
};

// ------------------DeckFileInvalidSize (< 5) --------------

class DeckFileInvalidSize : public std::runtime_error {
public:
    DeckFileInvalidSize() : std::runtime_error("Deck File Error: Deck size is invalid") {}
};

/*
other exceptions withing the class are:

 1	bad_alloc	This exception thrown on failure allocating memory
2	bad_cast	This exception thrown on failure to dynamic cast
3	bad_exception	This an exception thrown by unexpected handler
4	bad_function_call	This exception thrown on bad call
5	bad_typeid	This exception thrown on typeid of null pointer
6	bad_weak_ptr	It is a bad weak pointer
7	ios_base::failure	It is a base class for stream exceptions
8	logic_error	It is a logic error exception
9	runtime_error	It is a runtime error exception

  - - through logic_error
 3	invalid_argument	It is an invalid argument exception
4	length_error	It is a length error exception
5	out_of_range	It is a out-of-range exception

 */



#endif //EX4_EXCEPTION_H
