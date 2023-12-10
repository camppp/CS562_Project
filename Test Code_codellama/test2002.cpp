class CustomIterator {
public:
    CustomIterator(ItemList* pList) {
        m_pList = pList;
        m_pCurrent = nullptr;
    }

    Item* Next() {
        if (m_pCurrent == nullptr) {
            m_pCurrent = m_pList->Next();
        } else {
            m_pCurrent = m_pCurrent->Next();
        }

        return m_pCurrent;
    }

    bool HasNext() {
        return m_pCurrent != nullptr;
    }

private:
    ItemList* m_pList;
    Item* m_pCurrent;
};
