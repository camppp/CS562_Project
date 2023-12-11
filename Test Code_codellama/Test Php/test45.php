public function deleteSeason($seasonId)
{
    // Check if the season with the given identifier exists
    $season = Season::find($seasonId);
    if (!$season) {
        // If the season is not found, display a "Season not found" message and redirect the user to the season index page
        flash('Season not found')->error();
        return redirect()->route('seasons.index');
    }

    // If the season is found, delete it from the collection
    $season->delete();

    // Display a "Season deleted" message and redirect the user to the season index page
    flash('Season deleted')->success();
    return redirect()->route('seasons.index');
}