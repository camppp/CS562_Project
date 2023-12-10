#include "stdafx.h"
#include "CarBilboard_2.h"
#include "CarBilboard_2Doc.h"
#include "CarBilboard_2View.h"

BEGIN_MESSAGE_MAP(CCarBilboard_2View, CView)
    ON_WM_PAINT()
    ON_COMMAND(ID_PRINT, &CCarBilboard_2View::OnPrint)
END_MESSAGE_MAP()

CCarBilboard_2View::CCarBilboard_2View()
    : CView()
{
}

CCarBilboard_2View::~CCarBilboard_2View()
{
}

void CCarBilboard_2View::OnPaint()
{
    CPaintDC dc(this); // device context for painting

    // TODO: Add your drawing code here
    // Use the dc to display the car billboard content
}

void CCarBilboard_2View::OnPrint()
{
    // TODO: Add your printing code here
    // Use the dc to print the car billboard content
}
