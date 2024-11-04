import csv
import numpy as np


_dimension = 2
_number_of_points_in_element = 3
_min_bound = 0
_max_bound = 255


def triangle_area(points):
    vector_1 = list()
    vector_2 = list()
    for i in range(_dimension):
        vector_1.append(points[1][i] - points[0][i])
        vector_2.append(points[2][i] - points[0][i])
    return np.linalg.norm(np.cross(np.array(vector_1), np.array(vector_2))) / 2.0


class PointData:
    def __init__(self, filename):
        points, connectivity = self.read(filename)
        self._points = points
        self._connectivity = connectivity
        self._number_of_points = int(len(self._points) / _dimension)
        self._number_of_elements = int(len(self._connectivity) / _number_of_points_in_element)
        self._min = list()
        self._max = list()
        for i in range(_dimension):
            self._min.append(int(_max_bound))
            self._max.append(int(_min_bound))
        for i in range(self._number_of_points):
            for j in range(_dimension):
                self._min[j] = min(self._min[j], self._points[_dimension * i + j])
                self._max[j] = max(self._max[j], self._points[_dimension * i + j])
        print(f'read {self._number_of_points} points and {self._number_of_elements} elements with the min {str(self._min)} and the max {str(self._max)}')

    @property
    def number_of_points(self):
        return self._number_of_points

    @property
    def number_of_elements(self):
        return self._number_of_elements

    @property
    def points(self):
        return self._points

    @property
    def connectivity(self):
        return self._connectivity

    def read(self, filename):
        points = list()
        connectivity = list()
        with open(filename, 'r') as read_points:
            for data in read_points.readlines():
                data = data.strip()
                if len(data.split(',')) == _dimension:
                    for entry in data.split(','):
                        points.append(int(entry))
                elif len(data.split(',')) == _number_of_points_in_element:
                   for entry in data.split(','):
                       connectivity.append(int(entry))
                else:
                    raise ValueError('Unsupported file format')
        return (points, connectivity)

    def area(self):
        if self._number_of_elements == 0:
            return self.compute_pixel_area()
        else:
            return self.compute_triangle_area()

    def compute_pixel_area(self):
        tolerance = float(0.01)
        area = float(0)
        if _dimension != 2:
            raise ValueError(f'This area computation routine is developed for {_dimension} dimension data only')
        for i in range(int(self._max[0] - self._min[0])):
            for j in range(int(self._max[1] - self._min[1])):
                min_i = self._min[0] + i
                max_i = self._min[0] + i + 1
                min_j = self._min[1] + j
                max_j = self._min[1] + j + 1
                number_of_internal_points = 0
                for n in range(self._number_of_points):
                    if abs(self._points[2*n] - min_i) < tolerance and abs(self._points[2*n+1] - min_j) < tolerance:
                        number_of_internal_points = number_of_internal_points + 1
                    if abs(self._points[2*n] - min_i) < tolerance and abs(self._points[2*n+1] - max_j) < tolerance:
                        number_of_internal_points = number_of_internal_points + 1
                    if abs(self._points[2*n] - max_i) < tolerance and abs(self._points[2*n+1] - min_j) < tolerance:
                        number_of_internal_points = number_of_internal_points + 1
                    if abs(self._points[2*n] - max_i) < tolerance and abs(self._points[2*n+1] - max_j) < tolerance:
                        number_of_internal_points = number_of_internal_points + 1
                if number_of_internal_points == 4:
                    area = area + 1.0
                elif number_of_internal_points == 3:
                    area = area + 0.5
        return area

    def compute_triangle_area(self):
        area = float(0)
        for i in range(self._number_of_elements):
            triangle = list()
            for j in range(_number_of_points_in_element):
                node_id = self._connectivity[_number_of_points_in_element*i+j]
                point = list()
                for k in range(_dimension):
                    point.append(self._points[_dimension * node_id + k])
                triangle.append(point)
            area = area + triangle_area(triangle)
        return area

    def debug(self, filename):
        with open(filename, 'w') as output_points:
            for i in range(self._number_of_points):
                point = list()
                for j in range(_dimension):
                    point.append(self._points[_dimension * i + j])
                output_points.write(str(point))
            for i in range(self._number_of_elements):
                element = list()
                for j in range(_dimension):
                    element.append(self._connectivity[_number_of_points_in_element * i + j])
                output_points.write(str(element))

    def center(self):
        center_point = [float(0), float(0)]
        for i in range(self._number_of_points):
            center_point[0] = center_point[0] + self._points[_dimension * i + 0]
            center_point[1] = center_point[1] + self._points[_dimension * i + 1]
        center_point[0] = center_point[0] / float(self._number_of_points)
        center_point[1] = center_point[1] / float(self._number_of_points)
        return center_point


def main():
    try:
        test_dirs = ['diamond', 'rectangle', 'simple_square', 'square', 'square_minus_diamond', 'square_minus_star', 'star', 'triangle']

        for test_dir in test_dirs:
            # For point data only
            input_file = test_dir + '/points_only.csv'
            point_data_only = PointData(input_file)
            print(f'{input_file} area and center based on point data: {point_data_only.area()} {point_data_only.center()}')

            # For point + triangle data
            input_file = test_dir + '/points_and_elements.csv'
            points_and_elements = PointData(input_file)
            print(f'{input_file} area and center based on points and triangles: {points_and_elements.area()} {points_and_elements.center()}')

    except Exception as error:
        print ('Detected this error: ' + repr(error))


if __name__ == "__main__":
    main()
