
package main
import "strings"

const NO_TEXT = ""

func decodeCiphertext(encodedText string, rows int) string {
    if rows == 1 {
        return encodedText
    }
    if len(encodedText) == 0 {
        return NO_TEXT
    }

    lastNonSpaceIndexInOriginalText := 0
    columns := len(encodedText) / rows
    originalText := strings.Builder{}

    for column := range columns {
        var index = column

        for index < len(encodedText) {
            if encodedText[index] != ' ' {
                lastNonSpaceIndexInOriginalText = originalText.Len()
            }
            originalText.WriteByte(encodedText[index])
            index += columns + 1
        }
    }

    return originalText.String()[0 : lastNonSpaceIndexInOriginalText + 1]
}
