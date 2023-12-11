public function display_search() {
    // Display search options
    return '<div class="search-options">
        <label for="search-input">Search:</label>
        <input type="text" id="search-input" name="search-input">
        <button type="submit">Search</button>
    </div>';
}

public function display_sidebar_search() {
    // Display sidebar search
    return '<div class="sidebar-search">
        <label for="sidebar-search-input">Search:</label>
        <input type="text" id="sidebar-search-input" name