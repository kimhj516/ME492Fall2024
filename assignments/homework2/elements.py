 # you don't have to modify this file.
class Element:
    def __init__(self, index, head_node=None, tail_node=None, current=None):
        self.index = index
        self.head_node = head_node
        self.tail_node = tail_node
        self.current = current

 # the natural current flow is from head to tail
 # for example, - side of VoltageSource is connected to head_node and + side is connected to tail_node
 # if the actual current is the opposite direction, we just denote it as negative current

class VoltageSource(Element):
    def __init__(self, index, voltage, head_node=None, tail_node=None, current=None):
        # Initializes a voltage source with a specified voltage and index
        super().__init__(index, head_node, tail_node, current)
        self.voltage = voltage

class Resistor(Element):
    def __init__(self, index, resistance, head_node=None, tail_node=None, current=None):
        # Initializes a resistor with a specified resistance and index
        super().__init__(index, head_node, tail_node, current)
        self.resistance = resistance


def main():
    pass # if you want to add some test, erase this line and add freely.


if __name__ == "__main__":
    main()
