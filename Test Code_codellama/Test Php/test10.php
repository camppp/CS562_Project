class PropertyHistory {
  private $oldValue;
  private $history = [];

  public function __construct($oldValue) {
    $this->oldValue = $oldValue;
  }

  public function updateValue($newValue) {
    $this->oldValue = $newValue;
    $this->history[] = $this->oldValue;
  }

  public function getHistory() {
    return $this->history;
  }

  public function getCreatedBy() {
    return $this->oldValue;
  }
}