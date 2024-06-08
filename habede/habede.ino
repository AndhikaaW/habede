#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int col = 16;
const int row = 2;

const char message[] = "Happy Birthday!";
const char message2[] = "Rahma Dwi Maulia";
const char message3[] = "Putri";
const byte loveChar[8] = {
  0b00000,
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
};


LiquidCrystal_I2C lcd(0x27, col, row);

int position = 0;
int position3 = 0;
int position4 = 0;
int position5 = 0;
int positionGeser1 = 0;
int positionGeser2 = 2;
int messageLength = strlen(message);
int messageLength2 = strlen(message2);
int messageLength3 = strlen(message3);

// tones
int speakerPin = 11;
int length = 77; // the number of notes
char notes[] = "CDFA AGFAcA AGFGAGF FGAGF FGGGAG CDFA AGFAcA AGFGAGF FGAGF FGGGAG "; //juga kalung hati
                                    
int beats[] = {16,16,8,16,8,16,16,8,16,8,16, //hari ini hari yang kau tunggu
                4,16,16,8,8,8,8,16,4,8,8,8,8,16, 4,8,8,16,8,16,24, //bertambah satu tahun usiamu bahagialah selalu
                4,16,16,8,16,8,16,16,8,16,8,16, //yang kuberi bukan jam dan cincin
                4,16,16,8,8,8,8,16,4,8,8,8,8,16, 4,8,24,8,24,16,16,24 //bukan seikat bunga atau puisi juga kalung hati
                };
int tempo = 90;

void playTone(int tone, int duration) {
  
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
void playNote(char note, int duration) {
  
  char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           
                  'c', 'd', 'e', 'f', 'g', 'a', 'b',
                  'x', 'y' };

  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,
                  956,  834,  765,  593,  468,  346,  224,
                  655 , 715 };
  int SPEE = 5;
  // play the tone corresponding to the note name
  for (int i = 0; i < 17; i++) {
    if (names[i] == note) {
      int newduration = duration/SPEE;
      playTone(tones[i], newduration);
    }
  }
}


void setup() {
  lcd.init();
  lcd.backlight();
  // lcd.clear();
  lcd.createChar(0, loveChar);
  // tones
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // lcd
  lcd.clear();
  while (position < messageLength) {
    lcd.setCursor(position, 0);
    lcd.print(message[position]); 

    position++; 
    delay(300); 
  }
  lcd.clear();
  while (position3 < messageLength2) {
    lcd.setCursor(position3, 0);
    lcd.print(message2[position3]); 
    position3++; 
    delay(300); 
  }
  while (position4 < messageLength3) {
    lcd.setCursor(position4, 1);
    lcd.print(message3[position4]); 
    position4++; 
    delay(300); 
  }

  // lcd.clear();
  // lcd.setCursor(position5, 0);
  // lcd.print("semoga panjang umur sehat selalu"); 

  // position += 1; 
  
  // if(position >= col){
  //   lcd.scrollDisplayLeft();
  // }
  delay(300);

  // tones
 for (int i = 0; i < length; i++) {
    // Memainkan nada
    if (notes[i] == ' ') {
      delay(beats[i] * tempo); // istirahat
    } else {
      playNote(notes[i], beats[i] * tempo);
    }

    lcd.clear();
    lcd.setCursor(positionGeser1, 0);
    lcd.print("Happy Birthday");
    lcd.setCursor(positionGeser2, 1);
    lcd.write((byte)0);
    lcd.print("cintaku");
    lcd.write((byte)0);

    positionGeser1 += 1;
    positionGeser2 += 1;

    if(positionGeser1 < 0 || positionGeser1 >= col || positionGeser2 < 0 || positionGeser2 >= col){
      positionGeser1 = 0;
      positionGeser2 = 2;
    }
    // pause between notes
    delay(tempo);
  }
}

// https://www.youtube.com/watch?v=DLDSK0nJUoI

// 1 2 46 65 4 6  ! 6
// 6  5  4  5 6  5 4  5654  4 5 5 5  6  5
// 1 246 6 5 4 6  ! 6
// 6 5 4 5 6 5 4 5654 45 5 5 65


// C D FA AG F A  c A
// A G F G A G F GAGF FG G G AG
// C DFA A G F A  c A
// A G F G A G F GAGF FG G G AG
