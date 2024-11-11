#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// Функція для підрахунку символів B, A, S, I, C у рядку за допомогою стандартних функцій C
void countBASICCharsStandard(const char* str, int& countB, int& countA, int& countS, int& countI, int& countC) {
    countB = countA = countS = countI = countC = 0;

    // Проходимо рядок і рахуємо кожен символ
    for (size_t i = 0; i < strlen(str); i++) {
        switch (str[i]) {
            case 'B': countB++; break;
            case 'A': countA++; break;
            case 'S': countS++; break;
            case 'I': countI++; break;
            case 'C': countC++; break;
        }
    }
}

// Функція для заміни всіх входжень "BASIC" на "Delphi" за допомогою стандартних функцій C
char* replaceBASICWithDelphiStandard(char* str) {
    const char* search = "BASIC";
    const char* replace = "Delphi";
    size_t searchLen = strlen(search);
    size_t replaceLen = strlen(replace);

    // Вираховуємо максимальний розмір нового рядка
    size_t newSize = strlen(str) * 2 + 1;
    char* result = new char[newSize];
    char* dest = result;

    // Шукаємо входження "BASIC" та копіюємо решту рядка
    while (*str) {
        char* pos = strstr(str, search);
        if (pos) {
            // Копіюємо частину до "BASIC"
            size_t len = pos - str;
            strncpy(dest, str, len);
            dest += len;
            // Копіюємо "Delphi"
            strcpy(dest, replace);
            dest += replaceLen;
            str = pos + searchLen; // Пересуваємо покажчик далі після "BASIC"
        } else {
            // Копіюємо решту рядка
            strcpy(dest, str);
            break;
        }
    }

    return result;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Лічильники символів B, A, S, I, C
    int countB, countA, countS, countI, countC;
    countBASICCharsStandard(str, countB, countA, countS, countI, countC);

    // Виведення результату підрахунку символів
    cout << "Count of B: " << countB << endl;
    cout << "Count of A: " << countA << endl;
    cout << "Count of S: " << countS << endl;
    cout << "Count of I: " << countI << endl;
    cout << "Count of C: " << countC << endl;

    // Замінюємо "BASIC" на "Delphi" і виводимо результат
    char* modifiedStr = replaceBASICWithDelphiStandard(str);
    cout << "Modified string: " << modifiedStr << endl;

    // Звільняємо виділену пам'ять
    delete[] modifiedStr;

    return 0;
}
