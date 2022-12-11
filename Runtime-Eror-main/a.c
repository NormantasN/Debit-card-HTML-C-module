#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30
#define DATE_SIZE 5
#define NUMBER_SIZE 20
#define CVV_SIZE 4

typedef struct cards{
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    char number[NUMBER_SIZE];
    char date[DATE_SIZE];
    char cvv[CVV_SIZE];
}card;

card c;

// Prototypes
//void readInput(card c);
void printToHtml();

int main()
{   
    //readInput(c);
    printToHtml();
    return 0;
}

// void readInput(card c){
//     printf("Iveskite savo varda\n");
//     scanf("%s", &c.name);
//     printf("Iveskite savo pavarde\n");
//     scanf("%s", &c.surname);
//     printf("Iveskite savo korteles numeri\n");
//     scanf("%s", &c.number);
//     printf("Iveskite savo korteles galiojimo data 00/00\n");
//     scanf("%s", &c.date);
//     printf("Iveskite savo korteles CVV\n");
//     scanf("%s", &c.cvv);
//     strcat(c.name, c.surname);
//     printf("%s\n", c.name);
//     printf("%s\n", c.number);
//     printf("%s\n", c.date);
//     printf("%s\n", c.cvv);
//     printf("Done\n\n");
// }

void printToHtml(card c){
    FILE* ptr_file = fopen("input.txt", "rb");
    FILE* ptr = fopen("RUNTIMEERROR.html", "w");
    
    char name[MAX_SIZE] = "Jonas Petraitis";
    char blog[1000];
    // printf("%s\n", c.number);
    // printf("%s\n", c.date);
    // printf("%s\n", c.cvv);
    char number[] = "1234567891234567";
    char date[] = "12/26";
    char cvv[] = "299";

    fseek(ptr_file, 0, SEEK_END);
    long size = ftell(ptr_file);
    fseek(ptr_file, 0, SEEK_SET);

    char* content = calloc(size + 1, sizeof(char));
    fread(content, sizeof(char), size, ptr_file);
    fclose(ptr_file);

    char *posNumb = strstr(content, "2613 0744 9020 8004 ");
    char *posName = strstr(content, "Vardenis Pavardenis");
    char *posDate = strstr(content, "02/26 ");
    char *posCvv = strstr(content, "540 ");

    if(posName == NULL)
        fprintf(stderr, "File is not valid\n");

    strcpy(posNumb, number);
    strcpy(posName, name);
    strcpy(posDate, date);
    strcpy(posCvv, cvv);

    printf("The substring is: %s\n", posName);
    printf("The substring is: %s\n", posNumb);
    printf("The substring is: %s\n", posDate);
    printf("The substring is: %s\n", posCvv);
    fwrite(content, sizeof(char), size, ptr);
    free(content);   
    fclose(ptr); 
}