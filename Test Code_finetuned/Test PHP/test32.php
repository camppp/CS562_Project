class UrlManager {
    public $dates = ['deleted_at'];
    public $formConfig = [];
    public $listConfig = [];
    public $path;
    public $name;

    public function __construct($path, $name) {
        $this->path = $path;
        $this->name = $name;
    }

    public function url() {
        return $this->path. $this->name;
    }
}

// Usage
$urlManager = new UrlManager('/api/', 'users');
echo $urlManager->url(); // Outputs: /api/users