public ASTNode optimizeAST(ASTNode llowp, int loffset) {
    ASTNode newp = null;
    if (llowp != null) {
        newp = new ASTNode(llowp.getType(), llowp.getValue() + loffset);
    } else {
        newp = llowp;
    }
    return newp;
}
