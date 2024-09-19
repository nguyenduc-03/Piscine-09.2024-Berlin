#include <stdio.h>
#include <fcntl.h>    // for open
#include <unistd.h>   // for read, write, close
#include <stdlib.h>   // for malloc, free

int     ft_is_valid_char(char c);
int     ft_is_valid_num(char c);
int     is_valid_line(const char *line);

int check_lines(char *buffer, int filelong)
{
    ssize_t i;
    ssize_t start;
    int     line_valid;

    i = 0;
    start = 0;
    while (i < filelong)
    {
        while (i < filelong && buffer[i] != '\n' && buffer[i] != '\0')
            i++;
        // buffer[i] = '\0'; // Ensure the line is properly terminated
        line_valid = is_valid_line(&buffer[start]);
        if (line_valid != 1)
        {
            printf("Invalid line: '%s'\n", &buffer[start]); // Debug print
            return (-1);
        }
        i++;
        start = i;
    }
    return (1);
}

int is_valid_line(const char *line)
{
    int i;

    i = 0;
    while (line[i] && ft_is_valid_num(line[i]) == 1)
        i++;
    while (line[i] == ' ')
        i++;
    if (line[i] != ':')
        return (-1);
    i++;
    while (line[i] == ' ')
        i++;
    while (line[i] && ft_is_valid_char(line[i]) == 1 && line[i] != '\n')
        i++;
	printf("Index: %d\n",i);
	// printf("String: %s\n", line);
	// printf("ASCII value: %d\n", line[i]);

    if (line[i] != 10)
        {
			return (-1);
		}
    return (1);
}

// Mock implementations for testing
int ft_is_valid_char(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0;
}

int ft_is_valid_num(char c)
{
    return (c >= '0' && c <= '9') ? 1 : 0;
}

// int main()
// {
//     // Test Case 1: Valid line
//     char buffer1[] = "0: zero\n";
//     printf("Test Case 1: %d\n", check_lines(buffer1, 8)); // Expected output: 1

//     // Test Case 2: Missing colon
//     char buffer2[] = "0 zero\n";
//     printf("Test Case 2: %d\n", check_lines(buffer2, 8)); // Expected output: -1

//     // Test Case 3: Extra characters after newline
//     char buffer3[] = "0: zero etra\n";
//     printf("Test Case 3: %d\n", check_lines(buffer3, 14)); // Expected output: -1

//     // Test Case 4: Valid line with spaces
//     char buffer4[] = "100: onehundred\n";
//     printf("Test Case 4: %d\n", check_lines(buffer4, 16)); // Expected output: -1

//     // Test Case 5: Line with leading spaces and valid
//     char buffer5[] = "  42: forty-two\n";
//     printf("Test Case 5: %d\n", check_lines(buffer5, 16)); // Expected output: -1

//     // Test Case 6: Empty buffer
//     char buffer6[] = "";
//     printf("Test Case 6: %d\n", check_lines(buffer6, 0)); // Expected output: -1 (or 1 if handling empty buffers correctly)

//     return 0;
// }
