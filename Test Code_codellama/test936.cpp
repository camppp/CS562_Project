class TooltipBalance {
 public:
  TooltipBalance() {}
  ~TooltipBalance() {
    // Delete the UI associated with the tooltip balance
    delete ui;
  }

 private:
  // The UI associated with the tooltip balance
  UI* ui;
};
