#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 40

void strcat_pos(char string1[], char string2[], char string_final[], int pos);

int main()
{
    setlocale(LC_ALL, "portuguese");
    char string1[TAM], string2[TAM], string_final[TAM * 2] = {'\0'};
    int pos;

    printf("Digite seu nome: ");
    scanf("%s", string1);
    printf("Digite o sobrenome a ser concatenado: ");
    scanf("%s", string2);
    printf("Digite a posição para concatenar: ");
    scanf("%d", &pos);

    strcat_pos(string1, string2, string_final, pos);

    printf("String final: %s\n", string_final);

    return 0;
}

void strcat_pos(char string1[], char string2[], char string_final[], int pos)
{
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    
    // Copy the characters from string1 to string_final until the specified position
    for (int i = 0; i < pos && i < len1; i++) {
        string_final[i] = string1[i];
    }
    
    // Concatenate string2 into string_final at the specified position
    for (int i = 0; i < len2; i++) {
        string_final[pos + i] = string2[i];
    }
    
    // Concatenate the remaining characters from string1 into string_final
    for (int i = pos; i < len1; i++) {
        string_final[len2 + i] = string1[i];
    }
}
