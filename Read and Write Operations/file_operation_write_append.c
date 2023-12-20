#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(){

    // FILE* file_ptr = fopen("./write-to-file.txt", "w"); // w creates a file if it doesn't exist.
    // Use the code below to append data to an existing file.
    FILE* file_ptr = fopen("./write-to-file.txt", "a");


    if(file_ptr == NULL){
        printf("The file could not be opened, error number: %d\n", errno);
        printf("Error opening file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    
    char text[] = "File handling is an integral part of many medium-to-large-scale programs in C.\nFiles are the most convenient way of managing data for the wide range of programs of this size";

    for(int i = 0; text[i] != '\0'; i++){
        fputc(text[i], file_ptr);
    }

    fclose(file_ptr);
    return EXIT_SUCCESS;
}