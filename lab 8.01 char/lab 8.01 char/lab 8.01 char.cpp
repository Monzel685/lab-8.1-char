#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

char* ReplacePatternWithAsterisks(const char* s, bool& foundPattern) {
    foundPattern = false;
    // Виділяємо пам'ять для результату (масив символів розміром 201)
    char* result = new char[201];
    result[0] = '\0';  // Ініціалізуємо порожнім рядком
    int t_size = 200;
    int j = 0;
    const char* current = s;

    while (*current != '\0') {
        if ((strncmp(current, "OGO", 3) == 0) || (strncmp(current, "AGA", 3) == 0)) {
            if (j + 2 < t_size) {
                strcat(result, "**");
                j += 2;
                foundPattern = true;
            }
            current += 3;
        }
        else {
            if (j < t_size - 1) {
                result[j] = *current;
                result[j + 1] = '\0';
                j++;
            }
            current++;
        }
    }

    return result;  // Повертаємо вказівник на динамічно виділену пам'ять
}

int main() {
    // Виділяємо пам'ять для вводу користувача (масив символів розміром 101)
    char* str = new char[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);  // Зчитуємо рядок від користувача

    bool foundPattern;
    // Викликаємо функцію для заміни шаблонів
    char* result = ReplacePatternWithAsterisks(str, foundPattern);

    // Виводимо результат
    if (foundPattern) {
        cout << "Pattern 'OGO' or 'AGA' found: yes" << endl;
    }
    else {
        cout << "Pattern 'OGO' or 'AGA' found: no" << endl;
    }

    cout << "Modified string: " << result << endl;

    // Звільняємо пам'ять після використання
    delete[] str;   // Звільняємо пам'ять, виділену для вводу
    delete[] result;  // Звільняємо пам'ять, виділену для результату

    return 0;
}
