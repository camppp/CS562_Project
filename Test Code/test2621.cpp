int calculateTotalLines(Document* document, Cursor* elem_cursor, int startBlockNum, int endBlockNum) {
    int totalLines = 0;
    for (int j = startBlockNum; j <= endBlockNum; j++) {
        totalLines += document->findBlock(j).lineCount();
    }
    return totalLines;
}
