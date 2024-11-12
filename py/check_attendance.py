import json


with open('student_data.json', 'r') as file:
    data = json.load(file)

for each_student in data["student_data"]:
    print('student name: ' + each_student["name"] + ', email address: ' + each_student["email"] + ', github id: ' + each_student["github_id"] + ', student status: ' + each_student["student_status"])

def jsh99():
    # A function which prints student ID for every student.
    # Since there are no student ID info in json file yet, so this function won't work properly.
    for each_student in data["student_data"]:
        print(each_student["name"], "'s student ID is ", each_student["student_id"])

def gmmyung():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s me492 grade is ", each_student["grade"], sep="")

def rapael6696():
    # A function which prints students major for every student.
    for each_student in data["student_data"]:
        print(each_student["name"], "'s major is ", each_student["major"])

def tory453():
	#A function wich print student status for every student.
	for each_student in data["student_data"]:
		print(each_student["name"], "'s status is ", each_student["student_status"])

def joonseo():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s student address is ", each_student["address"])

