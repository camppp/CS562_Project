public function update(Request $request, $id)
{
    $category = Category::find($id);

    if ($category) {
        $category->name = $request->input('name');
        $category->description = $request->input('description');
        $category->save();

        return response()->json(['message' => 'Category updated successfully']);
    } else {
        return response()->json(['message' => 'Category not found'], 404);
    }
}