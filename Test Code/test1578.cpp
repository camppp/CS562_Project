class CncFun {
public:
    virtual ~CncFun() = default;
    virtual void execute() = 0;
};

class CncType {
public:
    virtual ~CncType() = default;
    virtual void execute() = 0;
};

class AppResult {
public:
    AppResult(const CncFun& cncFun, const CncType& cncType) :
        cncFun_(cncFun), cncType_(cncType) {}

    const CncFun& getConcreteFunction() const {
        return cncFun_;
    }

    const CncType& getConcreteType() const {
        return cncType_;
    }

    const std::vector<const CncType*>& getConcreteTypes() const {
        return cncTypes_;
    }

private:
    const CncFun& cncFun_;
    const CncType& cncType_;
    std::vector<const CncType*> cncTypes_;
};
