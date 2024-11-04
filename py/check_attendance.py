import json


with open('student_data.json', 'r') as file:
    data = json.load(file)

for each_student in data["student_data"]:
    print('student name: ' + each_student["name"] + ', email address: ' + each_student["email"] + ', github id: ' + each_student["github_id"])
