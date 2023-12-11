import boto3

def verify_item_count(table_name):
    # Connect to the DynamoDB table
    dynamodb = boto3.resource('dynamodb')
    table = dynamodb.Table(table_name)

    # Scan the table and count the items
    items = table.scan()['Items']
    item_count = len(items)

    # Verify the accuracy of the ItemCount value
    if item_count == table.item_count:
        return True
    else:
        return False