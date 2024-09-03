//4.Print the frequency of vowels from a string
#include <iostream>
#include <string>
using namespace std;

void countVowelFrequencies(const string &input) {
    int vowelFreq[5] = {0};
    for (char ch : input) {
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
    string input;

    cout << "Enter a string: ";
    getline(cin, input);  // Using getline to read the entire line

    countVowelFrequencies(input);

    return 0;
}
