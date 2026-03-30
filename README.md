# Controlador de LEDs via Serial (ESP32 + PlatformIO)

Projeto simples de embarcados com ESP32 que liga/desliga LEDs via comandos recebidos pela serial.

### Descrição
- Recebe texto pela porta serial (115200).
- Comandos válidos: `blue on`, `blue off`, `red on`, `red off`.
- Acende/apaga LED conectado em GPIO2 (vermelho) e GPIO4 (azul).

## Tecnologias Utilizadas
- ESP32 DevKitC
- Framework Arduino (PlatformIO)
- PlatformIO CLI / VS Code Extension
- Simulador Wokwi (`wokwi.toml`, `diagram.json`)

## Como Executar
1. Abra a pasta do projeto no VS Code.
2. Instale as extensões:
   - PlatformIO IDE
   - Wokwi Extension (opcional para simulação)
3. Conecte placa ESP32 ou use simulação:
   - Build local: `PlatformIO: Build`
   - Upload: `PlatformIO: Upload`
4. Abra Serial Monitor:
   - Baud 115200
   - Envie comandos de texto e veja respostas.

## Esquema de Comandos
| Comando     | Ação                        |
|-------------|-----------------------------|
| `blue on`   | Acende LED azul (GPIO4)     |
| `blue off`  | Apaga LED azul (GPIO4)      |
| `red on`    | Acende LED vermelho (GPIO2) |
| `red off`   | Apaga LED vermelho (GPIO2)  |

## Simulação (Wokwi)
- Arquivos inclusos:
  - `wokwi.toml`
  - `diagram.json`
- Com a extensão Wokwi instalada, abra `wokwi.toml` e clique em `Simulate`.
- Use o Serial Monitor integrado à simulação para enviar comandos em tempo real.

## Estrutura do Projeto
- `src/main.cpp` — lógica principal de leitura serial e controle de GPIO.
- `platformio.ini` — configuração de ambiente e board.
- `diagram.json` — desenho do circuito.
- `wokwi.toml` — configuração do ambiente de simulação.