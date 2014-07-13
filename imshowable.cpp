#include "imshowable.h"

ImShowable::ImShowable()
{
}

void ImShowable::imShow(cv::Mat m)
{
    cv::imshow("Default show",m);
}
