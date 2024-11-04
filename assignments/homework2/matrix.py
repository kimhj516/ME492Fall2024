import numpy as np

class Matrix:
    def __init__(self, row_size=None, col_size=None, value=None):
        # Initialize the matrix with the given row and column sizes, and the elements.
        self.row_size = row_size
        self.col_size = col_size
        self.value = value
        try: # Validate the dimensions and elements.
            self.input_check()
        except Exception as e:
            print("Error in class Matrix init:", e)

    def __getitem__(self, index): # pre-implemented
        return self.value[index]

    def __setitem__(self, index, value): # pre-implemented
        if isinstance(value, list):
            self.value[index] = value
        else:
            raise Exception("assigned value should be type of list.")

    def input_check(self): # pre-implemented
        if self.value is None:
            self.value_builder()
        else:
            self.value_checker()

    def value_builder(self): # pre-implemented
        if self.row_size is None or self.col_size is None:
            raise ValueError("row_size and col_size must be set if initial value is not inputted.")
        else:
            self.value = [[0 for _ in range(self.col_size)] for _ in range(self.row_size)]

    def value_checker(self): # pre-implemented
        if not isinstance(self.value, list):
            raise Exception("inputted value should be a type of 2 dimensional list.")
        else:
            if len(self.value) == 0 or not isinstance(self.value[0], list):
                raise Exception("inputted value should be a type of 2 dimensional list.")
            else:
                if len(self.value[0]) == 0:
                    raise ValueError("inputted value is empty.")
                row_len = self.value.__len__()
                col_len = self.value[0].__len__()
                for row in self.value:
                    if col_len != len(row):
                        raise Exception("inputted value's column sizes are not consistent")
                if self.row_size is None:
                    self.row_size = row_len
                else:
                    if row_len != self.row_size:
                        raise Exception("inputted row size doesn't match to inputted value.")
                if self.col_size is None:
                    self.col_size = col_len
                else:
                    if col_len != self.col_size:
                        raise Exception("inputted col size doesn't match to inputted value.")

 # you don't have to fully understand the above code; it is just for your convenient error handling.

    def matrix_add(self, matrix_1, matrix_2=None): # do not change the name of the method.
        # If matrix_2 is None: return the sum of the instance matrix (self) and matrix_1.
        # If matrix_2 is not None: return the sum of matrix_1 and matrix_2.
        # The return type should be an instance of the Matrix class.
        # pass # erase this line if you started implementing
        if matrix_2 is None:
            matrix_2 = self
            # matrix_1, matrix_2 = matrix_2, matrix_1
        if matrix_1.row_size != matrix_2.row_size or matrix_1.col_size != matrix_2.col_size:
            raise Exception("Matrix dimensions must match for addition.")
        result = Matrix(matrix_1.row_size, matrix_1.col_size)
        for i in range(matrix_1.row_size):
            for j in range(matrix_1.col_size):
                result[i][j] = matrix_1[i][j] + matrix_2[i][j]
        return result.round()

    def matrix_sub(self, matrix_1, matrix_2=None): # do not change the name of the method.
        # If matrix_2 is None: return the difference between the instance matrix (self) and matrix_1.
        # If matrix_2 is not None: return the difference between matrix_1 and matrix_2.
        # Note that matrix_1 is not always the first operand.
        # The return type should be an instance of the Matrix class.
        # pass # erase this line if you started implementing
        if matrix_2 is None:
            matrix_2 = self
            matrix_1, matrix_2 = matrix_2, matrix_1
        if matrix_1.row_size != matrix_2.row_size or matrix_1.col_size != matrix_2.col_size:
            raise Exception("Matrix dimensions must match for addition.")
        result = self.matrix_add(matrix_1, matrix_2.multiply(-1))
        return result.round()

    def matrix_mul(self, matrix_1, matrix_2=None): # do not change the name of the method.
        # If matrix_2 is None: return the product of the instance matrix (self) and matrix_1.
        # If matrix_2 is not None: return the product of matrix_1 and matrix_2.
        # Note that matrix_1 is not always the first operand.
        # The return type should be an instance of the Matrix class.
        # pass # erase this line if you started implementing
        if matrix_2 is None:
            matrix_2 = self
            matrix_1, matrix_2 = matrix_2, matrix_1
        if matrix_1.col_size != matrix_2.row_size:
            raise Exception(f"for matrix multiplication AB, A's column size(${matrix_1.col_size}) should match "
                            f"B's row size(${matrix_2.row_size})")
        result = Matrix(matrix_1.row_size, matrix_2.col_size)
        for i in range(matrix_1.row_size):
            for j in range(matrix_2.col_size):
                result[i][j] = sum(matrix_1[i][k] * matrix_2[k][j] for k in range(matrix_1.col_size))
        return result.round()
    
    def _minor(self, i, j):  # additional helper function which is not given in skeleton code
        minor_matrix = Matrix(self.row_size - 1, self.col_size - 1)
        minor_matrix.value = [row[:j] + row[j + 1:] for row in (self.value[:i] + self.value[i + 1:])]
        return minor_matrix

    def determinant(self): # do not change the name of the method.
        # Calculate and return the determinant of the instance matrix (self).
        # The return type should be a float.
        # pass # erase this line if you started implementing
        if self.row_size != self.col_size:
            raise Exception("Determinant is only defined for square matrices.")
        if self.col_size == 1:
            return self.value[0][0]
        elif self.row_size == 2:
            return self[0][0] * self[1][1] - self[0][1] * self[1][0]
        else:
            determinant = 0
            for i in range(self.col_size):
                determinant += ((-1) ** i) * self[0][i] * self._minor(0, i).determinant()
            return determinant

    def multiply(self, factor, matrix_1=None): # do not change the name of the method.
        # If matrix_1 is None: multiply each element of the instance matrix (self) by the factor.
        # If matrix_1 is provided: multiply each element of matrix_1 by the factor.
        # The factor should be a float, and the return type should be an instance of the Matrix class.
        # pass # erase this line if you started implementing
        if matrix_1 is None:
            matrix_1 = self
        result = Matrix(matrix_1.row_size, matrix_1.col_size)
        for i in range(self.row_size):
            for j in range(self.col_size):
                result[i][j] = matrix_1[i][j] * factor
        return result.round()

    def solve(self, matrix_b): # do not change the name of the method.
        # Let the instance matrix be A and matrix_b be B. Solve the equation AX = B.
        # Return the solution matrix X.
        # The return type should be an instance of the Matrix class.
        # you can use some external module, such as NumPy.
        # If you implement this method without using external module, you will get a bonus point.
        # pass # erase this line if you started implementing
        # Gaussian Elimination
        if self.row_size != self.col_size:
            raise Exception("Matrix A must be square for solving equation AX = B.")
        if matrix_b.row_size != self.row_size or matrix_b.col_size != 1:
            raise Exception("Matrix B must be n by 1 matrix where matrix A's size is n by n in the equation AX = B.")
        if self.determinant() == 0:
            raise Exception("Matrix A is singular (its determinant is 0): infinite or zero solution.")

        n = self.row_size
        aug = Matrix(self.row_size, self.col_size + 1)
        aug.value = [self[i] + matrix_b[i] for i in range(n)]

        for i in range(n):
            max_row = max(range(i, n), key=lambda r: abs(aug[r][i]))
            if i != max_row:
                aug[i], aug[max_row] = aug[max_row], aug[i]

            for j in range(i + 1, n):
                factor = aug[j][i] / aug[i][i]
                for k in range(i, n + 1):
                    aug[j][k] -= factor * aug[i][k]

        x = Matrix(n, 1)
        for i in range(n - 1, -1, -1):
            x[i][0] = aug[i][n] / aug[i][i]
            for j in range(i - 1, -1, -1):
                aug[j][n] -= aug[j][i] * x[i][0]
        return x.round()
    
    def solve_2(self, matrix_b):
        A = np.array(self.value)
        B = np.array(matrix_b.value)
        X = np.linalg.solve(A, B)
        x = Matrix(matrix_b.row_size, 1)
        for i in range(matrix_b.row_size):
            x.value[i][0] = X[i, 0]
        return x


    def round(self):  # additional helper function which is not given in skeleton code, grader will use actual value with allowable error.
        rounded_matrix = Matrix(self.row_size, self.col_size)
        for i in range(self.row_size):
            for j in range(self.col_size):
                rounded_matrix[i][j] = round(self[i][j], 5)
        return rounded_matrix
        


def main():
    a = [Matrix(value=[[2, 9, 7], [6, 10, 9], [3, 8, 1], [3, 4, 10], [9, 6, 2]]),Matrix(value=[[3, 9, 2, 5], [2, 1, 9, 2], [7, 8, 10, 3]]),Matrix(value=[[73, 83, 155, 49], [101, 136, 192, 77], [32, 43, 88, 34], [87, 111, 142, 53], [53, 103, 92, 63]])]
    print(a[0].matrix_mul(a[1]).value)
    print(a[2].value)


if __name__ == "__main__":
    main()