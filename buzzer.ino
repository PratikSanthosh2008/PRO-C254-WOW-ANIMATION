// Define frequency notes
#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define G4 392.00
#define A4 440.00
#define B4 493.88

// Define pin
int speakerOut = 26;
int DEBUG = 1;

void setup() {
  pinMode(speakerOut, OUTPUT);
  if (DEBUG) {
    Serial.begin(9600);
  }
}

double happyBirthdayMelody[] = {
  G4, G4, A4, G4, C4, B4, G4,
  G4, A4, G4, D4, C4,
  G4, G4, A4, G4, C4, B4, G4,
  G4, A4, G4, D4, C4,
  G4, G4, G5, E5, C5, B4, A4,
  F5, F5, E5, C5, D5, C5
};

int happyBirthdayLength = sizeof(happyBirthdayMelody) / sizeof(double);

long tempo = 10000;
int pause = 1000;
int rest_count = 2;

int tone_ = 0;
int beat = 0;
long duration = 0;

void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) {
    while (elapsed_time < duration) {
      digitalWrite(speakerOut, HIGH);
      delayMicroseconds(tone_ / 2);
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

      elapsed_time += (tone_);
    }
  } else {
    for (int j = 0; j < rest_count; j++) {
      delayMicroseconds(duration);
    }
  }
}

void loop() {
  for (int i = 0; i < happyBirthdayLength; i++) {
    tone_ = happyBirthdayMelody[i];
    beat = 50;
    duration = beat * tempo;

    // call the playTone()
    playTone();

    delayMicroseconds(pause);
  }
}