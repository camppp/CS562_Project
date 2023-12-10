void CSchrodinger1DItem::Assign(CSchrodinger1D* pS, int& i)
{
    iequ = i;
    x = &(pS->x[iequ]);
}
