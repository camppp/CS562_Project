void CMainLayout::Create(const CDlgMetrics& metrics, CRect& rect)
{
    // Calculate the position of the main dialog window
    rect.left = metrics.m_x;
    rect.top = metrics.m_y;
    rect.right = metrics.m_x + metrics.m_width;
    rect.bottom = metrics.m_y + metrics.m_height;

    // Calculate the position of the label 0
    m_rcLabel0.left = rect.left + metrics.m_label0_x;
    m_rcLabel0.top = rect.top + metrics.m_label0_y;
    m_rcLabel0.right = m_rcLabel0.left + metrics.m_label0_width;
    m_rcLabel0.bottom = m_rcLabel0.top + metrics.m_label0_height;

    // Calculate the position of the OK button
    m_rcOKButton.left = rect.right - metrics.m_ok_button_width;
    m_rcOKButton.top = rect.bottom - metrics.m_ok_button_height;
    m_rcOKButton.right = m_rcOKButton.left + metrics.m_ok_button_width;
    m_rcOKButton.bottom = m_rcOKButton.top + metrics.m_ok_button_height;

    // Calculate the position of the Cancel button
    m_rcCancelButton.left = rect.right - metrics.m_cancel_button_width;
    m_rcCancelButton.top = rect.bottom - metrics.m_cancel_button_height;
    m_rcCancelButton.right = m_rcCancelButton.left + metrics.m_cancel_button_width;
    m_rcCancelButton.bottom = m_rcCancelButton.top + metrics.m_cancel_button_height;

    // Calculate the position of the Apply button
    m_rcApplyButton.left = rect.right - metrics.m_apply_button_width;
    m_rcApplyButton.top = rect.bottom - metrics.m_apply_button_height;
    m_rcApplyButton.right = m_rcApplyButton.left + metrics.m_apply_button_width;
    m_rcApplyButton.bottom = m_rcApplyButton.top + metrics.m_apply_button_height;
}
