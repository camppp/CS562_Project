class DirectResponseManager {
  private $directResponse;
  private static $directResponseCount = 0;

  public function setDirectResponse($message) {
    $this->directResponse = $message;
    self::$directResponseCount++;
  }

  public function getDirectResponse() {
    return $this->directResponse;
  }

  public function getDirectResponseCount() {
    return self::$directResponseCount;
  }
}