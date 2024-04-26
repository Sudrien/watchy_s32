#include "watchy_s32.h"

void WatchyS32::drawWatchFace() {
  display.fillScreen(GxEPD_WHITE);
  

  for(int16_t i = 0; i < 256; i++) {
    display.drawLine(
      100,
      100,
      100 + 200 * sin(i * 1.40625 * DEG2RAD),
      100 - 200 * cos(i * 1.40625 * DEG2RAD),
      GxEPD_BLACK
      );
    }
  
  display.fillRect(
    5,
    5,
    190,
    190,
    GxEPD_WHITE
    );
  

  for(int16_t i = 0; i < 16; i++) {
    display.drawLine(
      100,
      100,
      100 + 200 * sin(i * 22.5 * DEG2RAD),
      100 - 200 * cos(i * 22.5 * DEG2RAD),
      GxEPD_BLACK
      );
    }

  display.fillCircle(
    100,
    100,
    90,
    GxEPD_WHITE
    );


  display.fillRect(
    33,
    33,
    134,
    134,
    GxEPD_WHITE
    );


  char time_buffer[9]; // leave space for nul terminator
  int16_t  x_center, y_center;
  uint16_t w_center, h_center;
  long long stamp = makeTime(currentTime) - settings.gmtOffset;

  uint16_t mods0 = (stamp / (256 * 256 * 256)) % 256;
  uint16_t mods1 = (stamp / (256 * 256)) % 256;
  uint16_t mods2 = (stamp / (256)) % 256;
  uint16_t mods3 = stamp % 256;


  char mods_buffer0[64];
  char mods_buffer1[64];
  char mods_buffer2[64];
  char mods_buffer3[64];

  sprintf(mods_buffer0, "%02X", mods0);
  sprintf(mods_buffer1, "%02X", mods1);
  sprintf(mods_buffer2, "%02X", mods2);
  sprintf(mods_buffer3, "%02X", mods3);




  sprintf(time_buffer, "%08X", stamp);

  display.setFont(&FreeSansBold12pt7b);
  display.setTextColor(GxEPD_BLACK);
  display.getTextBounds(time_buffer, 0, 0, &x_center, &y_center, &w_center, &h_center);

  display.setCursor(100 - w_center / 2, 176 - h_center / 2);
  display.println(time_buffer);

  

  display.setFont(&FreeMonoBold9pt7b);
  display.setTextColor(GxEPD_WHITE);






  display.drawCircle(100, 100, 86, GxEPD_BLACK);
  display.fillCircle(
    100 + 86 * sin((360 * mods3 / 256.0) * DEG2RAD),
    100 - 86 * cos((360 * mods3 / 256.0) * DEG2RAD),
    12,
    GxEPD_BLACK
    );
  display.fillTriangle(
    100,
    100,
    100 + 86 * sin((360 * mods3 / 256.0) * DEG2RAD + atan(12/86.0)),
    100 - 86 * cos((360 * mods3 / 256.0) * DEG2RAD + atan(12/86.0)),
    100 + 86 * sin((360 * mods3 / 256.0) * DEG2RAD - atan(12/86.0)),
    100 - 86 * cos((360 * mods3 / 256.0) * DEG2RAD - atan(12/86.0)),
    GxEPD_BLACK
    );
  display.getTextBounds( mods_buffer3, 0, 0, &x_center, &y_center, &w_center, &h_center);
  display.setCursor(
    99 + 86 * sin((360 * mods3 / 256.0) * DEG2RAD) - w_center / 2,  
    110 - 86 * cos((360 * mods3 / 256.0) * DEG2RAD) - h_center / 2
    );
  display.println(mods_buffer3);



  display.drawCircle(100, 100, 62, GxEPD_BLACK);
  display.fillCircle(
    100 + 62 * sin((360 * mods2 / 256.0) * DEG2RAD),
    100 - 62 * cos((360 * mods2 / 256.0) * DEG2RAD),
    12,
    GxEPD_BLACK
    );
  display.fillTriangle(
    100,
    100,
    100 + 62 * sin((360 * mods2 / 256.0) * DEG2RAD - (atan(12/62.0))),
    100 - 62 * cos((360 * mods2 / 256.0) * DEG2RAD - (atan(12/62.0))),
    100 + 62 * sin((360 * mods2 / 256.0) * DEG2RAD + (atan(12/62.0))),
    100 - 62 * cos((360 * mods2 / 256.0) * DEG2RAD + (atan(12/62.0))),
    GxEPD_BLACK
    );
  display.getTextBounds( mods_buffer2, 0, 0, &x_center, &y_center, &w_center, &h_center);
  display.setCursor(
    99 + 62 * sin((360 * mods2 / 256.0) * DEG2RAD) - w_center / 2,  
    110 - 62 * cos((360 * mods2 / 256.0) * DEG2RAD) - h_center / 2
    );
  display.println(mods_buffer2);
  


  display.drawCircle(100, 100, 38, GxEPD_BLACK);
  display.fillCircle(
    100 + 38 * sin((360 * mods1 / 256.0) * DEG2RAD),
    100 - 38 * cos((360 * mods1 / 256.0) * DEG2RAD),
    12,
    GxEPD_BLACK
    );
  display.fillTriangle(
    100,
    100,
    100 + 38 * sin((360 * mods1 / 256.0) * DEG2RAD - (atan(12/38.0))),
    100 - 38 * cos((360 * mods1 / 256.0) * DEG2RAD - (atan(12/38.0))),
    100 + 38 * sin((360 * mods1 / 256.0) * DEG2RAD + (atan(12/38.0))),
    100 - 38 * cos((360 * mods1 / 256.0) * DEG2RAD + (atan(12/38.0))),
    GxEPD_BLACK
    );
  display.getTextBounds( mods_buffer1, 0, 0, &x_center, &y_center, &w_center, &h_center);
  display.setCursor(
    99 + 38 * sin((360 * mods1 / 256.0) * DEG2RAD) - w_center / 2,  
    110 - 38 * cos((360 * mods1 / 256.0) * DEG2RAD) - h_center / 2
    );
  display.println(mods_buffer1);



  display.drawCircle(100, 100, 14, GxEPD_BLACK);
  display.fillCircle(
    100 + 14 * sin((360 * mods0 / 256.0) * DEG2RAD),
    100 - 14 * cos((360 * mods0 / 256.0) * DEG2RAD),
    12,
    GxEPD_BLACK
    );
  display.fillTriangle(
    100,
    100,
    100 + 14 * sin((360 * mods0 / 256.0) * DEG2RAD - (atan(12/14.0))),
    100 - 14 * cos((360 * mods0 / 256.0) * DEG2RAD - (atan(12/14.0))),
    100 + 14 * sin((360 * mods0 / 256.0) * DEG2RAD + (atan(12/14.0))),
    100 - 14 * cos((360 * mods0 / 256.0) * DEG2RAD + (atan(12/14.0))),
    GxEPD_BLACK
    );
  display.getTextBounds( mods_buffer0, 0, 0, &x_center, &y_center, &w_center, &h_center);
  display.setCursor(
    99 + 14 * sin((360 * mods0 / 256.0) * DEG2RAD) - w_center / 2,  
    110 - 14 * cos((360 * mods0 / 256.0) * DEG2RAD) - h_center / 2
    );
  display.println(mods_buffer0);
  

  }



