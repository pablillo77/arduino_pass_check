#include <SHA256.h>

SHA256 sha256;

String input = "";
bool ready = false;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Esperar conexión
  Serial.println("Ingresá la contraseña:");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();

    if (c == '\n' || c == '\r') {
      if (input.length() > 0) {
        ready = true;
      }
    } else {
      input += c;
      Serial.print("*");  // Mostrar asterisco en vez del carácter real
    }
  }

  if (ready) {
    Serial.println(); // Salto de línea

    // Calcular SHA-256
    sha256.reset();
    sha256.update((const uint8_t*)input.c_str(), input.length());

    uint8_t result[32];
    sha256.finalize(result, sizeof(result));

    // Convertir a hexadecimal
    String hashHex = "";
    for (int i = 0; i < 32; i++) {
      if (result[i] < 16) hashHex += "0";
      hashHex += String(result[i], HEX);
    }

    Serial.print("Hash generado: ");
    Serial.println(hashHex);

    // Comparar con hash esperado
    String knownHash = "8d969eef6ecad3c29a3a629280e686cf0c3f5d5a86aff3ca12020c923adc6c92"; // hash("123456")
    if (hashHex.equalsIgnoreCase(knownHash)) {
      Serial.println("✅ Contraseña correcta");
    } else {
      Serial.println("❌ Contraseña incorrecta");
    }

    // Reset
    input = "";
    ready = false;
    Serial.println("\nIngresá otra contraseña:");
  }
}
