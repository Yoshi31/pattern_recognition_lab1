#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

int main() {
    cv::Mat image = cv::imread("C:/Users/zayka/Source/Repos/CV_NGTU/img.jpg", cv::IMREAD_COLOR);

    if (image.empty()) {
        cout << "Unable to read the image" << endl;
        return 1;
    }

    cv::Size size = image.size();

    cv::line(image, cv::Point(size.width / 10, size.height / 10),
        cv::Point(size.width / 4, size.height / 10), cv::Scalar(255, 0, 0), 5); // Blue

    cv::circle(image, cv::Point(size.width / 2, size.height / 2), 40, cv::Scalar(0, 255, 0), 5); // Green

    cv::circle(image, cv::Point(size.width - size.width / 10, size.height / 10), 40, cv::Scalar(0, 0, 255), -1); // Red

    cv::rectangle(image, cv::Point(size.width / 10, size.height - size.height / 10),
        cv::Point(size.width / 3, size.height - size.height / 4), cv::Scalar(255, 255, 0), -1); // Yellow

    cv::rectangle(image, cv::Point(size.width - size.width / 10, size.height - size.height / 10),
        cv::Point(size.width - size.width / 3, size.height - size.height / 4), cv::Scalar(255, 0, 255), 2); // Purple

    cv::putText(image, "Width: " + to_string(size.width), cv::Point(size.width / 2 + 400, size.height / 2 - 20),
        cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 2); // White

    cv::putText(image, "Height: " + to_string(size.height), cv::Point(size.width / 2 + 400, size.height / 2 + 20),
        cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 2); // White

    cv::imshow("title", image);
    cv::moveWindow("title", 0, 200);
    cv::waitKey(0);

    return 0;
}