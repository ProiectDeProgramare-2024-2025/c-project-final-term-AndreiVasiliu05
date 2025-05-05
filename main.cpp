#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_RESERVED 10

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
typedef struct {
    char name[50];
} Item;

Item inventory[MAX_ITEMS] = { {"Paracetamol"}, {"Aspirin"}, {"Ibuprofen"} };
int itemCount = 3;
Item reservedItems[MAX_RESERVED];
int reservedCount = 0;

void viewItems();
void reserveItem();
void addItem();
void removeItem();
void viewReservedItems();

int main() {
    int choice = 0;
        clearScreen()
    while (1) {
        printf("\n-= Sistem pentru rezervarea produselor din farmacie =-\n");
        printf("1) Vizualizare produse\n");
        printf("2) Rezervare produse\n");
        printf("3) Adaugare produse\n");
        printf("4) Stergere produse\n");
        printf("5) Vizualizare produse rezervate\n");
        printf("6) Quit\n");
        printf("Ce doresti sa faci: ");

        if (scanf("%d", &choice) != 1) {
            printf("Eroare: Introdu un numar valid!\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                viewItems();
                break;
            case 2:
                reserveItem();
                break;
            case 3:
                addItem();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                viewReservedItems();
                break;
            case 6:
                printf("Iesire din program...\n");
                return 0;
            default:
                printf("Optiune invalida! Alege un numar intre 1 si 6.\n");
        }
    }
}

// Afiseaza lista de produse disponibile
void viewItems() {
    clearScreen()
    printf("\n--- Produse disponibile ---\n");
    if (itemCount == 0) {
        printf("Nu exista produse in inventar.\n");
    } else {
        for (int i = 0; i < itemCount; i++) {
            printf("%d) %s\n", i + 1, inventory[i].name);
        }
    }
}

// Permite utilizatorului sa rezerve un produs
void reserveItem() {
    clearScreen()
    int choice;
    viewItems();
    if (itemCount == 0) return;

    printf("\nIntrodu numarul produsului pe care doresti sa-l rezervi: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > itemCount) {
        printf("Numar invalid!\n");
        return;
    }

    if (reservedCount < MAX_RESERVED)
        clearScreen()
        reservedItems[reservedCount++] = inventory[choice - 1];
        printf("Ai rezervat: %s\n", inventory[choice - 1].name);
    } else {
        printf("Nu mai poti rezerva produse! Lista este plina.\n");
    }
}

// Permite adaugarea unui produs in inventar
void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Nu mai poti adauga produse! Inventarul este plin.\n");
        return;
    }

    printf("Introdu numele produsului: ");
    scanf(" %[^\n]", inventory[itemCount].name);
    itemCount++;
    printf("Produs adaugat cu succes!\n");
}

// Permite stergerea unui produs din inventar
void removeItem() {
    clearScreen()
    int choice;
    viewItems();
    if (itemCount == 0) return;

    printf("\nIntrodu numarul produsului pe care doresti sa-l stergi: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > itemCount) {
        printf("Numar invalid!\n");
        return;
    }

    // Sterge elementul si muta restul
    for (int i = choice - 1; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;

    printf("Produsul a fost sters!\n");
}

// Afiseaza lista produselor rezervate
void viewReservedItems() {
    clearScreen()
    printf("\n--- Produse rezervate ---\n");
    if (reservedCount == 0) {
        printf("Nu ai rezervat niciun produs.\n");
    } else {
        for (int i = 0; i < reservedCount; i++) {
            printf("%d) %s\n", i + 1, reservedItems[i].name);
        }
    }
}
