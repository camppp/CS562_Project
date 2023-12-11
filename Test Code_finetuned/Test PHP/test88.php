class ProductManager {
    public $products;

    public function __construct() {
        $this->products = array(
            array("Name" => "Shirt", "Price" => 20),
            array("Name" => "Pants", "Price" => 30),
            array("Name" => "Shoes", "Price" => 50)
        );
    }
}

// Usage
$manager = new ProductManager();
print_r($manager->products);