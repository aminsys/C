#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* file_ptr = fopen("./binary-data.bin", "wb");

    if(file_ptr == NULL){
        printf("\nError creating the file.\n");
        return EXIT_FAILURE;
    }

    char name[20] = "James Darwin";
    char city[10] = "Seattle";
    int age = 24;
    float salary = 12300.23;

    fwrite(name, sizeof(char), 20, file_ptr);
    fwrite(city, sizeof(char), 10, file_ptr);
    fwrite(&age, sizeof(int), 1, file_ptr);
    fwrite(&salary, sizeof(float), 1, file_ptr);

    fclose(file_ptr);

    return EXIT_SUCCESS;
}