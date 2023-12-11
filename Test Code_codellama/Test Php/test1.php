use App\Mail\OrderShipped;
use Illuminate\Support\Facades\Mail;

public function ship($orderId)
{
    $order = Order::find($orderId);

    // Ship the order
    $order->ship();

    // Send an email notification to the customer
    Mail::to($order->customer_email)
        ->send(new OrderShipped($order));
}