#include <stdio.h>

// Function to convert a character to bits and print them
void char_to_bits(char c) {
    // Convert the character to its ASCII value
    int ascii_value = (int)c;
    // Initialize loop counter
    int i = 7;
    // Print the binary representation of the ASCII value
    while (i >= 0) {
        // Extract each bit using right shift and bitwise AND
        int bit = (ascii_value >> i) & 1;
        // Print the bit
        printf("%d", bit);
        // Decrement loop counter
        i--;
    }
    // Print a space after printing all bits
    printf(" ");
}

// Function to convert bits to character and print it
void bits_to_char(int bits) {
    // Convert the bits to character and print it
    printf("%c", (char)bits);
}

int main() 
{
    const char *str = "Hello World";
    printf("String: %s\n", str);
    printf("Binary representation of each character:\n");
    int i = 0;
    while (str[i] != '\0') 
    {
        // Convert each character to bits and print
        char_to_bits(str[i]);
        // Move to the next character
        i++;
    }
    printf("\nCharacters obtained from binary representation:\n");
    i = 0;
    while (str[i] != '\0') 
    {
        // Convert each 8 bits to character and print
        int bits = 0;
        int j = 0;
        while (j < 8) 
	{
            bits = (bits << 1) | ((str[i] >> (7 - j)) & 1); // Shift bits and perform bitwise OR
            // Move to the next bit
            j++;
        }
        bits_to_char(bits);
        // Move to the next character
        i++;
    }
    printf("\n");
    return 0;
}