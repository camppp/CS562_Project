class Expr {
public:
    Expr() : value(nullptr) {}
    ~Expr() { delete value; }

    Expr* getValue() { return value.get(); }
    const Expr* getValue() const { return value.get(); }

    void setValue(std::unique_ptr<Expr>&& expr) { value = std::move(expr); }

private:
    std::unique_ptr<Expr> value;
};
