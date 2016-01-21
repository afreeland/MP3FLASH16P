/*
  MP3FLASH16P.h - Library for the MP3 FLASH 16P module
  Created by /u/Critters
  Released into the public domain
*/

#ifndef MP3FLASH16P_h
#define MP3FLASH16P_h
#include "Arduino.h"

class MP3FLASH16P
{
    public:
        MP3FLASH16P();
        void init(int PIN_BUSY, int VOLUME = 30);
        void playFile(int FILE_NUMBER, int VOLUME = -1);
        void playFileAndWait(int FILE_NUMBER, int VOLUME = -1);
        void setVolume(int VOLUME);
        void volumeUp();
        void volumeDown();
        void stopPlay();
        bool isBusy();
        uint8_t checksumCalc(uint8_t *instruction_params);
        uint8_t * buildParams(uint8_t *instruction_params, int len);
        void makeRequest(uint8_t * params, int len);
    private:
        int _PIN_BUSY;
        uint8_t _VOLUME;
        bool isPlaying;
};

#endif
