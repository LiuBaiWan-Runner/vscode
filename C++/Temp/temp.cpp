#include <iostream>
#include <cmath>

// 定义一个结构体来表示坐标点
struct Point {
    double x;
    double y;
};

// 生成五角星的坐标点矩阵
void generateStarCoordinates(Point* points, int numPoints, double majorAxis, double angle) {
    if (numPoints < 5 || points == nullptr) {
        std::cerr << "Invalid input" << std::endl;
        return;
    }

    // 计算五角星的角度
    double angleIncrement = 2 * M_PI / numPoints;

    for (int i = 0; i < numPoints; i++) {
        double currentAngle = angle + i * angleIncrement;
        double radius = (i % 2 == 0) ? majorAxis : majorAxis / 2.0; // 长轴和短轴交替

        // 计算坐标点的x和y坐标
        points[i].x = radius * cos(currentAngle);
        points[i].y = radius * sin(currentAngle);
    }
}

int main() {
    const int numPoints = 10; // 五角星有10个顶点
    Point starPoints[numPoints];
    double majorAxis = 500.0; // 长轴长度
    double angle = M_PI / 6.0; // 与Y轴夹角30度（弧度表示）

    generateStarCoordinates(starPoints, numPoints, majorAxis, angle);

    // 输出坐标点
    for (int i = 0; i < numPoints; i++) {
        std::cout << "Point " << i << ": (" << starPoints[i].x << ", " << starPoints[i].y << ")" << std::endl;
    }

    return 0;
}
