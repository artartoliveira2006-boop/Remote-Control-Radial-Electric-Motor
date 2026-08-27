void testeBobinas() {
  Serial.println("\n--- Teste de bobinas ---");

  const int bobinas[] = {
    COIL0_PIN,
    COIL2_PIN,
    COIL4_PIN,
    COIL1_PIN,
    COIL3_PIN
  };

  for (int i = 0; i < 5; i++) {
    Serial.print("Ativando saida da bobina no GPIO ");
    Serial.println(bobinas[i]);
    digitalWrite(bobinas[i], HIGH);
    delay(2000);
    digitalWrite(bobinas[i], LOW);
    delay(1000);
  }

  Serial.println("Teste concluido. Sequenciamento liberado em 5 segundos.");
  delay(5000);
  verificado = true;
}
double calcularDelay() {
  t = millis() - tempoInicioMotor;

  return TEMPO_MINIMO +
         (TEMPO_INICIAL - TEMPO_MINIMO) *
         exp(-t / TEMPO_DECAIMENTO);
}

void sequencia() {
  for (int i = 0; i < n; i++) {
    pProx = (pAtual + k + n) % n;

    if (pProx == 0) {
      digitalWrite(COIL3_PIN, LOW);
      digitalWrite(COIL0_PIN, HIGH);
    } else if (pProx == 1) {
      digitalWrite(COIL4_PIN, LOW);
      digitalWrite(COIL1_PIN, HIGH);
    } else if (pProx == 2) {
      digitalWrite(COIL0_PIN, LOW);
      digitalWrite(COIL2_PIN, HIGH);
    } else if (pProx == 3) {
      digitalWrite(COIL1_PIN, LOW);
      digitalWrite(COIL3_PIN, HIGH);
    } else if (pProx == 4) {
      digitalWrite(COIL2_PIN, LOW);
      digitalWrite(COIL4_PIN, HIGH);
    }

    pAtual = pProx;

    const int tempoAtual = static_cast<int>(calcularDelay());
    const double rpmEstimada = (60000.0 / tempoAtual) * 0.4;

    Serial.print("Delay: ");
    Serial.print(tempoAtual);
    Serial.print(" ms | RPM estimada: ");
    Serial.print(rpmEstimada);
    Serial.print(" | tempo: ");

    const int segundos = static_cast<long>(t / 1000) % 60;
    const int minutos = static_cast<long>(t / 60000) % 60;
    const int horas = static_cast<long>(t / 3600000);

    Serial.print(horas);
    Serial.print("h ");
    Serial.print(minutos);
    Serial.print("m ");
    Serial.print(segundos);
    Serial.println("s");

    delay(tempoAtual);
  }
}

void desligarTodasAsBobinas() {
  digitalWrite(COIL0_PIN, LOW);
  digitalWrite(COIL1_PIN, LOW);
  digitalWrite(COIL2_PIN, LOW);
  digitalWrite(COIL3_PIN, LOW);
  digitalWrite(COIL4_PIN, LOW);
}
