#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/brkiter.h>

#include "qatomicstring_p.h"
#include "qtocodepointsiterator_p.h"
#include "qassemblestringfns_p.h"

QT_BEGIN_NAMESPACE

using namespace QPatternist;

QString processString(const QString &input) {
    // Normalize the input string using Unicode normalization form C (NFC)
    UnicodeString unicodeInput = UnicodeString::fromUTF8(input.toUtf8().constData());
    unicodeInput = unicodeInput.unormalize(UNORM_NFC);

    // Convert the normalized string to uppercase
    unicodeInput.toUpper();

    // Replace any occurrences of the substring "QT" with "qatomicstring"
    UnicodeString qtString = "QT";
    UnicodeString replacementString = "qatomicstring";
    unicodeInput.findAndReplace(qtString, replacementString);

    return QString::fromUtf8(unicodeInput.toUTF8());
}

QT_END_NAMESPACE
