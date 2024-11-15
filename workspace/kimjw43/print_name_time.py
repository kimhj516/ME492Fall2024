from datetime import datetime

name = 'Jiwon Kim'
now = datetime.now()

print(f"Name: {name}")
print(f"Time: {now.strftime('%H:%M:%S')}")