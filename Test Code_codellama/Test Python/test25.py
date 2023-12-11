def group_products_by_category(products):
    # Write your code here
    result = {}
    for product in products:
        if product[1] not in result:
            result[product[1]] = []
        result[product[1]].append(product[0])
    return result