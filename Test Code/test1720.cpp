python
def calculateAttributes(G):
    N, T, S, P = G
    attributes = {}
    
    def calculateSynthesizedAttributes(X):
        if X in attributes:
            return attributes[X]['synthesized']
        
        synthesized = set()
        for production in P[X]:
            # Calculate synthesized attributes based on production rules
            # Add logic here to compute synthesized attributes for non-terminal X
            # Update synthesized set
        
        attributes[X] = {'synthesized': synthesized, 'inherited': set()}
        return synthesized
    
    def calculateInheritedAttributes(X):
        if X in attributes:
            return attributes[X]['inherited']
        
        inherited = set()
        for production in P[X]:
            # Calculate inherited attributes based on production rules
            # Add logic here to compute inherited attributes for non-terminal X
            # Update inherited set
        
        attributes[X]['inherited'] = inherited
        return inherited
    
    A = set()
    for X in N:
        A = A.union(calculateSynthesizedAttributes(X)).union(calculateInheritedAttributes(X))
    
    return A
