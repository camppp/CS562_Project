bufsize_t SectHdrsWrapper::getSize()
{
    if (this->m_PE == nullptr) return 0;

    size_t secCount = getFieldsCount();

    offset_t hdrOffset = m_PE->secHdrsOffset();
    offset_t fileSize = m_PE->getRawSize();
    offset_t endOffset = hdrOffset + (secCount * sizeof(IMAGE_SECTION_HEADER));

    if (endOffset > fileSize) {
        return static_cast<bufsize_t>(fileSize - hdrOffset);
    } else {
        return static_cast<bufsize_t>(secCount * sizeof(IMAGE_SECTION_HEADER));
    }
}
