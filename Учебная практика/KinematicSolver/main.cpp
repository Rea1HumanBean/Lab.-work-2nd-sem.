#define M_PI 3.1415

#include <iostream>
#include <vector>
#include <cmath>

struct Arms {
    int len_1;
    int len_2;
};

class KinematicSolver {
    Arms lengths;
public:
    KinematicSolver(Arms _lenghts): lengths(_lenghts) { }

    std::vector<float> solve(float x, float y) {
        std::vector<float> angles;

        float vect = sqrt(pow(x, 2) + pow(y, 2));

        if (vect > lengths.len_1 + lengths.len_2)
                throw std::runtime_error("Coordinates of a point greater than the coverage of the arms");

        float ang_1 = std::acos(x / vect);
        float ang_2 = std::acos((pow(lengths.len_1, 2) - pow(lengths.len_2, 2) + pow(vect, 2)) / (2 * vect * lengths.len_1));
        angles.push_back(ang_1 - ang_2);
        angles.push_back(M_PI - std::acos((pow(lengths.len_1, 2) + pow(lengths.len_2, 2) - pow(vect, 2)) / (2 * lengths.len_1 * lengths.len_2)));

        return angles;
    }
};

int main() {
    Arms a = { 4, 4 };
    KinematicSolver shoulders(a);
    std::vector<float> angles;

    try {
        angles = shoulders.solve(5, 5);
        std::cout << angles[0] << ' ' << angles[1]<<std::endl;
    }
    catch (const std::exception& exc) {
        std::cerr << exc.what() << std::endl;
        return 1;
    }
    
}
