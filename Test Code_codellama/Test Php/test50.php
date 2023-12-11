public function update(Request $request, $id)
{
    $relatedNews = RelatedNews::find($id);

    if ($relatedNews) {
        $relatedNews->title = $request->title;
        $relatedNews->description = $request->description;
        $relatedNews->url = $request->url;
        $relatedNews->save();

        return redirect()->route('related-news.index')->with('success', 'Related news article updated successfully');
    } else {
        return redirect()->route('related-news.index')->with('error', 'Related news article not found');
    }
}