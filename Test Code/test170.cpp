#include <wx/wx.h>
#include <wx/datetime.h>

class DateSelectionWidget : public wxPanel
{
public:
    DateSelectionWidget(wxWindow* parent, wxWindowID id, const wxDateTime& date = wxDateTime::Today())
        : wxPanel(parent, id), m_date(date)
    {
        // Create the year spin control
        m_yearSpinCtrl = CreateYearSpinCtrl(this, wxID_ANY, m_date.GetYear());
        m_yearSpinCtrl->Bind(wxEVT_SPINCTRL, &DateSelectionWidget::OnYearSpinCtrl, this);

        // Create the month combo box
        m_monthComboBox = CreateMonthComboBox(this, wxID_ANY, m_date.GetMonth());
        m_monthComboBox->Bind(wxEVT_COMBOBOX, &DateSelectionWidget::OnMonthComboBox, this);

        // Set the sequential month selection flag
        if (!(GetWindowStyle() & wxCAL_SEQUENTIAL_MONTH_SELECTION))
        {
            m_monthComboBox->SetSelection(m_date.GetMonth());
        }
    }

    void OnYearSpinCtrl(wxSpinEvent& event)
    {
        // Update the selected date based on the year spin control
        m_date.SetYear(m_yearSpinCtrl->GetValue());
        m_monthComboBox->SetSelection(m_date.GetMonth());
    }

    void OnMonthComboBox(wxCommandEvent& event)
    {
        // Update the selected date based on the month combo box
        m_date.SetMonth(m_monthComboBox->GetSelection());
        m_yearSpinCtrl->SetValue(m_date.GetYear());
    }

private:
    wxSpinCtrl* m_yearSpinCtrl;
    wxComboBox* m_monthComboBox;
    wxDateTime m_date;
};
