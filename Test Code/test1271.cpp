void setupGUI(wxWindow* parent, wxWindow* leftWidget, wxWindow* rightWidget) {
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    hbox->Add(leftWidget, 1, wxEXPAND | wxALL, 5);
    hbox->Add(rightWidget, 1, wxEXPAND | wxALL, 5);
    parent->SetSizer(hbox);
    parent->Centre();
}
