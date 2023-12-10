#include <string>

class ClearItem {
private:
    std::string m_subAcctType;
    bool m_subAcctTypeHasBeenSet;
    std::string m_reconcileStatus;

public:
    // Set the sub-account type for the clearing item and mark the sub-account type as set
    void SetSubAcctType(const std::string& _subAcctType) {
        m_subAcctType = _subAcctType;
        m_subAcctTypeHasBeenSet = true;
    }

    // Return true if the sub-account type has been set, and false otherwise
    bool SubAcctTypeHasBeenSet() const {
        return m_subAcctTypeHasBeenSet;
    }

    // Return the reconcile status of the clearing item
    std::string GetReconcileStatus() const {
        return m_reconcileStatus;
    }
};
