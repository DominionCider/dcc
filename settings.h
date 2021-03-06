#include <EEPROM.h>

void saveSettings() {
    EEPROM.put(0, settings);
    EEPROM.put(sizeof(settings), SETTINGS_VERSION);
    EEPROM.commit();
    Serial.println("Saved settings to EEPROM " + String(SETTINGS_VERSION));
}

void loadSettings() {
  EEPROM.begin(sizeof(settings) + 5);

  char v[5];
  EEPROM.get(sizeof(settings), v);
  if (String(v) == SETTINGS_VERSION) {
    EEPROM.get(0, settings);
    Serial.println("Loaded settings from EEPROM " + String(v));
  } else {
    Serial.println("Failed to load settings from EEPROM. Using defaults.");
  }
}
