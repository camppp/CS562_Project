BlackBerry::Platform::WebBlobDataItem* PlatformBlob::nextDataItem()
{
    if (!m_blobData || m_currentItem >= m_blobData->items().size())
        return 0;  // Return null pointer if blob data is invalid or current item index is out of range
    else
        return m_blobData->items()[m_currentItem++];  // Return the next data item and increment the current item index
}
