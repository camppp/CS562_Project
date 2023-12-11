function processSubscription($subscription) {
    if (empty($subscription->discounts)) {
        $subscription->setDiscounts([new SubscriptionDiscount()]);
    }
}