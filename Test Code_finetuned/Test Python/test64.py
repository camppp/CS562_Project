from abc import ABC, abstractmethod

class Expression(ABC):
    @abstractmethod
    def to_expr_string(self):
        pass

    def __str__(self):
        return self.opkind

class BinaryExpression(Expression):
    def __init__(self, opkind, left, right):
        self.opkind = opkind
        self.left = left
        self.right = right

    def to_expr_string(self):
        return "({} {} {})".format(self.left.to_expr_string(), self.opkind, self.right.to_expr_string())