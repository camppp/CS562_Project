function processSubscription($subscription): void
{
    // Check if the subscription already has discounts
    if (!empty($subscription->discounts)) {
        // If the subscription already has discounts, do nothing
        return;
    }

    // If the subscription does not have any discounts, add a default discount
    $subscription->setDiscounts([new SubscriptionDiscount()]);
}

$subscription = new Subscription();
// Perform necessary operations to set up the subscription object
processSubscription($subscription);
// After processing, the $subscription object should have at least one discount associated with it