// CCarBilboard_2View

IMPLEMENT_DYNCREATE(CCarBilboard_2View, CView)

BEGIN_MESSAGE_MAP(CCarBilboard_2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CCarBilboard_2View::OnFilePrint)
END_MESSAGE_MAP()

void CCarBilboard_2View::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class
	CRect rect;
	GetClientRect(&rect);

	// Draw the car billboard content
	pDC->DrawText(_T("Your Car Billboard Content Here"), rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void CCarBilboard_2View::OnFilePrint()
{
	// TODO: Add your specialized code here to handle printing
	CPrintDialog printDlg(FALSE);
	if (printDlg.DoModal() == IDOK)
	{
		CDC dc;
		if (printDlg.GetPrinterDC(dc))
		{
			DOCINFO di;
			::ZeroMemory(&di, sizeof(DOCINFO));
			di.cbSize = sizeof(DOCINFO);
			di.lpszDocName = _T("Car Billboard Print");
			dc.StartDoc(&di);
			dc.StartPage();
			OnDraw(&dc); // Call the OnDraw method to draw the content on the printer DC
			dc.EndPage();
			dc.EndDoc();
		}
	}
}
