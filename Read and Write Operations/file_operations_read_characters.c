#include <stdio.h>
#include <stdlib.h>

int main(){

    // Make sure to create a file named 'read-file-character-by-character.txt' with some content in
    FILE* file_ptr = fopen("./read-file-character-by-character.txt", "r");

    if(file_ptr == NULL){
        printf("\nThe file could not be opened!\n");
        return EXIT_FAILURE;
    }

    int ch = fgetc(file_ptr); // getc can also be used

    while(ch != EOF){
        putchar('|'); // to show that the file is read character by character
        putchar(ch);
        ch = fgetc(file_ptr);
    }

    if(feof(file_ptr)){
        printf("\nEnd of file reached.\n");
    } else {
        printf("\nSomething went wrong.\n");
    }

    fclose(file_ptr);

    return EXIT_SUCCESS;
}