from matrix import Matrix
from node import Node
from elements import VoltageSource
from elements import Resistor


class Circuit:
    def __init__(self, nodes, elements, relations): # pre-implemented
        self.nodes = nodes
        self.elements = elements
        self.relations = relations
        self.construct_circuit()

    def construct_circuit(self): # pre-implemented
        for relation in self.relations:  # relation: [[element_index, head_node_index, tail_node_index],...]
            self.elements[relation[0]].head_node = self.nodes[relation[1]]
            self.elements[relation[0]].tail_node = self.nodes[relation[2]]
            self.nodes[relation[1]].adjacent.append(self.elements[relation[0]])
            self.nodes[relation[2]].adjacent.append(self.elements[relation[0]])

    def solve_node_voltage(self): # do not change the name of this method
        # you should construct system of equation based on Kirchhoff's Current Law and solve it using Matrix class.
        # you should return the node voltage list (1 dimensional float list) in the order of node indices.
        # pass # erase this line and implement
        node_count , n = len(self.nodes), len(self.nodes) + len(self.elements)
        mtx_a, mtx_b = Matrix(n, n), Matrix(n, 1)
        mtx_a.value[0][0] , idx = 1, 1
        for element in self.elements:
            if isinstance(element, VoltageSource): mtx_a[idx][element.head_node.index], mtx_a[idx][element.tail_node.index], mtx_b[idx][0] , idx = -1, 1, element.voltage, idx + 1
            else:
                mtx_a[idx][element.head_node.index], mtx_a[idx][element.tail_node.index], mtx_a[idx][node_count + element.index], idx = 1, -1, -element.resistance, idx + 1
                equation = [0] * n
                equation[node_count + element.index] = 1
                for other_element in element.head_node.adjacent:
                    if other_element is element: continue
                    if element.head_node is other_element.tail_node: equation[node_count + other_element.index] = -1
                    else: equation[node_count + other_element.index] = 1
                if equation in mtx_a or list(map(lambda x: (-1)*x, equation)) in mtx_a: continue
                mtx_a.value[idx], idx = equation, idx + 1
        mtx_x , res = mtx_a.solve(mtx_b), []
        for i in range(len(self.nodes)):
            self.nodes[i].voltage = mtx_x[i][0]
            res.append(mtx_x[i][0])
        return res




def main():
    # example case of Appendix C in homework 2 instruction
    ccc = Circuit([Node(0), Node(1), Node(2), Node(3)],[VoltageSource(0, 1), Resistor(1, 1), Resistor(2, 2), Resistor(3, 3), Resistor(4, 4)],[[0, 0, 1], [1, 1, 2], [2, 2, 3], [3, 3, 0], [4, 3, 0]]).solve_node_voltage()
    for  i in range(len(ccc)):
        print(i , ":", ccc[i], "V")

if __name__ == "__main__":
    main()
