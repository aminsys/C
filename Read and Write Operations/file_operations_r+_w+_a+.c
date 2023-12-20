#include <stdlib.h>
#include <stdio.h>

void readPlusFile(FILE* file_ptr);
void writePlusFile(FILE* file_ptr);
void appendPlusFile(FILE* file_ptr);
int fileOperations(FILE* file_ptr);

int main(){

    FILE* file_ptr = fopen("./file-content.txt", "r+");
    readPlusFile(file_ptr);

    file_ptr = fopen("./file-content.txt", "w+");
    writePlusFile(file_ptr);

    file_ptr = fopen("./file-content.txt", "a+");
    appendPlusFile(file_ptr);

    return EXIT_SUCCESS;
}

void readPlusFile(FILE* file_ptr){

    fileOperations(file_ptr);

    fputs("========== r+ ===========\n"
    "This text is an example text to use while opening a file in the r+ mode.\n", file_ptr);
    fputs("Great minds think alike."
    "\n-Typical classmate\n", file_ptr);

    printf("\nFinished reading from file\n");
    fclose(file_ptr);
}

void writePlusFile(FILE* file_ptr){
    
    fileOperations(file_ptr);

    fputs("========== w+ ===========\n"
    "This text is an example text to use while opening a file in the w+ mode.\n", file_ptr);
    fputs("Great minds think alike."
    "\n-Typical classmate\n", file_ptr);

    printf("\nFinished writing to file\n");
    fclose(file_ptr);
}

void appendPlusFile(FILE* file_ptr){

    fileOperations(file_ptr);

    fputs("========== a+ ===========\n"
    "This text is an example text to use while opening a file in the a+ mode.\n", file_ptr);
    fputs("Great minds think alike."
    "\n-Typical classmate\n", file_ptr);

    printf("\nFinished appending to file\n");
    fclose(file_ptr);
}

int fileOperations(FILE* file_ptr){
    if(file_ptr==NULL){
        printf("\nCouldn't open the file.\n");
        return EXIT_FAILURE;
    }

    char data_buffer[1048];
    while(fgets(data_buffer,1048,file_ptr) != NULL){
        printf("%s", data_buffer);
        fflush(stdout);
    }
}