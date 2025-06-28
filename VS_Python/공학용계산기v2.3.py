import math
import ast
from fractions import Fraction
from collections import defaultdict

class Symbolic:
    def __init__(self, coefficient, base):
        self.coefficient = coefficient
        self.base = base

    def __str__(self):
        coeff = "" if self.coefficient == 1 else str(self.coefficient)
        return f"{coeff}{self.base}"

    def __repr__(self):
        return str(self)

    def __add__(self, other):
        if isinstance(other, Symbolic) and self.base == other.base:
            return Symbolic(self.coefficient + other.coefficient, self.base)
        else:
            return f"{self} + {other}"

    def __sub__(self, other):
        if isinstance(other, Symbolic) and self.base == other.base:
            return Symbolic(self.coefficient - other.coefficient, self.base)
        else:
            return f"{self} - {other}"

def needs_parentheses(expr):
    special_chars = ['+', '-', '×', '÷', '^', '/']
    return any(char in str(expr) for char in special_chars)

class Calculator(ast.NodeVisitor):
    evaluated_functions = {
        "sin": math.sin,
        "cos": math.cos,
        "tan": math.tan,
        "asin": math.asin,
        "acos": math.acos,
        "atan": math.atan,
    }

    symbolic_functions = {
        "sqrt": "√",
        "log": "log",
        "log10": "log₁₀",
        "exp": "e^",
    }

    constants = {
        "pi": "π",
        "e": "e",
    }

    def __init__(self):
        self.stack = []

    def visit_Constant(self, node):
        self.stack.append(Fraction(node.value))

    def visit_Name(self, node):
        if node.id in self.constants:
            self.stack.append(self.constants[node.id])
        else:
            raise NameError(f"알 수 없는 이름: {node.id}")

    def visit_BinOp(self, node):
        self.visit(node.left)
        self.visit(node.right)
        right = self.stack.pop()
        left = self.stack.pop()

        if isinstance(left, Fraction) and isinstance(right, Fraction):
            if isinstance(node.op, ast.Add):
                self.stack.append(left + right)
            elif isinstance(node.op, ast.Sub):
                self.stack.append(left - right)
            elif isinstance(node.op, ast.Mult):
                self.stack.append(left * right)
            elif isinstance(node.op, ast.Div):
                self.stack.append(left / right)
            elif isinstance(node.op, ast.Pow):
                self.stack.append(left ** right)
            elif isinstance(node.op, ast.Mod):
                self.stack.append(left % right)
            else:
                raise TypeError(f"지원하지 않는 연산자: {node.op}")
        elif isinstance(left, Symbolic) and isinstance(right, Symbolic):
            if isinstance(node.op, ast.Add):
                self.stack.append(left + right)
            elif isinstance(node.op, ast.Sub):
                self.stack.append(left - right)
            else:
                self.stack.append(f"({left}) {node.op.__class__.__name__} ({right})")
        else:
            if isinstance(node.op, ast.Add):
                self.stack.append(f"{left} + {right}")
            elif isinstance(node.op, ast.Sub):
                self.stack.append(f"{left} - {right}")
            elif isinstance(node.op, ast.Mult):
                self.stack.append(f"{left} × {right}")
            elif isinstance(node.op, ast.Div):
                left_expr = f"({left})" if needs_parentheses(left) else str(left)
                right_expr = f"({right})" if needs_parentheses(right) else str(right)
                self.stack.append(f"{left_expr}/{right_expr}")
            elif isinstance(node.op, ast.Pow):
                self.stack.append(f"{left}^{right}")
            elif isinstance(node.op, ast.Mod):
                self.stack.append(f"{left} mod {right}")
            else:
                raise TypeError(f"지원하지 않는 연산자: {node.op}")

    def visit_UnaryOp(self, node):
        self.visit(node.operand)
        operand = self.stack.pop()
        if isinstance(node.op, ast.UAdd):
            self.stack.append(operand)
        elif isinstance(node.op, ast.USub):
            if isinstance(operand, Fraction):
                self.stack.append(-operand)
            elif isinstance(operand, Symbolic):
                self.stack.append(Symbolic(-operand.coefficient, operand.base))
            else:
                self.stack.append(f"-({operand})")
        else:
            raise TypeError(f"지원하지 않는 단항 연산자: {node.op}")

    def visit_Call(self, node):
        args = []
        for arg in node.args:
            self.visit(arg)
            args.append(self.stack.pop())
        args.reverse()

        func_name = node.func.id

        if func_name in self.evaluated_functions:
            func = self.evaluated_functions[func_name]
            if any(isinstance(arg, str) for arg in args):
                self.stack.append(f"{func_name}({', '.join(map(str, args))})")
            else:
                self.stack.append(Fraction(func(*args)))
        elif func_name in self.symbolic_functions:
            symbol = self.symbolic_functions[func_name]
            arg = args[0]
            if isinstance(arg, Fraction) and arg.denominator == 1:
                base_expr = f"{symbol}{arg.numerator}"
            else:
                base_expr = f"{symbol}({arg})"
            self.stack.append(Symbolic(Fraction(1), base_expr))
        else:
            raise NameError(f"알 수 없는 함수: {func_name}")

    def calculate(self, expression):
        self.stack = []
        node = ast.parse(expression, mode="eval")
        self.visit(node.body)
        return self.stack.pop()

def main():
    print("공학용 계산기 (통분 + 약분 + 심볼묶기 완전판)")
    calculator = Calculator()

    while True:
        try:
            expression = input("수식을 입력하세요 (종료하려면 'exit' 입력): ")
            if expression.lower() == "exit":
                print("계산기를 종료합니다.")
                break
            result = calculator.calculate(expression)
            print("결과:", result)
        except (NameError, TypeError, SyntaxError, AttributeError, ValueError):
            print("잘못된 수식입니다.")
        except ZeroDivisionError:
            print("0으로 나눌 수 없습니다.")

if __name__ == "__main__":
    main()
