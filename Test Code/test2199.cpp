#include <pcre.h>
#include <QDebug>

void compileRegularExpression(const QString& pattern) {
    int options = 0; // Initialize options for PCRE
    options |= PCRE_CASELESS; // Set the option for case-insensitive matching

    const char* error;
    int errOffset;

    auto re = pcre_compile(pattern.toUtf8().constData(), options, &error, &errOffset, NULL);

    if (!re) {
        qWarning() << Q_FUNC_INFO << "failed compiling regular expression: " << error;
    } else {
        // Regular expression compilation successful, further processing can be done here
    }
}

int main() {
    QString regexPattern = "your_regular_expression_pattern_here";
    compileRegularExpression(regexPattern);
    return 0;
}
