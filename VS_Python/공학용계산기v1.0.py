import math
import ast

class Calculator(ast.NodeVisitor):
    operators = {
        ast.Add: lambda a, b: a + b,
        ast.Sub: lambda a, b: a - b,
        ast.Mult: lambda a, b: a * b,
        ast.Div: lambda a, b: a / b,
        ast.Mod: lambda a, b: a % b,
        ast.Pow: lambda a, b: a ** b,
    }

    functions = {
        "sin": math.sin,
        "cos": math.cos,
        "tan": math.tan,
        "asin": math.asin,
        "acos": math.acos,
        "atan": math.atan,
        "exp": math.exp,
        "log": math.log,
        "log10": math.log10,
        "sqrt": math.sqrt,
    }

    constants = {
        "pi": math.pi,
        "e": math.e,
    }

    def __init__(self):
        self.stack = []

    def visit_Constant(self, node):
        self.stack.append(node.value)

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
        op = self.operators.get(type(node.op))
        if op is None:
            raise TypeError(f"지원하지 않는 연산자: {node.op}")
        self.stack.append(op(left, right))

    def visit_UnaryOp(self, node):
        self.visit(node.operand)
        operand = self.stack.pop()
        if isinstance(node.op, ast.UAdd):
            self.stack.append(+operand)
        elif isinstance(node.op, ast.USub):
            self.stack.append(-operand)
        else:
            raise TypeError(f"지원하지 않는 단항 연산자: {node.op}")

    def visit_Call(self, node):
        args = []
        for arg in node.args:
            self.visit(arg)
            args.append(self.stack.pop())
        args.reverse()
        func = self.functions.get(node.func.id)
        if func is None:
            raise NameError(f"알 수 없는 함수: {node.func.id}")
        self.stack.append(func(*args))

    def calculate(self, expression):
        self.stack = []
        node = ast.parse(expression, mode="eval")
        self.visit(node.body)
        return self.stack.pop()

def main():
    print("공학용 계산기")
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
