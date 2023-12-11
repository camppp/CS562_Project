import boto3

def verify_item_count(table_name):
    dynamodb = boto3.resource('dynamodb')
    table = dynamodb.Table(table_name)

    # Scan the table
    response = table.scan()

    # Count the items manually
    manual_count = len(response['Items'])

    # Get the ItemCount value from the table
    table_info = table.table_status
    item_count = table_info['ItemCount']

    # Compare the manually counted items with the ItemCount value
    if manual_count == item_count:
        return True
    else:
        return False