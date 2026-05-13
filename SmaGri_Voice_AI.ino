#include <Irigasi_Proyek_konsentrasi_inferencing.h>

#define MICROPHONE_PIN 4

// Buffer memori untuk merekam suara
float features[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE];

void setup() {
    Serial.begin(115200);
    
    
    delay(3000); 
    
    Serial.println("=========================================");
    Serial.println("Sistem Irigasi AI - Bangkit dan Siap Mendengar!");
    
    analogReadResolution(12);
}

void loop() {
    ei_printf("\nMenunggu perintah... (Bicara sekarang!)\n");

    uint32_t record_start = millis();

    for (int i = 0; i < EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE; i++) {
        uint32_t start_time = micros();
        int raw_audio = analogRead(MICROPHONE_PIN);
        
        
        features[i] = (float)((raw_audio - 2048) * 15);

        
        if (i % 1000 == 0) yield();

        while (micros() - start_time < (1000000 / EI_CLASSIFIER_FREQUENCY)) {
            
        }
    }

    ei_printf("Memproses suara...\n");

    signal_t signal;
    int err = numpy::signal_from_buffer(features, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);
    if (err != 0) {
        ei_printf("Gagal membuat signal (%d)\n", err);
        return;
    }

    ei_impulse_result_t result = { 0 };
    err = run_classifier(&signal, &result, false);
    if (err != EI_IMPULSE_OK) {
        ei_printf("Gagal menjalankan AI (%d)\n", err);
        return;
    }

    ei_printf("Hasil Prediksi (Berdasarkan Suaramu):\n");
    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
        ei_printf("    %s: %.5f\n", result.classification[ix].label, result.classification[ix].value);
    }

    delay(1000);
}