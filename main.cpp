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

    cv::Mat_<cv::Vec4b> image_RGB;
    cv::Mat_<cv::Vec4b> image_A;
    image_RGB = imread("C:/Users/icema/Desktop/OTUS_Project/Imported_Resource/lenna.png");
    image_A = imread("C:/Users/icema/Desktop/OTUS_Project/Imported_Resource/alpha.png");
    if ( !image_RGB.data||!image_A.data )
    {
        printf("No image data \n");
        return -1;
    }
    //Mat temp;
    //cv::cvtColor(image_RGB,temp,COLOR_BGR2BGRA,4);
    //createAlphaImage(image_A,image_RGB);
    namedWindow("Изображение", WINDOW_AUTOSIZE );
    imshow("Изображение", image_RGB);
    /*cv::Mat_<cv::Vec4b> imgs;
    imgs.push_back(image_RGB);
    imgs.push_back(~image_RGB);
    imgs.push_back(image_RGB(Rect(0, 0, image_RGB.cols / 2, image_RGB.rows / 2)));
    imwrite("test.png", imgs);
    
    imwrite("test.png", image_RGB);*/
    waitKey(0);
    
    
    return 0;
}