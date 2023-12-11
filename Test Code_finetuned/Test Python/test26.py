def group_products_by_category(products):
    product_dict = {}
    for product in products:
        if product[1] in product_dict:
            product_dict[product[1]].append(product[0])
        else:
            product_dict[product[1]] = [product[0]]
    return product_dict