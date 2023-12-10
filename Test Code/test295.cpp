bool checkInScripts(scriptelem script[], int scriptcount, scriptelem elem) {
    for (int i = 0; i < scriptcount; i++) {
        if (strcmp(script[i].ch, elem.ch) == 0 && script[i].count == elem.count) {
            return true;
        }
    }
    return false;
}
