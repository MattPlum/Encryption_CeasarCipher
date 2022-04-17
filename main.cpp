#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

/**
 * @brief This program takes in a messsage, then uses substitution cipher (Ceasar cipher) to encrypt it given the shift position.
 * It returns the encrypted messsage in plain text
 * 
 * @return int 
 */
int main(void) {

  //Create int variables i, j, f, n and multi-dimensional array 1x50 t
  int temp, message_index, alphabet_index, shift, message_length, shifted_message_int[1][50];

  //Create multi-dimensional array char variables 1x50 p, k, c and 1x27 a with alphabet
  char p[1][50], message[1][50], shifted_message_char[1][50], 
  alphabet[1][27] = {
    "abcdefghijklmnopqrstuvwxyz"

  };

  //Get string message to be encrypted and store string characters in first row ("h,"e","l","l",)
  printf("Enter the text to be encrypted (50 char max):");
  scanf("%s", message[0]);


  //Set message_length = to message length
  message_length = strlen(message[0]);

  //Get decimal input and store in int f variable
  printf("Enter the shift position:");
  scanf("%d", &shift);  //shift = 3

  //Shifts each character in the input string by the shift position. 
  shift = shift % 26; //take mod value so that you get a number from 1-26
  for (message_index = 0; message_index < message_length; message_index++) // loop for each character in string
    for (alphabet_index = 0; alphabet_index < 26; alphabet_index++)  // iterate over all characters in alphabet 
      if (message[0][message_index] == alphabet[0][alphabet_index]) {   // if character in k[][] matches character in a[][] || h == h when j = 7
        shifted_message_int[0][message_index] = (alphabet_index + shift) % 26; // set t[0][i] to the shifted value of (7 + 3 = 10)
        temp = shifted_message_int[0][message_index];   // set temp to shifted value as well (10)
        shifted_message_char[0][message_index] = alphabet[0][temp]; // set shifted_message_char to new character (10th letter in alphabet = k)
        break;
      }

  shifted_message_char[0][message_index] = '\0'; //add a new line in case
  printf("The cipher text is:");
  puts(shifted_message_char[0]);  //print shifted message khoor
}
//   printf("\nDecryption Process:\n");

//   for (message_index = 0; message_index < message_length; message_index++) //loop for each character
//   {
//     temp = (shifted_message_int[0][message_index] - shift + 26) % 26;
//     p[0][message_index] = alphabet[0][temp];
//   }
//   printf("The plain text is:");
//   puts(p[0]);
// }