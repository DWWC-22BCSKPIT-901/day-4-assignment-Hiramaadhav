#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> charCount;

    // Step 1: Count the frequency of each character
    for (char c : s) {
        charCount[c]++;
    }

    // Step 2: Find the first character with a count of 1
    for (int i = 0; i < s.length(); i++) {
        if (charCount[s[i]] == 1) {
            return i;
        }
    }

    // Step 3: If no unique character found, return -1
    return -1;
}

int main() {
    string s = "loveleetcode";
    int result = firstUniqChar(s);
    if (result != -1) {
        cout << "The first non-repeating character is at index: " << result << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }

    return 0;
}
