#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* file_ptr = fopen("./binary-data.bin", "rb");

    if(file_ptr == NULL){
        printf("\nError: Cannot open the file.\n");
        return EXIT_FAILURE;
    }

    char name[20];
    char city[10];
    int age;
    float salary;

    fread(name, sizeof(char), 20, file_ptr);
    fread(city, sizeof(char), 10, file_ptr);
    fread(&age, sizeof(int), 1, file_ptr);
    fread(&salary, sizeof(float), 1, file_ptr);

    fclose(file_ptr);

    printf("Name: %s\n", name);
    printf("City: %s\n", city);
    printf("Age: %d\n", age);
    printf("Salary: %f\n", salary);

    return EXIT_SUCCESS;
}