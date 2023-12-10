QT_BEGIN_NAMESPACE

QString processString(const QString &input)
{
    // Normalize the input string using Unicode normalization form C (NFC)
    QString normalizedInput = QString::fromRawData(input.toRawData(), input.size(), QString::NormalizationForm_C);

    // Convert the normalized string to uppercase
    QString uppercaseInput = normalizedInput.toUpper();

    // Replace any occurrences of the substring "QT" with "qatomicstring"
    QString processedInput = uppercaseInput.replace("QT", "qatomicstring");

    return processedInput;
}

QT_END_NAMESPACE
