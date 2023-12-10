bool PageTable::contains(Page* page)
{
    SpinLock::Synchronized method(spinLock);

    size_t index = page->hashCode() % pageCount;
    return hashTable[index].find(page) != hashTable[index].end();
}
