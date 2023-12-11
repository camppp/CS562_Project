class Shape {
  private $width;
  private $height;

  function __construct() {
    parent::__construct();
  }

  function calculateArea() {
    return $this->width * $this->height;
  }

  function calculatePerimeter() {
    return 2 * ($this->width + $this->height);
  }
}

$shape = new Shape();
$shape->width = 5;
$shape->height = 3;

echo $shape->calculateArea(); // Output: 15
echo $shape->