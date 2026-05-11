// Konfigurasi Pin
#define MICROPHONE_PIN 4 

void setup() {
  // Pipa komunikasi sudah diperbesar ke tingkat maksimal ESP32
  Serial.begin(921600);
  
  // ADC di ESP32-S3 diatur ke 12-bit
  analogReadResolution(12);
}

void loop() {
  // Mencatat waktu mulai loop untuk mengontrol frekuensi sampling
  unsigned long start_time = micros();

  // Membaca nilai dari mikrofon MAX9814
  int raw_audio = analogRead(MICROPHONE_PIN);
  
  // Mengirim nilai ke Serial
  Serial.println(raw_audio);

  // Menghitung jeda agar tetap stabil di sekitar 16kHz
  unsigned long execution_time = micros() - start_time;
  if (execution_time < 62) {
    delayMicroseconds(62 - execution_time); 
  }
}
