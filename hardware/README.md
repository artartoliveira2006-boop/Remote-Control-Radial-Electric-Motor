# Hardware e montagem

Este diretório registra o circuito de acionamento do motor radial de cinco bobinas. O [projeto compartilhado no Tinkercad](https://www.tinkercad.com/things/hriccYSg3r2-dazzling-gaaris-fulffy/editel?sharecode=ODh7P4tV9Ig7Nv-Jada4wmx27EI8rfMsCgkdmTvJzwE) pode exigir login na Autodesk.

## Sinais usados pelo firmware

No modo sequencial (`MODO == 1`), o firmware usa:

| Saída lógica | GPIO |
| --- | ---: |
| `COIL0_PIN` | 14 |
| `COIL1_PIN` | 17 |
| `COIL2_PIN` | 27 |
| `COIL3_PIN` | 25 |
| `COIL4_PIN` | 16 |

No modo radial (`MODO == 2`), os mesmos GPIOs são associados às saídas em outra ordem. A tabela descreve apenas o firmware; a correspondência física entre saída, transistor e bobina ainda deve ser conferida no protótipo.

## Acionamento e alimentação

As bobinas não podem ser ligadas diretamente aos GPIOs do microcontrolador. O sketch menciona um ULN2003 como estágio de potência. Antes de energizar:

1. confirme a tensão e a corrente nominal de cada bobina;
2. use fonte externa dimensionada para a corrente simultânea prevista;
3. mantenha o GND da fonte, do driver e da placa em comum;
4. confirme a ligação das proteções contra tensão reversa do driver;
5. teste uma bobina por vez, por intervalo curto, observando aquecimento;
6. mantenha um meio físico de cortar a alimentação das bobinas.

O programa executa um teste automático de todas as bobinas na inicialização. Não energize a potência antes de confirmar a pinagem e os limites térmicos.

## Dados ainda necessários

- modelo exato da placa ESP32;
- modelo e quantidade dos drivers;
- tensão, resistência e corrente das bobinas;
- tensão e corrente máxima da fonte;
- diagrama definitivo das ligações;
- identificação física das bobinas 0 a 4.
