#include "Algorithm.h"

float Algorithm::getAngle(sf::Vector2f point1, sf::Vector2f point2) {
    if (point1.y < point2.y) {
        float norme1 = sqrt(pow(point1.x, 2) + pow(point1.y, 2));
        float norme2 = sqrt(pow(point2.x, 2) + pow(point2.y, 2));
        float angle = Conversion::to_degres(acos((point1.x*point2.x + point1.y*point2.y) / (norme1*norme2)));
        if (angle > 5) {
            return angle - 5;
        }
    }
    return 0.0;
}
