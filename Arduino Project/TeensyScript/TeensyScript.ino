// to enable USB Midi you have to go to tools > Board: and select a Teensy board
// then in tools > USB Type: select "MIDI"
// the MIDI channel number to send messages

//Setup Button
int bankTaste = LOW;
int bankTasteAlt = LOW;
int bankTastePin = 2;
bool freeze = false;
//Setup FSR
int previousA0 = -1; // store previously sent values, to detect changes
int previousA1 = -1;
int previousA2 = -1;
int previousA3 = -1;
int druckKnopfZeige = 15;
int druckKnopfMittel = 16;
int druckKnopfRing = 17;
int druckKnopfKlein = 18;
int n0;
int n1;
int n2;
int n3;

void setup() {  
  pinMode(bankTastePin, INPUT_PULLUP);
  Serial.begin(96000);

}

void loop() {
  bankTaste = digitalRead(bankTastePin);
  //Button pressed
  if(bankTaste==LOW && bankTasteAlt == HIGH){

    if(!freeze){
      freeze=true;
    }else{
      freeze=false;
    }

    bankTasteAlt=bankTaste;
  }

  //Button Released
  if(bankTaste==HIGH && bankTasteAlt == LOW){

    //...do stuff

    bankTasteAlt=bankTaste;
  }

  if(!freeze){
    n0 = analogRead(druckKnopfZeige)/8; //convert 10bit analog signal to 7 bit MIDI
    n1 = analogRead(druckKnopfMittel)/8;
    n2 = analogRead(druckKnopfRing)/8;
    n3 = analogRead(druckKnopfKlein)/8;
    // only transmit MIDI messages if analog input changed
    sPrint(n0);
    sPrint(n1);
    //sPrint(n2); REENABLE LATER
    //sPrint(n3);  ...
  
    sendMidiData(20,n0,previousA0);
    //sendMidiData(21,n1,previousA1); REENABLE LATER
    //sendMidiData(22,n2,previousA2); ..
    //sendMidiData(23,n3,previousA3); ..
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}

void sPrint(int i){
  Serial.println(i);
}

void sendMidiData(int cc,int i, int a){
  if(i != a){
    usbMIDI.sendControlChange(cc,i,1); //(x,x,1) -> 1 ist der Channel, um variabeln zu sparen
    a = i;
  }
}
