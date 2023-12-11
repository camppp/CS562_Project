class PropertyHistory {
    private $value;
    private $history = [];

    public function __construct($initialValue) {
        $this->value = $initialValue;
        $this->history[] = $initialValue;
    }

    public function updateValue($newValue) {
        $this->history[] = $this->value;
        $this->value = $newValue;
    }

    public function getHistory() {
        return $this->history;
    }

    public function getValue() {
        return $this->value;
    }
}