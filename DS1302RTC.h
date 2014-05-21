/*
 * DS1302RTC.h - library for DS1302 RTC
 * This library is intended to be uses with Arduino Time.h library functions
 */

#ifndef DS1302RTC_h
#define DS1302RTC_h

#include <Time.h>

// library interface description
class DS1302RTC
 { // user-accessible "public" interface
   public:
      DS1302RTC(uint8_t io, uint8_t sclk, uint8_t rst);
      static time_t get();
      static bool set(time_t t);
      static bool read(tmElements_t &tm);
      static bool write(tmElements_t &tm);
   
      static void halt();
      static bool chipPresent() { return exists; }

   private:
      static void clock_burst_read(uint8_t *p);
      static void clock_burst_write(uint8_t *p);
      static uint8_t read(int address);
      static void write(int address, uint8_t data);
      static void start(void);
      static void stop(void);
      static uint8_t toggleread(void);
      static void togglewrite( uint8_t data, uint8_t release);
   
   private:
      static bool exists;
      
      static uint8_t io;
      static uint8_t sclk;
      static uint8_t rst;
 };

#endif
