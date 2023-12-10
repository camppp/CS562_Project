void UpdateControls() {
    // Calculate the histogram
    std::vector<int> histogram = CalculateHistogram(dataset);

    // Update the GUI controls
    for (int i = 0; i < histogram.size(); i++) {
        // Get the current bar
        GUI::Bar* bar = GUI::GetBar(i);

        // Set the bar's height
        bar->SetHeight(histogram[i]);
    }
}
