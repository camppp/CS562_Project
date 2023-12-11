class ProductManager {
  private $products = [];

  public function addProduct($name, $price) {
    $this->products[$name] = $price;
  }

  public function removeProduct($name) {
    unset($this->products[$name]);
  }

  public function calculateTotalPrice() {
    $total = 0;
    foreach ($this->products as $product) {
      $total += $product;
    }
    return $total;
  }

  public function applyDiscount($code, $percentage) {
    if ($code === 'DISCOUNT10') {
      $this->products = array_map(function($product) use ($percentage) {
        return $product * (1 - $percentage / 100);
      }, $this->products);
    }
  }
}