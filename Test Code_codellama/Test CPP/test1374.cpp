class ClearItem {
private:
    string subAcctType;
    bool subAcctTypeSet;
    ReconcileStatus reconcileStatus;

public:
    ClearItem() {}

    void SetSubAcctType(string subAcctType) {
        this->subAcctType = subAcctType;
        this->subAcctTypeSet = true;
    }

    bool SubAcctTypeHasBeenSet() {
        return this->subAcctTypeSet;
    }

    ReconcileStatus GetReconcileStatus() {
        return this->reconcileStatus;
    }
};
