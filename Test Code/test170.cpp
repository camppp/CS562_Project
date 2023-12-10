// Check if the flag wxCAL_SEQUENTIAL_MONTH_SELECTION is not set
if ( !HasFlag(wxCAL_SEQUENTIAL_MONTH_SELECTION) )
{
    // Ensure sequential month selection
    CreateSequentialMonthComboBox();
}
else
{
    CreateMonthComboBox();
}

// Event handling for year spin control
Bind(wxEVT_SPINCTRL, &MyDateSelectionWidget::OnYearChange, this);

// Event handling for month combo box
Bind(wxEVT_COMBOBOX, &MyDateSelectionWidget::OnMonthChange, this);

// Event handler for year change
void MyDateSelectionWidget::OnYearChange(wxSpinEvent& event)
{
    int year = m_yearSpinCtrl->GetValue();
    m_date.SetYear(year);
    UpdateDisplayedDate();
}

// Event handler for month change
void MyDateSelectionWidget::OnMonthChange(wxCommandEvent& event)
{
    wxString selectedMonth = m_monthComboBox->GetStringSelection();
    int month = GetMonthNumber(selectedMonth);
    m_date.SetMonth(month);
    UpdateDisplayedDate();
}

// Helper function to update the displayed date
void MyDateSelectionWidget::UpdateDisplayedDate()
{
    m_staticYear->SetLabel(m_date.Format(_T("%Y")));
    m_staticMonth->SetLabel(m_date.Format(_T("%B")));
}
