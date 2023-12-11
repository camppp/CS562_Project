class CriterionArgs:
    def __init__(self, initial_residual):
        self.initial_residual = initial_residual

    def calculateResidualNormReduction(self, current_residual):
        if self.initial_residual == 0:
            return 0
        else:
            return current_residual / self.initial_residual