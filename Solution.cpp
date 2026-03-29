
#include <string>
using namespace std;

class Solution {

    inline static const string NO_TEXT = "";

public:
    string decodeCiphertext(string encodedText, int rows) {
        if (rows == 1) {
            return encodedText;
        }
        if (encodedText.empty()) {
            return NO_TEXT;
        }

        int lastNonSpaceIndexInOriginalText = 0;
        int columns = encodedText.length() / rows;
        string originalText;

        for (int column = 0; column < columns; ++column) {
            int index = column;

            while (index < encodedText.length()) {
                if (encodedText[index] != ' ') {
                    lastNonSpaceIndexInOriginalText = originalText.length();
                }
                originalText.push_back(encodedText[index]);
                index += columns + 1;
            }
        }

        return originalText.substr(0, lastNonSpaceIndexInOriginalText + 1);
    }
};
