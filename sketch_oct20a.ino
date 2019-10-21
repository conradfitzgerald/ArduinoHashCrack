#include <MD5.h>
char returnVal[33]; //An MD5 hash is ALWAYS 32 characters long, or 128bit. Add an extra byte for null-termination.
char buf[64]; //The max Serial buffer is 64 bytes.

void setup() {
  pinMode(2, INPUT_PULLUP); //Unnecessary at the moment, will be needed later.
  Serial.begin(115200);
  //delay(1000); //A second to start up properly.
}

void clearBuffer(){
  for (int i = 0; i < 64; ++i){
    buf[i] = 0x00;
  }
}

void hashMD5(char a[]){
  unsigned char* hash = MD5::make_hash(a);
  char *md5str = MD5::make_digest(hash, 16); //Direct example from Tzikis's GitHub.
  for(int i = 0; i < 32; ++i){
    returnVal[i] = md5str[i]; //Assigning the global variable character by character.
  }
  returnVal[32] = 0x00; //Always null-terminate your strings, kids!
  free(hash); //Since we're looping, we need to free up the memory before another iteration.
  free(md5str);
}

void loop() {
  clearBuffer();
  if(Serial.available()){
      Serial.readBytesUntil('\n', buf, 64);
      if(buf){
          hashMD5(buf);
          Serial.print(returnVal);
      }
      Serial.flush();
  }
}
