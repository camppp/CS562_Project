void ImageLayeri3d::RequestTile(const std::string& quadcode,
                                std::function<void(const std::string&, ImageTile*)> cbfReady,
                                std::function<void(const std::string&)> cbfFailed)
{
    // Retrieve the tile from the tile retrieval mechanism
    ImageTile* tile = RetrieveTile(quadcode);

    // Check if the tile was retrieved successfully
    if (tile != nullptr)
    {
        // Invoke the callback function for a successful tile retrieval
        cbfReady(quadcode, tile);
    }
    else
    {
        // Invoke the callback function for a failed tile retrieval
        cbfFailed(quadcode);
    }
}
