#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const double MAXLATITUDE = 90;
const double MAXLONGITUDE = 180;

class Position {
    public:
        Position(double latitude, double longitude, double height) {
            this->latitude = latitude;
            this->longitude = longitude;
            this->height = height;
        }

        string toString() {
            return "(" + to_string(this->latitude) + ", " + to_string(this->longitude) + ", " + to_string(this->height) + ')';
        }
        double getLat() {return latitude;};
        double getLong() {return longitude;};
        double getHeight() {return height;};
        bool operator==(const Position &rhs) const {
            return (this->longitude == rhs.longitude && this->latitude == rhs.latitude && this->height == rhs.height);
        }

        // This function is used in sorting Positions in order of descending latitude, ascending longitude
        static bool comparePoints(Position point1, Position point2) {
            if(point1.latitude == point2.latitude) {
                return (point1.longitude < point2.longitude);
            }

            return (point1.latitude > point2.latitude);
        }

    private:
        double longitude, latitude, height;
};

class Calculator {
    public:
        static double calculateDistance(Position p1, Position p2);
    private:
        static double degreesToMeters(double degrees);
};

double Calculator::degreesToMeters(double degrees) {
    return degrees * M_PI / 180 * 6378137;
}

double Calculator::calculateDistance(Position p1, Position p2) {
    double latDiff = degreesToMeters(p1.getLat()) - degreesToMeters(p2.getLat());
    double longDiff = degreesToMeters(p1.getLong()) - degreesToMeters(p2.getLong());
    double heightDiff = p1.getHeight() - p2.getHeight();

    return sqrt(pow(latDiff, 2) + pow(longDiff, 2) + pow(heightDiff, 2));
}

class Quadrilateral {
    public:
        Quadrilateral(vector<Position> shape);
        void printSortedPositions();
        bool validateShape();
        void showAllDistances();
    private:
        vector<Position> points;
};

Quadrilateral::Quadrilateral(vector<Position> shape) {
    this->points = shape;
}

void Quadrilateral::printSortedPositions() {
    vector<Position> sortedShape = this->points;
    sort(sortedShape.begin(), sortedShape.end(), Position::comparePoints);

    cout << "The positions of the points you have entered, ordered by descending latitude, ascending longitude, are:\n";
    for(Position point : sortedShape) {
        cout << point.toString() << '\n';
    }
}

bool Quadrilateral::validateShape() {
    for(Position point : this->points) {
        if(point.getLat() > MAXLATITUDE || point.getLat() < -MAXLATITUDE) {
            cout << "Error: Latitude outside of accepted range [-90, 90]\n";
            return false;
        }

        if(point.getLong() >= MAXLONGITUDE || point.getLong() < -MAXLONGITUDE) {
            cout << "Error: Longitude outside of accepted range [-180, 180)\n";
            return false;
        }

        if(count(this->points.begin(), this->points.end(), point) > 1) {
            cout << "Error: Point with the same position already exists\n";
            return false;
        }
    }
    
    return true;
}

void Quadrilateral::showAllDistances() {
    for(auto i = this->points.begin(); i != this->points.end(); i++) {
        for(auto j = i + 1; j != this->points.end(); j++) {
            cout << "Distance between point " << i->toString() << " and point " << j->toString() << " is " << Calculator::calculateDistance(*i, *j) << '\n';
        }
    }
}

Quadrilateral parseInput() {
    vector<Position> shape;
    for(int i = 1; i <= 4; i++) {
        double latitude, longitude, height;
        cout << "Please enter point " << i << " latitude, longitude (in degrees) and height (in meters), separated by spaces:\n";
        cin >> latitude >> longitude >> height;
        shape.push_back(Position(latitude, longitude, height));
    }

    return Quadrilateral(shape);
}

int main() {
    Quadrilateral shape = parseInput();
    if(!shape.validateShape()) {
        return -1;
    }

    shape.printSortedPositions();

    shape.showAllDistances();
    return 0;
}