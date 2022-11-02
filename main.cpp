#include <iostream>
#include <vector>
#include <algorithm>
#define MAXLATITUDE 90
#define MAXLONGITUDE 180

using namespace std;

class Position {
    public:
        double longitude, latitude, height;
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
};

ostream& operator<<(ostream& outStream, const Position& posToOutput) {
    outStream << '(' << posToOutput.latitude << ", " << posToOutput.longitude << ", " << posToOutput.height << ')';
    return outStream; 
}

class Calculator {
    public:
        static double calculateDistance(Position p1, Position p2);
    private:
        static double degreesToMeters(double degrees);
};

class Quadrilateral {
    public:
        Quadrilateral(vector<Position> shape);
        void printSortedPositions();
        bool validateShape();

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
        cout << point << '\n';
    }
}

bool Quadrilateral::validateShape() {
    for(Position point : this->points) {
        if(point.latitude > MAXLATITUDE || point.latitude < -MAXLATITUDE) {
            cout << "Error: Latitude outside of accepted range [-90, 90]\n";
            return false;
        }

        if(point.longitude >= MAXLONGITUDE || point.longitude < -MAXLONGITUDE) {
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

Quadrilateral parseInput() {
    vector<Position> shape;
    for(int i = 1; i <= 4; i++) {
        Position newPoint;
        cout << "Please enter point " << i << " latitude, longitude (in degrees) and height (in meters), separated by spaces:\n";
        cin >> newPoint.latitude >> newPoint.longitude >> newPoint.height;
        shape.push_back(newPoint);
    }

    return Quadrilateral(shape);
}

int main() {
    Quadrilateral shape = parseInput();
    if(!shape.validateShape()) {
        return -1;
    }

    shape.printSortedPositions();
    return 0;
}