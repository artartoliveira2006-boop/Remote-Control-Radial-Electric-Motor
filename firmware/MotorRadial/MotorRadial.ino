#include "arduino_secrets.h"

#include <WiFi.h>
#include <HTTPClient.h>
#include "variaveis.h"

TaskHandle_t tarefaInternet;

void setup() {
  Serial.begin(115200);
  delay(5000);

  pinMode(COIL0_PIN, OUTPUT);
  pinMode(COIL1_PIN, OUTPUT);
  pinMode(COIL2_PIN, OUTPUT);
  pinMode(COIL3_PIN, OUTPUT);
  pinMode(COIL4_PIN, OUTPUT);
  desligarTodasAsBobinas();

  xTaskCreatePinnedToCore(
    vTarefaInternet,
    "TarefaInternet",
    10000,
    nullptr,
    1,
    &tarefaInternet,
    0
  );

  delay(500);
  conectarWifi();
  testeBobinas();
}
void vTarefaInternet(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    consultarComandoRemoto();
    vTaskDelay(10000 / portTICK_PERIOD_MS);
  }
}

void loop() {
  if (ligado && verificado) {
    sequencia();
  } else {
    desligarTodasAsBobinas();
    delay(100);
  }
}
