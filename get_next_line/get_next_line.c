
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	bytesRead = 0;
	static char buffer[BUFFER_SIZE];
    int newline_found;
    int lineLen;
	char *line;

    line = NULL
    newline_found = 0;
    lineLen = 0;
    while (bytesRead > 0 || !newline_found)
    {
        if (bytesRead == 0)
        {
            bytesRead = gnl_read_to_buffer(fd, buffer, BUFFER_SIZE);
            if (bytesRead == -1)
                return (NULL);
            if (!bytesRead)
                break;
        }
        while (lineLen < bytesRead && buffer[lineLen] != '\n')
            lineLen++;
        if (lineLen < bytesRead && buffer[lineLen] == '\n')
        {
            newline_found = 1;
            lineLen++; //include '\n'
        }
        line = gnl_buffer_to_line(line, lineLen, buffer, &bytesRead);
        if (newline_found)
            break;
    }
	return (line)
}

// Helper function to read data from the file descriptor into the buffer
// Returns the number of bytes read or -1 on error
ssize_t read_into_buffer(int fd, char* buffer, size_t buffer_size) {
    // Use the read() function to read data from the file descriptor into the buffer
    // Handle errors and return the number of bytes read
}

// Helper function to allocate and copy a line from the buffer
// Returns a dynamically allocated string containing the line
char* allocate_and_copy_line(char* line, int line_length, char* buffer, ssize_t* bytes_read) {
    // Allocate memory for the line and copy the data read so far
    // Return the dynamically allocated line
}

// Main get_next_line function
char* get_next_line(int fd) {
    static char buffer[BUFFER_SIZE]; // Static buffer to store data between calls
    static int bytes_read = 0;       // Static variable to keep track of bytes read
    int newline_found = 0;           // Flag to track if a newline is found
    int line_length = 0;             // Length of the current line
    char* line = NULL;               // Pointer to the line being read

    // While there's data left to process in the buffer or more data to read
    while (bytes_read > 0 || !newline_found) {
        // Check if the buffer needs to be refilled
        if (bytes_read == 0) {
            bytes_read = read_into_buffer(fd, buffer, BUFFER_SIZE);
            if (bytes_read == -1) {
                perror("read");
                return NULL; // Error reading, return NULL
            }
            if (bytes_read == 0)
                break; // End of file reached
        }

        // Process data in the buffer
        while (line_length < bytes_read && buffer[line_length] != '\n') {
            line_length++;
        }

        // Check if a newline was found
        if (line_length < bytes_read && buffer[line_length] == '\n') {
            newline_found = 1;
            line_length++; // Include the newline character
        }

        // Allocate memory for the line and copy the data read so far
        line = allocate_and_copy_line(line, line_length, buffer, &bytes_read);

        // If a newline was found, break out of the loop
        if (newline_found)
            break;
    }

    return line;
}
