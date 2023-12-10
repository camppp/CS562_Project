void parse(const std::string& src, const std::function<void(const JsonNode&)>& f, const std::function<void(const std::string&)>& e) {
    // Initialize the parser state
    JsonParserState state;
    state.src = src;
    state.pos = 0;
    state.line = 1;
    state.col = 1;

    // Parse the input JSON string
    while (state.pos < state.src.size()) {
        // Skip whitespace characters
        while (state.pos < state.src.size() && isspace(state.src[state.pos])) {
            state.pos++;
        }

        // Check for the start of a JSON value
        if (state.pos < state.src.size() && state.src[state.pos] == '{') {
            // Parse a JSON object
            JsonObjectNode* object = parseObject(state);
            if (object != nullptr) {
                f(object);
            } else {
                e("Invalid JSON object");
                return;
            }
        } else if (state.pos < state.src.size() && state.src[state.pos] == '[') {
            // Parse a JSON array
            JsonArrayNode* array = parseArray(state);
            if (array != nullptr) {
                f(array);
            } else {
                e("Invalid JSON array");
                return;
            }
        } else {
            // Report an error
            e("Invalid JSON value");
            return;
        }
    }
}
