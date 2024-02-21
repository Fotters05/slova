#include <iostream>
#include <string>

using namespace std;

void reverseWord(string& word) {
    int n = word.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = word[i];
        word[i] = word[n - i - 1];
        word[n - i - 1] = temp;
    }
    cout << "Реверс: " << word << endl;
}

void noVowels(string& word) {
    string result;
    for (char c : word) {
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    cout << "Без гласных: " << result << endl;
}

void noConsonants(string& word) {
    string result;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            result += c;
        }
    }
    cout << "Без согласных: " << result << endl;
}

void random(string& word) {
    srand(time(0));
    int n = word.length();
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        char temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << "Рандомная перестановка: " << word << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    string word;
    int choice;

    cout << "Введите слово: ";
    cin >> word;

    while (true) {
        cout << "Выберите действие:" << endl;
        cout << "1. Наоборот." << endl;
        cout << "2. Без гласных." << endl;
        cout << "3. Без согласных." << endl;
        cout << "4. Рандомные буквы" << endl;
        cin >> choice;

        if (choice == 1) {
            reverseWord(word);
        }
        else if (choice == 2) {
            noVowels(word);
        }
        else if (choice == 3) {
            noConsonants(word);
        }
        else if (choice == 4) {
            random(word);
        }
        else {
            cout << "Неверный ввод." << endl;
            continue;
        }
    }

    return 0;
}