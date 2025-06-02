#include <iostream>

using namespace std;

class Solution {
public:

    void  printArray(int array[], int size = 26) {
        for (int i = 0; i < size; i++) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }
    int canConstruct(string ransomNote, string magazine) {
        int array[26] = {0};
        if (ransomNote.size() > magazine.size()) {
            printArray(array);
            return -1;
        }
        for (int i = 0; i < magazine.size(); i++) {
            array[magazine[i] - 'a']++;
            printArray(array);
        }
        
        for (int j = 0; j < ransomNote.size(); j++) {
            array[ransomNote[j] - 'a']--;
            if (array[ransomNote[j] - 'a'] < 0) {
                printArray(array);
                return -1;
            }
        }
        return 1;
    }
};

int main() {
    Solution s;
    string ransomNote = "aa";
    string magazine = "aab";
    cout << s.canConstruct(ransomNote , magazine) << endl;
    return 0;
}