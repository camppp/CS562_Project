void center(float avail_width, float element_width, float padding = 0) {
    ImGui::SameLine((avail_width / 2) - (element_width / 2) + padding);
}
