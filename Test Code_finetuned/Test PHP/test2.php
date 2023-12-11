public function update(Request $request, $id)
{
    // Validate the request data
    $validatedData = $request->validate([
        'title' =>'required|string|max:255',
        'content' =>'required|string',
        // Add more validation rules as needed
    ]);

    // Find the related news article by its ID
    $relatedNews = RelatedNews::findOrFail($id);

    // Update the related news article with the new data
    $relatedNews->title = $validatedData['title'];
    $relatedNews->content = $validatedData['content'];
    // Update other fields as needed

    // Save the changes
    $relatedNews->save();

    // Redirect to a relevant page or route
    return redirect()->route('related-news.index')->with('success', 'Related news article updated successfully');
}