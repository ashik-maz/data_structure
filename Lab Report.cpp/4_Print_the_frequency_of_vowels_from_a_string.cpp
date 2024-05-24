//4.Print the frequency of vowels from a string
#include <iostream>
using namespace std;
void countVowelFrequencies(char input[], int length) {
    int vowelFreq[5] = {0}; 
    for (int i = 0; i < length; ++i) {
        char ch = input[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + ('a' - 'A');
        }
        switch (ch) {
            case 'a': vowelFreq[0]++; break;
            case 'e': vowelFreq[1]++; break;
            case 'i': vowelFreq[2]++; break;
            case 'o': vowelFreq[3]++; break;
            case 'u': vowelFreq[4]++; break;
        }
    }
    cout << "Vowel frequencies:\n";
    cout << "a: " << vowelFreq[0] << endl;
    cout << "e: " << vowelFreq[1] << endl;
    cout << "i: " << vowelFreq[2] << endl;
    cout << "o: " << vowelFreq[3] << endl;
    cout << "u: " << vowelFreq[4] << endl;
}

int main() {
    char input[100];
    int length = 0;

    cout << "Enter a string: ";
    char ch;
    while (cin.get(ch) && ch != '\n') {
        input[length++] = ch;
    }
    countVowelFrequencies(input, length);

    return 0;
}
