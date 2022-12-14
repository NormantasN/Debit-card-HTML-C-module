#ifndef MODULIS_H_INCLUDED
#define MODULIS_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30
#define DATE_SIZE 5
#define NUMBER_SIZE 20
#define CVV_SIZE 3

typedef struct cards{
    char name[MAX_SIZE];
    char surname[MAX_SIZE];
    char number[NUMBER_SIZE];
    char date[DATE_SIZE];
    int cvv;
}card;

// Prototypes
void readInput(card*);
void printToHtml(card*);

#endif // MODULIS_H_INCLUDED
