#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
void createAlphaImage(const cv::Mat_<cv::Vec4b>& mat, cv::Mat_<cv::Vec4b> &dst)
{
    std::vector<cv::Mat_<cv::Vec4b>> MatChannels;
    cv::split(mat,MatChannels);

    cv::Mat alpha=MatChannels.at(0)+MatChannels.at(1)+MatChannels.at(2);
    MatChannels.push_back(alpha);
    cv::merge(MatChannels,dst);
}
int main(int argc, char** argv )
{

    Mat_<cv::Vec4b> image_RGB;
    Mat_<cv::Vec4b> image_A;
    image_RGB = imread("C:/Users/icema/Desktop/OTUS_Project/lenna.png");
    image_A = imread("C:/Users/icema/Desktop/OTUS_Project/alpha.png");
    if ( !image_RGB.data||!image_A.data )
    {
        printf("No image data \n");
        return -1;
    }
    //Mat temp;
    //cv::cvtColor(image_RGB,temp,COLOR_BGR2BGRA,4);
    createAlphaImage(image_A,image_RGB);
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image_A);
    waitKey(0);
    return 0;
}