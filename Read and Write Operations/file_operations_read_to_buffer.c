#include <stdio.h>
#include <stdlib.h>

int main(){
    
    // Make sure to create a file name 'read-file-string-by-string.txt' with some content in it
    FILE* file_ptr = fopen("./read-file-string-by-string.txt", "r");
    char data_buffer[1048]; // Statically allocated array that occupies 1048 characters

    if(file_ptr == NULL){
        printf("The file could not be opened\n");
        return EXIT_FAILURE;
    }

    while(fgets(data_buffer, 1048, file_ptr) != NULL){
        putchar('|');
        printf("%s", data_buffer);
        fflush(stdout);
    }

    if(feof(file_ptr)){
        printf("\nEnd of file reached.\n");
    }
    else {
        printf("Something went wrong\n");
    }

    fclose(file_ptr);

    return EXIT_SUCCESS;
}