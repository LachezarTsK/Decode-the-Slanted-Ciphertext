
function decodeCiphertext(encodedText: string, rows: number): string {
    const NO_TEXT = "";
    if (rows === 1) {
        return encodedText;
    }
    if (encodedText.length === 0) {
        return NO_TEXT;
    }

    let lastNonSpaceIndexInOriginalText = 0;
    const columns = Math.floor(encodedText.length / rows);
    const originalText: string[] = new Array();

    for (let column = 0; column < columns; ++column) {
        let index = column;

        while (index < encodedText.length) {
            if (encodedText.charAt(index) !== ' ') {
                lastNonSpaceIndexInOriginalText = originalText.length;
            }
            originalText.push(encodedText.charAt(index));
            index += columns + 1;
        }
    }

    return originalText.join('').substring(0, lastNonSpaceIndexInOriginalText + 1);
};
