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
};

bool comparePoints(Position point1, Position point2) {
    if(point1.latitude == point2.latitude) {
        return (point1.longitude < point2.longitude);
    }

    return (point1.latitude > point2.latitude);
}

int main() {
    vector<Position> shape;

    for(int i = 1; i <= 4; i++) {
        Position newPoint;
        cout << "Please enter point " << i << " latitude, longitude and height (separated by spaces):\n";
        cin >> newPoint.latitude >> newPoint.longitude >> newPoint.height;

        if(newPoint.latitude > MAXLATITUDE || newPoint.latitude < -MAXLATITUDE) {
            cout << "Error: Latitude outside of accepted range [-90, 90]\n";
            return -1;
        }

        if(newPoint.longitude >= MAXLONGITUDE || newPoint.longitude < -MAXLONGITUDE) {
            cout << "Error: Longitude outside of accepted range [-180, 180)\n";
            return -1;
        }

        if(count(shape.begin(), shape.end(), newPoint)) {
            cout << "Error: Position already exists\n";
            return -1;
        }
        shape.push_back(newPoint);
    }
}