/*
 File:          recursion.c
 Purpose:       Exercises for CPSC259 lab 4
 Author:		Stephanie Quon and Mihir Bhatia
 Student #s:	95122271 and 76149921
 CS Accounts:	k5d3b and mbhatia01
 Date:			November 5, 2020
 */

/******************************************************************
 PLEASE EDIT THIS FILE

 Comments that start with // should be replaced with code
 Comments that are surrounded by * are hints
 ******************************************************************/


/* Preprocessor directives */
#include "recursion.h"
#include <string.h>

/*
 Calculates the power.
 PARAM:     base is an integer
 PARAM:     power is an integer
 PRE:       power >= 0
 PRE:       base != 0
 RETURN:    base^power
 */
int calculate_power(int base, int power)
{
	// base case: when power is 0, result is always 1
	if (power == 0)
		return 1;
	// recursive: calculate the base against itself be decreasing power each call
	else
		return (calculate_power(base, power - 1) * base);
}

/*
 Returns the number of digits in an integer
 PARAM:     number is an integer
 PRE:       0 < number <= INT_MAX
 RETURN:    the number of digits in the number
 */
int count_digits(int number)
{
	// base case: when number is 0, number of digits it always
	if (number == 0)
		return 0;
	// recursive: calculate the number of times the digit can be divided by 10
	else
		return (count_digits(number / 10) + 1);
}

/*
 Returns the length of the specified string.
 PARAM:  string, a pointer to an array of char
 PRE:    the string pointer is not a dangling pointer
 RETURN: the length of the string passed as a parameter  
 */
int string_length(char* string)
{
	// base case: when the string's first char is a null character, string is empty
	if (*string == '\0')
		return 0;
	// recursive: iterate through length of string until it reaches the null char
	else
		return (1 + string_length(string + 1));
}

/*
 Determines if a string is a palindrome.  DOES NOT skip spaces!
 For example, 
 ""     -> returns 1 (an empty string is a palindrome)
 "the"  -> returns 0
 "abba" -> returns 1
 "Abba" -> returns 0
 "never odd or even" -> returns 0
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  string, a pointer to an array of char
 PARAM:  string_length, the length of the string
 PRE:    the string pointer is not a dangling pointer
 PRE:    string_length is the correct length of the string
 RETURN: IF string is a palindrome
         THEN 1
		 END 0
 */
int is_palindrome(char* string, int string_length)
{
	// base case(s): when the string is length 0 or 1, it is always a palindrome
	if (string_length == 0 || string_length == 1)
		return 1;
	// recursive: iterate through the string comparing one side to the other, return 0 early if there is a mismatch
	else {
		if (*string == *(string + string_length - 1))
			return is_palindrome(string + 1, string_length - 2);
		else
			return 0;
	}
}

/*
 Draws a ramp.  The length of the longest rows is specified by the parameter.
 For the recursive call, be aware that both parameters can be modified.
 PARAM:     number, an integer
 PARAM:     buffer, a character array of sufficient length
 PRE:       number >= 1
            buffer has sufficient length and contains null characters from the buffer
            address to the end of its length
 POST:      draws a ramp whose height is the specified number into buffer
 RETURN:    the number of characters written into buffer. Don't forget to count your
            newline characters!
 */
int draw_ramp(int number, char* buffer)
{
	// base case: if the number if 1, only one line needs to be executed
	if (number == 1) {
		draw_row(number, buffer);
	}

	// recurvise: calls itself until number is one, and the "bounces" to complete the lines under the function call
	else {
		// drawing stars counting down
		draw_row(number, buffer);
		strcat(buffer, "\n");

		draw_ramp(number - 1, buffer);

		// drawing stars counting up
		strcat(buffer, "\n");
		draw_row(number, buffer);
	}

	// return length of the buffer as the chars written to it
	return string_length(buffer);
}



/*
 Draws a row of asterisks of the specified length
 For the recursive call, be aware that both parameters can be modified.
 PARAM:  size, an integer
 PARAM:  buffer, a character array of sufficient length
 PRE:    size >= 1
         buffer has sufficient length and contains null characters from the buffer
         address to the end of its length
 POST:   draws a row of asterisks of specified length to buffer
 RETURN: the number of characters drawn
 */
int draw_row(int size, char* buffer)
{
	// create a pointer to a star
	char* star = "*";

	// base case: when size is 1, only 1 star needs to be concatenated
	if (size == 1) {
		strcat(buffer, star);
	}

	//  recursive: continue concatenating stars to the buffer until the size reaches 1
	else {
		strcat(buffer, star);
		draw_row(size - 1, buffer);
	}


	// return length of the buffer as the chars written to it
	return string_length(buffer);
}

