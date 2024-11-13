from datetime import datetime

def print_name_and_time():
    name = "Doh Hosung"
    current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    print(f"Name: {name}")
    print(f"Current Time: {current_time}")

if __name__ == "__main__":
    print_name_and_time()


