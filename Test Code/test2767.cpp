WebBlobDataItem* PlatformBlob::nextDataItem() {
    if (!m_blobData || m_currentItem >= m_blobData->size()) {
        return nullptr;
    }

    WebBlobDataItem* item = m_blobData->at(m_currentItem);
    m_currentItem++;
    return item;
}
