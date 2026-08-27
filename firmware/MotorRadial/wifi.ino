void conectarWifi() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }

  Serial.println("Conectado ao Wi-Fi.");
}
void consultarComandoRemoto() {
  if (WiFi.status() != WL_CONNECTED) {
    return;
  }

  HTTPClient http;
  const String urlFinal = String(github_raw_url) + "?t=" + String(millis());

  http.begin(urlFinal);
  http.addHeader("Cache-Control", "no-cache");

  const int httpCode = http.GET();
  if (httpCode > 0) {
    String payload = http.getString();
    payload.trim();
    Serial.println("Comando remoto: " + payload);

    if (payload == "MOTOR_ON") {
      if (!ligado) {
        tempoInicioMotor = millis();
      }
      ligado = true;
    } else if (payload == "MOTOR_OFF") {
      ligado = false;
    }
  } else {
    Serial.println("Erro HTTP: " + String(httpCode));
  }

  http.end();
}
