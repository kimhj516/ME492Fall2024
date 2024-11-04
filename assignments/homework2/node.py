 # you don't have to modify this file.
class Node:
    def __init__(self, index=None, voltage=None):
        self.index = index
        self.voltage = voltage
        self.adjacent = []
        try:
            self.input_check()
        except Exception as e:
            print("An error occurred while initializing node:", e)

    def input_check(self):
        if self.index is None:
            raise Exception("Index cannot be None.")
        elif not isinstance(self.index, int):
            raise Exception("Index must be an integer.")
        elif self.index < 0:
            raise Exception("Index cannot be negative.")
        if self.voltage is not None and not isinstance(self.voltage, float) and not isinstance(self.voltage, int):
            raise Exception("Voltage must be a float or an integer if it's not None.")
        if self.index == 0:  # global_id == 0 means grounded
            if self.voltage is None:
                self.voltage = 0
            if self.voltage != 0:
                raise Exception("Ground voltage should be zero.")


def main():
    pass # erase this line and add your tests freely.


if __name__ == "__main__":
    main()
