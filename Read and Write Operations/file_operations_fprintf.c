// fprintf is used for writing structured data to file
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE* file_ptr = fopen("./fprinf-file.csv", "w");

    if(file_ptr == NULL){
        printf("File couldn't be created.\n");
        return EXIT_FAILURE;
    }

    const int num_records = 3; // Const variables must be initialized as they are declared.

    char name[3][20] = {"Henrik Gustafsson", "Samira Said", "Ken Shimura"};
    char department[3][25] = {"Human resources", "Marketing", "IT and internal Support"};
    char id[3][15] = {"HR0033", "MR102", "IT0029"};
    int age[3] = {33, 29, 53};

    fprintf(file_ptr, "ID, Name, Department, Age\n");

    for(int i = 0; i < num_records; i++){
        fprintf(file_ptr, "%s, %s, %s, %d\n", id[i], name[i], department[i], age[i]);
    }

    fclose(file_ptr);

    return EXIT_SUCCESS;
}