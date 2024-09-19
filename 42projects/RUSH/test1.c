// #include <fcntl.h>    // for open
// #include <unistd.h>   // for read, close
// #include <stdlib.h>   // for malloc, free

// ssize_t count_file_bytes(const char *filename)
// {
//     int fd;
//     char buffer[128];
//     ssize_t total_bytes = 0;
//     ssize_t bytes_read = 1; // Initialize to enter loop

//     fd = open(filename, O_RDONLY);
//     if (fd == -1)
//         return -1; // Error opening file

//     while (bytes_read > 0)
//     {
//         bytes_read = read(fd, buffer, sizeof(buffer));
//         if (bytes_read == -1)
//         {
//             close(fd);
//             return -1; // Error reading file
//         }
//         total_bytes += bytes_read;
//     }

//     close(fd);
//     return total_bytes;
// }

// int main(void)
// {
//     ssize_t size;
//     char buf[50];
//     int len;

//     size = count_file_bytes("number.digit");
//     if (size == -1)
//         write(2, "Error counting file bytes\n", 27);
//     else
//     {
//         len = snprintf(buf, sizeof(buf), "File size: %zd bytes\n", size);
//         write(1, buf, len);
//     }
//     return 0;
// }
