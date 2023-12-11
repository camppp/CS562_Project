void setupGUI(wxWindow* parent, wxWindow* leftWidget, wxWindow* rightWidget) {
    // Create a new horizontal box sizer
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    // Add the left and right widgets to the sizer with equal proportions and a 5-pixel border on all sides
    hbox->Add(leftWidget, 1, wxEXPAND | wxALL, 5);
    hbox->Add(rightWidget, 1, wxEXPAND | wxALL, 5);

    // Set the sizer for the parent window
    parent->SetSizer(hbox);

    // Center the window
    parent->Centre();
}
