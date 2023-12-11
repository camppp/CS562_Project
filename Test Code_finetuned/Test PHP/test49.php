class ReturnOrder extends Model
{
    use HasFactory;

    protected $fillable = [
        'user_id',
        'payment_type',
        'payment_id',
        'paying_amount',
        'balance_transaction',
       'strip_order_id',
    ];

    public function calculateRefundAmount()
    {
        $refundAmount = 0;

        if ($this->payment_type == 'credit_card') {
            $refundAmount = $this->paying_amount * 0.9;
        } elseif ($this->payment_type == 'paypal') {
            $refundAmount = $this->paying_amount;
        } elseif ($this->payment_type =='stripe') {
            $refundAmount = $this->paying_amount * 0.95;
        }

        if ($this->balance_transaction > 0) {
            $refundAmount += $this->balance_transaction;
        }

        if (!empty($this->strip_order_id)) {
            $refundAmount += $this->paying_amount * 0.1;
        }

        return $refundAmount;
    }
}