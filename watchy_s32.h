#ifndef WATCHY_S32_H
#define WATCHY_S32_H

#include <Watchy.h>
#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>


#define DEG2RAD 0.0174532925

class WatchyS32 : public Watchy{
    using Watchy::Watchy;
    public:
        WatchyS32(const watchySettings& s) : Watchy(s) {}
        void drawWatchFace();
    private:
  };
#endif
