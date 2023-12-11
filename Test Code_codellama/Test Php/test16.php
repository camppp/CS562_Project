class URLManager {
  private $dates = [];
  private $formConfig = [];
  private $listConfig = [];

  public function __construct($dates = [], $formConfig = [], $listConfig = []) {
    $this->dates = $dates;
    $this->formConfig = $formConfig;
    $this->listConfig = $listConfig;
  }

  public function url() {
    return $this->path . $this->name;
  }

  public function getDates() {
    return $this->dates;
  }

  public function getFormConfig() {
    return $this->formConfig;
  }

  public function getListConfig() {
    return $this->listConfig;
  }
}

$urlManager = new URLManager(['deleted_at'], [], []);

echo $urlManager->url(); //