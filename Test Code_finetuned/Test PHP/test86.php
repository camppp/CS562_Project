SELECT products.id, products.name, products.price, brands.brand_name, categories.category_name
FROM products
JOIN brands ON products.brand_id = brands.id
JOIN categories ON products.category_id = categories.id
ORDER BY products.id DESC;