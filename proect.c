#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[30];
    float amount;
};

void addExpense() {
    FILE *fp = fopen("expenses.txt", "a");
    struct Expense e;

    printf("Enter category (Food/Travel/Study/etc): ");
    scanf("%s", e.category);

    printf("Enter amount: ");
    scanf("%f", &e.amount);

    fwrite(&e, sizeof(e), 1, fp);
    fclose(fp);

    printf("✅ Expense added successfully!\n");
}

void viewExpenses() {
    FILE *fp = fopen("expenses.txt", "r");
    struct Expense e;
    float total = 0;

    if (fp == NULL) {
        printf("No expenses found!\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    while (fread(&e, sizeof(e), 1, fp)) {
        printf("Category: %-10s Amount: ₹%.2f\n", e.category, e.amount);
        total += e.amount;
    }

    printf("---------------------\n");
    printf("Total Expense: ₹%.2f\n", total);

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n💰 SMART EXPENSE TRACKER 💰\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                printf("Thank you for using Expense Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}