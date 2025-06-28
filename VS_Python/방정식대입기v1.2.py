import ast
import math
from fractions import Fraction

class Symbolic:
    def __init__(self, coefficient, base):
        self.coefficient = Fraction(coefficient)
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

class ExpressionEvaluator(ast.NodeVisitor):
    allowed_functions = {
        "sin": math.sin,
        "cos": math.cos,
        "tan": math.tan,
        "asin": math.asin,
        "acos": math.acos,
        "atan": math.atan,
        "sqrt": "√",
        "log": "log",
        "log10": "log₁₀",
        "exp": "e^",
        "pi": math.pi,
        "e": math.e,
    }

    operators = {
        ast.Add: lambda a, b: a + b,
        ast.Sub: lambda a, b: a - b,
        ast.Mult: lambda a, b: a * b,
        ast.Div: lambda a, b: a / b,
        ast.Pow: lambda a, b: a ** b,
        ast.Mod: lambda a, b: a % b,
    }

    def __init__(self, expr):
        expr = expr.replace('^', '**')
        self.tree = ast.parse(expr, mode="eval")

    def evaluate(self, x_value):
        self.x_value = Fraction(x_value)
        return self.visit(self.tree.body)

    def visit_BinOp(self, node):
        left = self.visit(node.left)
        right = self.visit(node.right)

        if isinstance(left, Fraction) and isinstance(right, Fraction):
            if isinstance(node.op, ast.Add):
                return left + right
            elif isinstance(node.op, ast.Sub):
                return left - right
            elif isinstance(node.op, ast.Mult):
                return left * right
            elif isinstance(node.op, ast.Div):
                return left / right
            elif isinstance(node.op, ast.Pow):
                return left ** right
            elif isinstance(node.op, ast.Mod):
                return left % right
            else:
                raise TypeError(f"지원하지 않는 연산자 {node.op}")
        elif isinstance(left, Symbolic) and isinstance(right, Symbolic):
            if isinstance(node.op, ast.Add):
                return left + right
            elif isinstance(node.op, ast.Sub):
                return left - right
            else:
                return f"({left}) {node.op.__class__.__name__} ({right})"
        else:
            if isinstance(node.op, ast.Add):
                return f"{left} + {right}"
            elif isinstance(node.op, ast.Sub):
                return f"{left} - {right}"
            elif isinstance(node.op, ast.Mult):
                return f"{left} × {right}"
            elif isinstance(node.op, ast.Div):
                left_expr = f"({left})" if needs_parentheses(left) else str(left)
                right_expr = f"({right})" if needs_parentheses(right) else str(right)
                return f"{left_expr}/{right_expr}"
            elif isinstance(node.op, ast.Pow):
                return f"{left}^{right}"
            elif isinstance(node.op, ast.Mod):
                return f"{left} mod {right}"
            else:
                raise TypeError(f"지원하지 않는 연산자 {node.op}")

    def visit_UnaryOp(self, node):
        operand = self.visit(node.operand)
        if isinstance(node.op, ast.UAdd):
            return operand
        elif isinstance(node.op, ast.USub):
            if isinstance(operand, Fraction):
                return -operand
            elif isinstance(operand, Symbolic):
                return Symbolic(-operand.coefficient, operand.base)
            else:
                return f"-({operand})"
        else:
            raise TypeError(f"지원하지 않는 단항 연산자 {node.op}")

    def visit_Call(self, node):
        func_name = node.func.id
        args = [self.visit(arg) for arg in node.args]

        if func_name in ["sqrt", "log", "log10", "exp"]:
            arg = args[0]
            if isinstance(arg, Fraction) and arg.denominator == 1:
                base_expr = f"{self.allowed_functions[func_name]}{arg.numerator}"
            else:
                base_expr = f"{self.allowed_functions[func_name]}({arg})"
            return Symbolic(Fraction(1), base_expr)
        elif func_name in ["sin", "cos", "tan", "asin", "acos", "atan"]:
            func = self.allowed_functions[func_name]
            if isinstance(args[0], Fraction):
                return Fraction(func(float(args[0])))
            else:
                return f"{func_name}({args[0]})"
        else:
            raise NameError(f"알 수 없는 함수 {func_name}")

    def visit_Name(self, node):
        if node.id == "x":
            return self.x_value
        elif node.id in self.allowed_functions:
            return self.allowed_functions[node.id]
        else:
            raise NameError(f"알 수 없는 변수 {node.id}")

    def visit_Constant(self, node):
        return Fraction(node.value)

def main():
    print("방정식 계산기 (분수 통분 + 약분 + 심볼묶기 지원)")
    expr = input("x에 대한 수식을 입력하세요: ")
    evaluator = ExpressionEvaluator(expr)

    while True:
        user_input = input("x 값을 입력하세요 (exit 입력 시 종료): ")
        if user_input.lower() == 'exit':
            print("계산기를 종료합니다.")
            break
        try:
            x_value = Fraction(user_input)
            result = evaluator.evaluate(x_value)
            print("결과:", result)
        except Exception as e:
            print(f"오류 발생: {e}")

if __name__ == "__main__":
    main()
