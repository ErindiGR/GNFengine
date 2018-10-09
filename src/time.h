#ifndef TIME_H
#define TIME_H


#include "commun.h"


class time
{

    static double _time_prev;
    static double _time_fps_prev;
    static uint   _fps;
    static float  _dt;

public:

    static double get_time();
    static float get_delta_time();
    static void update();

};


#endif //!TIME_H