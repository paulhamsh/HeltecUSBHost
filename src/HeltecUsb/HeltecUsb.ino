#include "BluetoothSerial.h"
#include "heltec.h"
#include <usbh_midi.h>

#define PGMNAME "Heltec USB"
// MIDI vars
USB Usb;
USBH_MIDI MIDIUSBH(&Usb);

int scr_line;
char midistr[50];

void printit(char *str) {
  if (scr_line >= 7) {
    Heltec.display->clear();
    Heltec.display->drawString(0, 0, PGMNAME);
    scr_line = 1;
  }
  Heltec.display->drawString(0,scr_line *8, str);
  Heltec.display->display();
  scr_line++;
}


void midi_event() {
   uint8_t receive_buf[MIDI_EVENT_PACKET_SIZE];
   uint16_t received;

   uint8_t *p;
   
   int return_code = 0;     //return code
   int count = 0;
   
   int header, chan, miditype, dat1, dat2;
   int i, j, k;
   
   return_code = MIDIUSBH.RecvData(&received, receive_buf);

   //check there is data
   if (return_code != 0 || received == 0) return;
   if (receive_buf[0] == 0 && receive_buf[1] == 0 && receive_buf[2] == 0 && receive_buf[3] == 0) return;
   
   while (count < received)  {
      p = &receive_buf[count];
      if (p[0] == 0 && p[1] == 0) break; //data end

      header =   p[0] & 0x0f;
      chan =     p[1] & 0x0f + 1;
      miditype = p[1] & 0xf0;
      dat1 =     p[2];
      dat2 =     p[3];

      count += 4;

      sprintf(midistr, "%02Xh %d %d", miditype, dat1, dat2);
      printit(midistr);
            
      if (miditype == 0x90) {
      }
      else if (miditype == 0xB0) {
      }
   }
}

void start_midi() {
   if (Usb.Init() == -1) {
      printit("USB host init failed");
      while (true); //halt
   }
}

void setup() {
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Enable*/, true /*Serial Enable*/);

  
  Heltec.display->clear();
  Heltec.display->drawString(0, 0, PGMNAME);
  Heltec.display->display();
  scr_line = 1;

  start_midi();
}


  
void loop() {

  Usb.Task();
  if (MIDIUSBH) {
    midi_event();
  }
}
