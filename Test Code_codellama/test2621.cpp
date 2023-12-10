int calculateTotalLines(Document* document, Cursor* elem_cursor, int startBlockNum, int endBlockNum) {
    int totalLines = 0;
    for (int i = startBlockNum; i <= endBlockNum; i++) {
        totalLines += document->getBlock(i)->getLineCount();
    }
    return totalLines;
}
