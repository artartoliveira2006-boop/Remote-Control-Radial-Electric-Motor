#pragma once

const char *ssid = SECRET_SSID;
const char *password = SECRET_PASSWORD;

// Arquivo publico que recebe MOTOR_ON ou MOTOR_OFF.
const char *github_raw_url =
  "https://raw.githubusercontent.com/artartoliveira2006-boop/"
  "Remote-Control-Radial-Electric-Motor/refs/heads/main/commands.txt";

// 1 = sequencial; 2 = radial/estrela.
#define MODO 1

#if MODO == 1
  const int COIL0_PIN = 14;
  const int COIL1_PIN = 17;
  const int COIL2_PIN = 27;
  const int COIL3_PIN = 25;
  const int COIL4_PIN = 16;

  const double TEMPO_INICIAL = 800.0;
  const double TEMPO_MINIMO = 100.0;
  const double TEMPO_DECAIMENTO = 40000.0;
#elif MODO == 2
  const int COIL0_PIN = 14;
  const int COIL3_PIN = 17;
  const int COIL1_PIN = 27;
  const int COIL4_PIN = 25;
  const int COIL2_PIN = 16;

  const double TEMPO_INICIAL = 500.0;
  const double TEMPO_MINIMO = 80.0;
  const double TEMPO_DECAIMENTO = 20000.0;
#else
  #error "MODO invalido. Use 1 ou 2."
#endif

volatile unsigned long tempoInicioMotor = 0;
volatile bool ligado = false;
volatile bool verificado = false;

const int n = 5;
const int k = 2;
int pProx;
int pAtual = 0;
double t;
