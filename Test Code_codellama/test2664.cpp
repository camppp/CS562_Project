void EBCoarToCoarRedist::define(const EBLevelGrid& a_eblgFine, const EBLevelGrid& a_eblgCoar, int a_nref)
{
    // Check that the refinement ratio is valid
    if (a_nref <= 0)
    {
        MayDay::Error("Invalid refinement ratio in EBCoarToCoarRedist::define");
    }

    // Get the number of fine and coarse grids
    int nfine = a_eblgFine.getDBL().getDomain().getSize();
    int ncoarse = a_eblgCoar.getDBL().getDomain().getSize();

    // Check that the refinement ratio is valid for the given grids
    if (nfine % ncoarse != 0)
    {
        MayDay::Error("Invalid refinement ratio in EBCoarToCoarRedist::define");
    }

    // Get the refinement ratio
    int refRatio = nfine / ncoarse;

    // Redistribute data from the fine grid to the coarser grid
    for (int i = 0; i < nfine; i++)
    {
        // Get the fine grid cell
        const EBCellFAB& fineCell = a_eblgFine.getEBCellFAB(i);

        // Get the coarse grid cell
        const EBCellFAB& coarseCell = a_eblgCoar.getEBCellFAB(i / refRatio);

        // Redistribute data from the fine grid cell to the coarse grid cell
        coarseCell.redistribute(fineCell, refRatio);
    }
}
