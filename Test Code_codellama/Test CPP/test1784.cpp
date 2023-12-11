#include <iostream>
#include <vector>

class WhileStmt {
 public:
  WhileStmt(std::vector<Stmt*> inits, Expr* cond, Stmt* stmt)
      : inits_(inits), cond_(cond), stmt_(stmt) {}

  void dump() {
    std::cout << "WhileStmt: " << this << std::endl;
    std::cout << "Location: " << location() << std::endl;
    for (auto init : inits_) {
      init->dump();
    }
    if (cond_) {
      cond_->dump();
    }
    if (stmt_) {
      stmt_->dump();
    }
  }

 private:
  std::vector<Stmt*> inits_;
  Expr* cond_;
  Stmt* stmt_;
};
