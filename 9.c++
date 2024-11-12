#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to create the LPS (Longest Prefix Suffix) array
vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Function to find all occurrences of pattern `p` in text `s`
void KMPSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    // Preprocess the pattern (create LPS array)
    vector<int> lps = computeLPSArray(pattern);

    int i = 0; // index for text
    int j = 0; // index for pattern
    vector<int> occurrences;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Found a match
            occurrences.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    // Output all occurrences of the pattern
    cout << "Pattern found at indices: ";
    for (int idx : occurrences) {
        cout << idx << " ";
    }
    cout << endl;
}

int main() {
    string text = "ababcababcabcababc";
    string pattern = "abc";

    KMPSearch(text, pattern);

    return 0;
}
