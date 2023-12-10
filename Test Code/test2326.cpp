class GameSettingsManager {
    private map<string, number> defaultValues;
    private map<string, number> maxValues;

    public GameSettingsManager() {
        defaultValues = new map<string, number>();
        maxValues = new map<string, number>();
    }

    public bool SetDefNum(string key, number value, bool enforceConstraint) {
        if (enforceConstraint) {
            // Enforce constraints on the parameter
            if (value < 0) {
                return false;
            }
        }
        defaultValues[key] = value;
        return true;
    }

    public bool SetMaxAmount(number value) {
        if (value < 0) {
            return false;
        }
        maxValues["max_amount"] = value;
        return true;
    }
}
