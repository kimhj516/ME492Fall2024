import json


with open('student_data.json', 'r') as file:
    data = json.load(file)

for each_student in data["student_data"]:
    print('student name: ' + each_student["name"] + ', email address: ' + each_student["email"] + ', github id: ' + each_student["github_id"])

def jsh99():
    # A function which prints student ID for every student.
    # Since there are no student ID info in json file yet, so this function won't work properly.
    for each_student in data["student_data"]:
        print(each_student["name"], "'s student ID is ", each_student["student_id"])

def rapael6696():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s github ID is ", each_student["github_id"])
