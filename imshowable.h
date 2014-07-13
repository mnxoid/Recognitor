#ifndef IMSHOWABLE_H
#define IMSHOWABLE_H
#include <opencv2/highgui/highgui.hpp>
class ImShowable
{
public:
    ImShowable();
    virtual void imShow(cv::Mat m);
};

#endif // IMSHOWABLE_H
