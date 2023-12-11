class CustomException extends Exception {
    protected $severity;

    public function setSeverity($severity) {
        $this->severity = $severity;
    }

    public function getSeverity() {
        return $this->severity;
    }

    public function __construct($message = "", $code = 0, Throwable $previous = null) {
        parent::__construct($message, $code, $previous);
        $this->setSeverity($code);
    }
}