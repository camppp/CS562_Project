class SeasonController {
    public function deleteSeason($seasonId) {
        // Assuming $seasons is an array of Season objects
        $seasons = Season::all();

        // Find the season with the given id
        $seasonToDelete = null;
        foreach ($seasons as $season) {
            if ($season->getId() == $seasonId) {
                $seasonToDelete = $season;
                break;
            }
        }

        // If the season was not found, display an error message and redirect
        if ($seasonToDelete == null) {
            flash('danger', 'Season not found');
            return redirect('seasons');
        }

        // If the season was found, delete it
        Season::delete($seasonToDelete);

        // Redirect to the season index page
        return redirect('seasons');
    }
}