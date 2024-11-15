# print_name_time.py
from datetime import datetime

if __name__ == '__main__':
    name = "Myungwoo Jung"
    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"My name is {name}, and the current time is {current_time}")

