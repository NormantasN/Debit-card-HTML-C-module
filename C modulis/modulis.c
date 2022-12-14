#include "modulis.h"

void readInput(card *c){
    printf("Iveskite savo varda\n");
    scanf("%s", &c->name);
    printf("Iveskite savo pavarde\n");
    scanf("%s", &c->surname);
    printf("Iveskite savo korteles numeri (be tarpu)\n");
    scanf("%s", &c->number);
    printf("Iveskite savo korteles galiojimo data 00/00\n");
    scanf("%s", &c->date);
        fflush(stdout);
    printf("Iveskite savo korteles CVV\n");
    scanf("%d", &c->cvv);
    strcat(c->name, " ");
    strcat(c->name, c->surname);
    // printf("%s\n", c->name);
    // printf("%s\n", c->number);
    // printf("%s\n", c->date);
    // printf("%d\n", c->cvv);
    printf("Done\n\n");
}

void printToHtml(card *c){
    FILE* ptr_file = fopen("input.txt", "rb");
    FILE* ptr = fopen("RUNTIMEERROR.html", "w");
    char blog[1000];
    // printf("%s\n", &c->name);
    // printf("%s\n", &c->surname);
    // printf("%s\n", &c->number);
    // printf("%s\n", &c->date);
    // printf("%d\n", c->cvv);
    //char name[MAX_SIZE] = "Jonas Petraitis";
    //char number[] = "1234567891234567";
    //char date[] = "12/26";
    //char cvv[] = "299";

    char cvv[CVV_SIZE];
    fseek(ptr_file, 0, SEEK_END);
    long size = ftell(ptr_file);
    fseek(ptr_file, 0, SEEK_SET);

    char* content = calloc(size + 1, sizeof(char));
    fread(content, sizeof(char), size, ptr_file);
    fclose(ptr_file);

    char *posNumb = strstr(content, "2613 0744 9020 80");
    char *posName = strstr(content, "Vardenis Pavardenis");
    char *posDate = strstr(content, "02/26 ");
    char *posCvv = strstr(content, "540 ");

    if(posName == NULL)
        fprintf(stderr, "File is not valid\n");

    strcpy(posNumb, c->number);
    strcpy(posName, c->name);
    strcpy(posDate, c->date);
    sprintf(cvv, "%d", c->cvv); // Disclaimer: Konvertavimas int->string butinas, nes negalima cvv iskart apsirasyt kaip stringo, kadangi isvestis buna klaidinga - cvv buna pakartojamas 2 kartus
    strcpy(posCvv, cvv);

    // printf("The substring is: %s\n", posName);
    // printf("The substring is: %s\n", posNumb);
    // printf("The substring is: %s\n", posDate);
    // printf("The substring is: %s\n", posCvv);
    fwrite(content, sizeof(char), size, ptr);
    free(content);
    fclose(ptr);
}
