#include <stdio.h>
#include <stdlib.h>

//  Load PIN from file
int loadPin() {
    FILE *fp = fopen("pin.txt", "r");
    int pin;
    if (fp == NULL) {
        // First time use: create default PIN 1234
        fp = fopen("pin.txt", "w");
        fprintf(fp, "1234");
        fclose(fp);
        return 1234;
    }
    fscanf(fp, "%d", &pin);
    fclose(fp);
    return pin;
}

//  Save new PIN to file
void savePin(int newPin) {
    FILE *fp = fopen("pin.txt", "w");
    if (fp == NULL) {
        printf("Error saving new PIN.\n");
        return;
    }
    fprintf(fp, "%d", newPin);
    fclose(fp);
}

//  Load balance from file
float loadBalance() {
    FILE *fp = fopen("balance.txt", "r");
    float balance = 0.0;
    if (fp != NULL) {
        fscanf(fp, "%f", &balance);
        fclose(fp);
    }
    return balance;
}

// Save balance to file
void saveBalance(float balance) {
    FILE *fp = fopen("balance.txt", "w");
    if (fp != NULL) {
        fprintf(fp, "%.2f", balance);
        fclose(fp);
    }
}

//  Show ATM menu
void showMenu() {
    printf("\n===== ATM MENU =====\n");
    printf("1. Check Balance\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Change PIN\n");
    printf("5. Exit\n");
    printf("====================\n");
    printf("Enter your choice: ");
}

//  Change PIN
void changePin(int currentPin) {
    int oldPin, newPin, confirmPin;

    printf("Enter current PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != currentPin) {
        printf("❌ Incorrect current PIN!\n");
        return;
    }

    printf("Enter new PIN: ");
    scanf("%d", &newPin);
    printf("Confirm new PIN: ");
    scanf("%d", &confirmPin);

    if (newPin != confirmPin) {
        printf("❌ PINs do not match!\n");
        return;
    }

    savePin(newPin);
    printf(" PIN changed successfully!\n");
}

int main() {
    int enteredPin, choice;
    float balance, amount;

    int currentPin = loadPin();

    //  Login
    printf("Enter your 4-digit PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin != currentPin) {
        printf("❌ Incorrect PIN. Access denied!\n");
        return 0;
    }

    printf(" Login successful!\n");
    balance = loadBalance();

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf(" Your balance is: ₹%.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ₹");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    saveBalance(balance);
                    printf(" ₹%.2f deposited.\n", amount);
                } else {
                    printf("❌ Invalid amount.\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ₹");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    saveBalance(balance);
                    printf(" ₹%.2f withdrawn.\n", amount);
                } else {
                    printf("❌ Invalid or insufficient amount.\n");
                }
                break;

            case 4:
                changePin(currentPin);
                currentPin = loadPin();  // Reload new PIN
                break;

            case 5:
                printf(" Thank you! Exiting...\n");
                saveBalance(balance);
                exit(0);

            default:
                printf("❌ Invalid choice. Try again.\n");
        }
    }

    return 0;
}
