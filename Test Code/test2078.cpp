#include <stdio.h>

typedef struct Point {
    int x;
    int y;
    struct Point *next_point;
} Point;

#define SGLIB_LIST_DELETE(type, list, elem, next) // Macro to delete elem from list
#define SGLIB_LIST_REVERSE(type, list, next) // Macro to reverse the list
#define SGLIB_LIST_ADD(type, list, elem, next) // Macro to add elem to list

void printPoints(Point *list) {
    Point *current = list;
    while (current != NULL) {
        printf("(%d, %d) -> ", current->x, current->y);
        current = current->next_point;
    }
    printf("NULL\n");
}

int main() {
    // Assume listaPunktow<T> is defined as Point<T>
    Point *lista = NULL; // Assume lista is initialized with some points
    Point *dolaczanyCiag = NULL; // Assume dolaczanyCiag is initialized with some points
    int konfiguracja = 2; // Assume konfiguracja is initialized with some value

    // Your code to handle konfiguracja equal to 2
    if (konfiguracja == 2) {
        // Add logic for konfiguracja equal to 2
        // For example, reversing the list and adding it back
        SGLIB_LIST_REVERSE(Point, dolaczanyCiag, next_point);
        Point *current = dolaczanyCiag;
        while (current->next_point != NULL) {
            current = current->next_point;
        }
        current->next_point = lista;
        lista = dolaczanyCiag;
        dolaczanyCiag = NULL;
    }

    printPoints(lista); // Call the function to print the points in the linked list

    return 0;
}
