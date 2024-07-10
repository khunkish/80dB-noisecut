#include <driver/i2s.h>

// I2S configuration
void i2s_setup() {
    i2s_config_t i2s_config = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_TX),
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
        .communication_format = I2S_COMM_FORMAT_I2S,
        .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
        .dma_buf_count = 8,
        .dma_buf_len = 64,
        .use_apll = false,
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = 14,
        .ws_io_num = 15,
        .data_out_num = 25,
        .data_in_num = 32
    };

    i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin_config);
    i2s_zero_dma_buffer(I2S_NUM_0);
}

void setup() {
    Serial.begin(115200);
    i2s_setup();
}

void loop() {
    int16_t i2s_data[64];
    size_t bytes_read;

    // Read data from microphone
    i2s_read(I2S_NUM_0, &i2s_data, sizeof(i2s_data), &bytes_read, portMAX_DELAY);

    // Process the data (implement noise cancellation algorithm here if needed)

    // For simplicity, just output the same data
    size_t bytes_written;
    i2s_write(I2S_NUM_0, &i2s_data, bytes_read, &bytes_written, portMAX_DELAY);
}
