TOptional<DwarfNode> NextChild() override
{
    Dwarf_Error err;
    int rc;

    // Check if the current node has children
    if (dwarf_child(mCurrentDie, &mCurrentDie, &err) == DW_DLV_OK) {
        // Push the current node onto the stack of parents
        mParents.push_back(mCurrentDie);
        return TOptional<DwarfNode>(mCurrentDie);
    }

    // Traverse up the tree to find the next child node
    while (!mParents.empty()) {
        Dwarf_Off currentOff = dwarf_dieoffset(mCurrentDie);
        Dwarf_Off parentOff = dwarf_dieoffset(mParents.back());
        if (currentOff == parentOff) {
            mCurrentDie = mParents.back();
            mParents.pop_back();
            // Check if the current parent has more children
            if (dwarf_child(mCurrentDie, &mCurrentDie, &err) == DW_DLV_OK) {
                // Push the current node onto the stack of parents
                mParents.push_back(mCurrentDie);
                return TOptional<DwarfNode>(mCurrentDie);
            }
        } else {
            mParents.pop_back();
        }
    }

    // No more children to traverse
    return TOptional<DwarfNode>();
}
