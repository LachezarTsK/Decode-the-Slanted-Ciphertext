
class Solution {

    private companion object {
        const val NO_TEXT = ""
    }

    fun decodeCiphertext(encodedText: String, rows: Int): String {
        if (rows == 1) {
            return encodedText
        }
        if (encodedText.isEmpty()) {
            return NO_TEXT
        }

        var lastNonSpaceIndexInOriginalText = 0
        val columns = encodedText.length / rows
        val originalText = StringBuilder()

        for (column in 0..<columns) {
            var index = column

            while (index < encodedText.length) {
                if (encodedText[index] != ' ') {
                    lastNonSpaceIndexInOriginalText = originalText.length
                }
                originalText.append(encodedText[index])
                index += columns + 1
            }
        }

        return originalText.toString().substring(0, lastNonSpaceIndexInOriginalText + 1)
    }
}
