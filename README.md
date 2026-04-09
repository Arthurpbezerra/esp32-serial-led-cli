# Serial LED CLI (ESP32)

Projeto de estudo em embarcados com ESP32 (Arduino + PlatformIO), focado em UART CLI não bloqueante e organização modular de código.

## Objetivo

Controlar LEDs por comandos via Serial, com parser de linha não bloqueante e separação em módulos (`main`, `cli`, `commands`, `app`).

## Funcionalidades

- Leitura de comandos pela UART em 115200 baud
- Controle de LEDs:
  - `red on`
  - `red off`
  - `blue on`
  - `blue off`
- Comandos de apoio:
  - `help`
  - `status`
  - `uptime`

## Comandos suportados

| Comando    | Descrição |
|------------|-----------|
| `help`     | Lista os comandos disponíveis |
| `status`   | Mostra estado lógico dos LEDs |
| `uptime`   | Mostra tempo desde boot |
| `red on`   | Liga LED vermelho |
| `red off`  | Desliga LED vermelho |
| `blue on`  | Liga LED azul |
| `blue off` | Desliga LED azul |

## Estrutura do projeto

- `src/main.cpp`  
  Inicialização geral e `loop()` com chamada da CLI.
- `src/cli/cli.h` / `src/cli/cli.cpp`  
  Leitura UART, buffer e fechamento de linha.
- `src/cli/commands.h` / `src/cli/commands.cpp`  
  Parser e execução dos comandos.
- `src/app/app_state.h`  
  Estado compartilhado da aplicação.
- `src/app/pins.h`  
  Mapeamento centralizado de pinos.

## Ambiente

- ESP32 DevKit (PlatformIO)
- Framework Arduino
- Baud rate: `115200`

## Como executar

1. Abra a pasta `Serial_Led` no VS Code/PlatformIO.
2. Compile o projeto.
3. Faça upload para ESP32 ou rode no simulador.
4. Abra o Serial Monitor em `115200`.
5. Envie os comandos listados acima.

## Próximos passos sugeridos

- Padronizar respostas (`OK`, `ERR`, `USAGE`)
- Tratar overflow de linha no parser da CLI
- Adicionar sintaxe alternativa:
  - `set led <red|blue> <on|off>`
  - `get uptime`