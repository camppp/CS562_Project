void Undo(int opCount_save)
{
    // Check if there are enough operations in the undo log
    if (undoLog.GetCount() < opCount_save)
    {
        // Not enough operations, do nothing
        return;
    }

    // Get the most recent operation
    vrEulerOp* op = undoLog.GetHead();

    // Revert the operation
    op->Revert();

    // Remove the operation from the undo log
    undoLog.Remove(op);
}

void Redo(int opCount_save)
{
    // Check if there are enough operations in the undo log
    if (undoLog.GetCount() < opCount_save)
    {
        // Not enough operations, do nothing
        return;
    }

    // Get the most recent operation
    vrEulerOp* op = undoLog.GetHead();

    // Reapply the operation
    op->Apply();

    // Add the operation to the undo log
    undoLog.Add(op);
}
