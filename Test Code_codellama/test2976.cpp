void decompressFile(std::istream& _decompress, std::ostream& _dest) {
    char ch;
    while (_decompress.get(ch)) {
        if (ch == ' ') {
            _dest.put(' ');
        } else if (ch == '!') {
            _dest.put('!');
        } else if (ch == '?') {
            _dest.put('?');
        } else if (ch == '*') {
            _dest.put('*');
        } else if (ch == '+') {
            _dest.put('+');
        } else if (ch == '-') {
            _dest.put('-');
        } else if (ch == '=') {
            _dest.put('=');
        } else if (ch == ':') {
            _dest.put(':');
        } else if (ch == ';') {
            _dest.put(';');
        } else if (ch == '[') {
            _dest.put('[');
        } else if (ch == ']') {
            _dest.put(']');
        } else if (ch == '{') {
            _dest.put('{');
        } else if (ch == '}') {
            _dest.put('}');
        } else if (ch == '(') {
            _dest.put('(');
        } else if (ch == ')') {
            _dest.put(')');
        } else if (ch == '|') {
            _dest.put('|');
        } else if (ch == '&') {
            _dest.put('&');
        } else if (ch == '^') {
            _dest.put('^');
        } else if (ch == '~') {
            _dest.put('~');
        } else if (ch == '`') {
            _dest.put('`');
        } else if (ch == '\\') {
            _dest.put('\\');
        } else if (ch == '/') {
            _dest.put('/');
        } else if (ch == '<') {
            _dest.put('<');
        } else if (ch == '>') {
            _dest.put('>');
        } else if (ch == ',') {
            _dest.put(',');
        } else if (ch == '.') {
            _dest.put('.');
        } else if (ch == '?') {
            _dest.put('?');
        } else if (ch == '!') {
            _dest.put('!');
        } else if (ch == ' ') {
            _dest.put(' ');
        } else {
            _dest.put(ch);
        }
    }
}
