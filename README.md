# Voice-Command-Irigasi-ESP32
Proyek Sistem Irigasi Pintar menggunakan ESP32-S3 (Lexin N16R8) dan Mikrofon MAX9814 dengan Edge Impulse.

**Spesifikasi Hardware:**
* Mikrokontroler: ESP32-S3 Varian Lexin N16R8 (16MB Flash, 8MB PSRAM)
* Sensor Suara: Mikrofon MAX9814 (dengan fitur AGC aktif)
* Baud Rate Serial: 921600 bps
* Sampling Rate: ~13.000 Hz


## Progres AI Training (Edge Impulse)
* Model berhasil dilatih menggunakan algoritma MFCC dan Neural Network (Keras).
* **Akurasi Model:** 79.4%
* **Kemampuan Live Classification:** Berhasil mendeteksi kata kunci ("Siram" dan "Stop") secara real-time dengan akurasi tinggi.

![Hasil Training AI](Screenshot%202026-05-12%20153550.png)
