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

def star_doh():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s student retake is", each_student["retake"])

def kopgh8026():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s student GPA  is", each_student["GPA"])

def jhhan04():
    for each_student in data["student_data"]:
	print(each_student["name"], "'s major is ", each_student["major"])

def aimer1():
	for each_student in data["student_data"]:
		print(each_student["name"], "'s address is ", each_student["address"])

def leohyun777():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s github id is ", each_student["github_id"])

def kimjw43():
    for each_student in data["student_data"]:
        print(each_student["name"], "is majoring in", each_student["major"])

def jhpark31k():
    for each_student in data["student_data"]:
        print(each_student["name"], "will graduate in", each_student["grad_y"])

def aleph_null():
# My email id is 'aleph-null', but in python '-' cannot be used for function name.
# Therefore I used 'aleph_null' as function name
    for each_student in data["student_data"]:
        print(each_student["name"], "'s height is", each_student["height"])
def anna5031():
    for each_student in data["student_data"]:
        print(each_student["name"], "'s birthday is", each_student["Bday"])
