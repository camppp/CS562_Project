class DatabaseManager {
public:
    DatabaseManager(sal_Int32 nOpenMode) : m_nOpenMode(nOpenMode), m_bRowCountFinal(false) {}

    void addRow(const com::sun::star::uno::Reference<com::sun::star::sdbc::XRow>& row) {
        m_itemSet.push_back(row);
    }

    void addContentIdentifier(const com::sun::star::uno::Reference<com::sun::star::ucb::XContentIdentifier>& identifier) {
        m_identSet.push_back(identifier);
    }

    com::sun::star::uno::Reference<com::sun::star::sdbc::XRow> getRow(sal_Int32 index) {
        if (index < 0 || index >= m_itemSet.size()) {
            throw std::out_of_range("Index out of range");
        }
        return m_itemSet[index];
    }

    com::sun::star::uno::Reference<com::sun::star::ucb::XContentIdentifier> getContentIdentifier(sal_Int32 index) {
        if (index < 0 || index >= m_identSet.size()) {
            throw std::out_of_range("Index out of range");
        }
        return m_identSet[index];
    }

    sal_Int32 getRowCount() {
        return m_itemSet.size();
    }

    sal_Int32 getContentIdentifierCount() {
        return m_identSet.size();
    }

private:
    IdentSet m_identSet;
    ItemSet m_itemSet;
    sal_Int32 m_nOpenMode;
    sal_Bool m_bRowCountFinal;
};
