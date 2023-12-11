function unfavoriteItem($userId, $itemId) {
    // Check if the user is authenticated
    if (!Auth::check()) {
        return false;
    }

    // Get the user's favorites
    $favorites = Auth::user()->favorites;

    // Check if the item is already in the user's favorites
    if (!$favorites->contains($itemId)) {
        return false;
    }

    // Remove the item from the user's favorites
    $favorites->remove($itemId);

    // Save the changes to the user's favorites
    $favorites->save();

    // Return true if the unfavorite action was successful
    return true;
}