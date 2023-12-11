public function favoriteQuestion($questionId) {
    $question = Question::findOrFail($questionId);

    if (auth()->check()) {
        $question->favorites()->attach(auth()->id());

        if (request()->expectsJson()) {
            return response()->json([
               'message' => 'The question has been favorited',
                'favorited' => true
            ]);
        } else {
            return back()->with('success', 'The question has been favorited');
        }
    } else {
        return redirect()->route('login')->with('error', 'Please log in to favorite the question');
    }
}