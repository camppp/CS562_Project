public function ship($orderId)
{
    // Assuming $order is the order model instance
    $order = Order::find($orderId);

    // Check if the order exists
    if (!$order) {
        return response()->json(['error' => 'Order not found'], 404);
    }

    // Mark the order as shipped
    $order->shipped = true;
    $order->save();

    // Get the customer's email
    $customerEmail = $order->customer->email;

    // Send the email notification
    Mail::to($customerEmail)->send(new OrderShipped($order));

    return response()->json(['message' => 'Order shipped successfully']);
}