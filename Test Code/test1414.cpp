bufsize_t SectHdrsWrapper::getSize() {
    // Calculate the total size of the section headers
    bufsize_t totalSize = getFieldsCount() * sizeof(IMAGE_SECTION_HEADER);

    // Calculate the end offset of the section headers
    offset_t endOffset = secHdrsOffset() + totalSize;

    // Check if the end offset exceeds the total size of the PE file
    if (endOffset > m_PE->getRawSize()) {
        // Return the remaining size of the file from the header offset
        return m_PE->getRawSize() - secHdrsOffset();
    }

    // Return the total size of the section headers
    return totalSize;
}
