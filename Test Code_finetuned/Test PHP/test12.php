function unfavoriteItem($userId, $itemId) {
    // Find the user by ID
    $user = User::find($userId);

    // Check if the user exists
    if (!$user) {
        return false;
    }

    // Check if the user has favorited the item
    if (!$user->favorites->contains($itemId)) {
        return false;
    }

    // Unfavorite the item
    $user->unfavorite($itemId);

    // Check if the unfavorite action was successful
    if (!$user->favorites->contains($itemId)) {
        return true;
    } else {
        return false;
    }
}