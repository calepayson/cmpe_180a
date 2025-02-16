// Shift C Program
// By: Cale Smith
//
// Takes two user supplied arguments, an integer and a string.
// Shifts the string as many times as specified by the integer.
// Prints the result to stdout.
//
// Warning:
//     This program uses atoi() to convert the inputted number to an integer.
//     To signal an error atoi() returns a 0.
//     This program considers 0 a valid integer input.
//     If the program does not shift the string, check that you are inputting a
//     valid integer (within [0, 32_767]).

#include <stdio.h>  // frpintf()
#include <stdlib.h> // atoi()
#include <string.h> // strcpy(), strcat(), strncpy()

/*
 * This function prints the usage of this program to stderr.
 *
 * Input: None.
 * Output: None.
 */
void print_usage();

/*
 * This function shifts a string by a user-specified number of characters.
 * The string is shifted in a rightwards direction and trailing characters
 * are wrapped around to the front of the string. The provided string is
 * replaced with the shifted string (mostly so I don't have to deal with
 * memory allocation).
 *
 * Input:
 *     int num: The number of shifts to apply to the array.
 *     char *phrase: The phrase to be shifted.
 *
 * Output:
 *     char *: A pointer to the string stored at phrase. A bit redundant but
 *             this is how they do it in the C standard library.
 *
 * Examples:
 *     shiftstring(1, "hello") -> "ohell"
 *     shiftstring(3, "world") -> "rldwo"
 *     shfitstring(11, "Abc")  -> "bcA"
 */
char *shiftstring(int num, char *phrase);

int main(int argc, char *argv[]) {
  // Check if the program recieved the proper number of arguments.
  if (argc != 3) {
    fprintf(stderr,
            "ERROR: Incorrect number of arguments.\n"
            "    Expected: 2\n"
            "    Recieved: %i\n",
            argc);
    print_usage();
    return 1;
  }

  // Convert <num> to an integer and error on failure.
  int num = atoi(argv[1]);
  if (num < 0) {
    fprintf(stderr,
            "ERROR: Unable to convert <num> to a postive integer.\n"
            "    Expected: [0, 32767]\n"
            "    Recieved: %i\n",
            num);
    print_usage();
    return 1;
  }

  // Use phrase to point to argv[2] for better readability
  char *phrase = argv[2];

  char *shifted = shiftstring(num, phrase);

  fprintf(stdout, "%s\n", shifted);

  return 0;
}

void print_usage() {
  fprintf(stderr,
          "Usage: ./shift <num> <phrase>\n"
          "    num - The number of shifts to implement.\n"
          "    phrase - The phrase upon which to implement the shifts\n");
}

char *shiftstring(int num, char *phrase) {
  // Initialize doubled_size as two copies of the phrase in the same string
  size_t doubled_size = (strlen(phrase) * 2) + 1;
  char doubled_phrase[doubled_size];
  strcpy(doubled_phrase, phrase);
  strcat(doubled_phrase, phrase);

  // Calculate the starting index given the shift
  size_t phrase_size = strlen(phrase) + 1;
  size_t length = strlen(phrase);
  int shift_index = length - (num % length);
  char shifted[phrase_size];

  // Starting at the shifted index, length number of chars int phrase.
  strncpy(phrase, &doubled_phrase[shift_index], length);

  return phrase;
}
