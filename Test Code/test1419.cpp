def extractCopyrightYear(copyrightText: str) -> str:
    # Find the first occurrence of the copyright symbol (©)
    copyrightSymbolIndex = copyrightText.find("©")

    # If the copyright symbol is not found, return an empty string
    if copyrightSymbolIndex == -1:
        return ""

    # Find the first occurrence of a digit after the copyright symbol
    digitIndex = copyrightText.find(digit, copyrightSymbolIndex + 1)

    # If a digit is not found, return an empty string
    if digitIndex == -1:
        return ""

    # Find the first occurrence of a hyphen after the digit
    hyphenIndex = copyrightText.find("-", digitIndex + 1)

    # If a hyphen is not found, return the year as a string
    if hyphenIndex == -1:
        return copyrightText[digitIndex:digitIndex + 4]

    # Return the range of years as a string
    return copyrightText[digitIndex:hyphenIndex]
