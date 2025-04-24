# Arduino Password Check con SHA256

Este proyecto implementa una verificación de contraseña en un Arduino Nano usando un hash SHA256.

## 🔐 Funcionalidad

- El usuario ingresa una contraseña por el monitor serial.
- Se calcula el hash SHA256 de la entrada.
- Se compara contra un hash predefinido (guardado en el código).
- Si coinciden, se imprime "Acceso concedido", si no, "Acceso denegado".

## 📦 Dependencias

- Arduino IDE
- [ArduinoBearSSL](https://github.com/arduino-libraries/ArduinoBearSSL) o una librería compatible con SHA256 como **Crypto** o **SHA256**.

> ⚠️ Asegurate de no tener conflictos entre librerías que implementan SHA256. Usá solo una.

## ⚙️ Uso

1. Subí el código al Arduino.
2. Abrí el Monitor Serial (9600 baudios).
3. Ingresá una contraseña.
4. Observá la respuesta.

