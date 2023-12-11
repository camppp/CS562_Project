class ProductManager {
    private $products = [];
    private $discountCode = null;
    private $discountPercentage = null;

    public function addProduct($name, $price) {
        $this->products[$name] = $price;
    }

    public function removeProduct($name) {
        if (array_key_exists($name, $this->products)) {
            unset($this->products[$name]);
        }
    }

    public function calculateTotalPrice() {
        $total = 0;
        foreach ($this->products as $price) {
            $total += $price;
        }
        if ($this->discountCode!== null && $this->discountPercentage!== null) {
            $total -= $total * ($this->discountPercentage / 100);
        }
        return $total;
    }

    public function applyDiscount($code, $percentage) {
        if ($code === $this->discountCode) {
            $this->discountPercentage = $percentage;
        }
    }
}