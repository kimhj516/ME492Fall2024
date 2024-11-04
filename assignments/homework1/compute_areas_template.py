import csv
import numpy as np


_dimension = 2
_number_of_points_in_element = 3
_min_bound = 0
_max_bound = 255


# compute the triangle area for input coordinates of three vertices
def triangle_area(points):


# develop a class containing read-in point data 
class PointData:
    # initialize with input coordinates and triangle information
    # defined required instance variables
    def __init__(self, points, connectivity):

    # output number of points
    @property
    def number_of_points(self):

    # output number of triangles
    @property
    def number_of_elements(self):

    # output coordinates of the point data
    @property
    def points(self):

    # output triangle information of the point data
    @property
    def connectivity(self):

    # read the input text file to save the point data
    def read(self, filename):

    # compute area of the point data
    def area(self):

    # compute area by counting the pixels
    def compute_pixel_area(self):

    # compute area by summing the triangles
    def compute_triangle_area(self):

    # compute the center of the point data
    def center(self):


# test developed class methods and functions here
def main():
    try:

    except Exception as error:


if __name__ == "__main__":
    main()
