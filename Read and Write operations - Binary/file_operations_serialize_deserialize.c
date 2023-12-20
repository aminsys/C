#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char city[20];
    int age;
    float salary;

} Employee;

int readBinaryData(FILE* file_ptr);
int writeBinaryData(FILE* file_ptr);

int main(){

    FILE* file_ptr = fopen("./binary-info.bin", "wb");
    writeBinaryData(file_ptr);

    file_ptr = fopen("./binary-info.bin", "rb");
    readBinaryData(file_ptr);

    return EXIT_SUCCESS;
}

int readBinaryData(FILE* file_ptr){
    
    // Make sure that the deserialized object has the same type as the serialized object.
    if (file_ptr == NULL) {
        printf("\nCould not open the file\n");
        return EXIT_FAILURE;
    }

    Employee employee;

    fread(&employee, sizeof(Employee), 1, file_ptr);
    fclose(file_ptr);

    printf("Name: %s\n", employee.name);
    printf("City: %s\n", employee.city);
    printf("Age: %d\n", employee.age);
    printf("Salary: %.2f\n", employee.salary);

    return EXIT_SUCCESS;
}

int writeBinaryData(FILE* file_ptr){
    if(file_ptr == NULL){
        printf("\nCan't create a file.\n");
        return EXIT_FAILURE;
    }

    Employee employee;

    strcpy(employee.name, "Nancy Ajram");
    strcpy(employee.city, "Cairo");
    employee.age = 29;
    employee.salary = 39320.93;

    fwrite(&employee, sizeof(Employee), 1, file_ptr);

    fclose(file_ptr);

    return EXIT_SUCCESS;
}
