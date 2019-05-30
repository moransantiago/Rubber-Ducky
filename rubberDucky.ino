#include <Keyboard.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  Keyboard.begin();
  delay(500);

  Keyboard.press(KEY_LEFT_GUY);
  Keyboard.press('r');
  delay(500);
  Keyboard.releaseAll();
  delay(500);

  delay(500);
  Keyboard.end();
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {

}
