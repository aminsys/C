#include <stdlib.h>
#include <stdio.h>

int main(){

    char id[15];
    char name[30];
    char department[30];
    int age;

    // Make sure to create 'structured-records.csv' before
    FILE *file_ptr = fopen("./structured-records.csv", "r");

    if(file_ptr == NULL){
        printf("Couldn't open file.\n");
        return EXIT_FAILURE;
    }

    fscanf(file_ptr, "%*[^\n]\n"); // Read in the header with regex
    while(fscanf(file_ptr,"%[^,],%[^,],%[^,],%d\n",id, name, department, &age) != EOF){
        putchar('|');
        printf("%s, %s, %s, %d\n", id, name, department, age);
    }
    if(feof(file_ptr)){
        printf("\nEnd of file reached successfully!\n");
    } else {
        printf("\nSomething went wrong and file_ptr hasn't reached the end of the file\n");
    }

    fclose(file_ptr);

    return EXIT_SUCCESS;
}