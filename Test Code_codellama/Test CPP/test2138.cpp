class EnvOption {
public:
    EnvOption(const std::string& name, const std::string& description, const std::string& default_value)
        : name_(name), description_(description), default_value_(default_value) {}

    virtual ~EnvOption() {}

    virtual void set_value(const std::string& value) = 0;
    virtual std::string get_value() const = 0;

    const std::string& name() const { return name_; }
    const std::string& description() const { return description_; }
    const std::string& default_value() const { return default_value_; }

private:
    std::string name_;
    std::string description_;
    std::string default_value_;
};

class BoolOption : public EnvOption {
public:
    BoolOption(const std::string& name, const std::string& description, bool default_value)
        : EnvOption(name, description, default_value ? "true" : "false") {}

    void set_value(const std::string& value) override {
        bool new_value = value == "true";
        if (new_value != value_) {
            value_ = new_value;
            on_change();
        }
    }

    std::string get_value() const override {
        return value_ ? "true" : "false";
    }

private:
    bool value_;
};

class IntOption : public EnvOption {
public:
    IntOption(const std::string& name, const std::string& description, int default_value)
        : EnvOption(name, description, std::to_string(default_value)) {}

    void set_value(const std::string& value) override {
        int new_value = std::stoi(value);
        if (new_value != value_) {
            value_ = new_value;
            on_change();
        }
    }

    std::string get_value() const override {
        return std::to_string(value_);
    }

private:
    int value_;
};

class StringOption : public EnvOption {
public:
    StringOption(const std::string& name, const std::string& description, const std::string& default_value)
        : EnvOption(name, description, default_value) {}

    void set_value(const std::string& value) override {
        if (value != value_) {
            value_ = value;
            on_change();
        }
    }

    std::string get_value() const override {
        return value_;
    }

private:
    std::string value_;
};

class EnvOptions {
public:
    EnvOptions() {}

    void add_option(const std::string& name, const std::string& description, const std::string& default_value) {
        options_.emplace_back(std::make_unique<EnvOption>(name, description, default_value));
    }

    void add_bool_option(const std::string& name, const std::string& description, bool default_value) {
        options_.emplace_back(std::make_unique<BoolOption>(name, description, default_value));
    }

    void add_int_option(const std::string& name, const std::string& description, int default_value) {
        options_.emplace_back(std::make_unique<IntOption>(name, description, default_value));
    }

    void add_string_option(const std::string& name, const std::string& description, const std::string& default_value) {
        options_.emplace_back(std::make_unique<StringOption>(name, description, default_value));
    }

    EnvOption* get_option(const std::string& name) {
        for (auto& option : options_) {
            if (option->name() == name) {
                return option.get();
            }
        }
        return nullptr;
    }

    void set_default_value(const std::string& name, const std::string& value) {
        EnvOption* option = get_option(name);
        if (option) {
            option->set_value(value);
        }
    }

private:
    std::vector<std::unique_ptr<EnvOption>> options_;
};

void set_default_trace_exceptions(bool value) {
    EnvOptions::get_instance().set_default_value("trace_exceptions", value ? "true" : "false");
}
