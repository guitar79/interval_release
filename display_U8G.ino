#include <U8glib.h>
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);  // I2C / TWI 

void U8G_start()
  {
    u8g.setFont(u8g_font_5x8);
    u8g.setColorIndex(1);
    u8g.setFontPosTop();
  }

void draw()
  {
    u8g.firstPage();   
    do {
            u8g.setFont(u8g_font_unifont); u8g.setFontPosTop();
            u8g.setPrintPos(2, 0);
            u8g.print(firmware_Name);
            u8g.setPrintPos(85, 0);
            u8g.print(firmware_Ver);
            u8g.drawStr(0, 14, "DELAY : ");
            u8g.setPrintPos(90, 14);
            u8g.print(val_delay_begin_ms);
            u8g.drawStr(0, 26, "SHUTTER : ");
            u8g.setPrintPos(90,26);
            u8g.print(val_shutterspeed_ms);
            u8g.drawStr(0,38,"INTERVAL:");
            u8g.setPrintPos(90,38);
            u8g.print(val_interval_ms);
            u8g.drawStr(0,50,"<<STOP");
            u8g.drawStr(70,50,"START>>");
        } 
      while( u8g.nextPage() );
  }
  
