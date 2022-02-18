#include <DHT.h>
#include <LiquidCrystal.h>
#define DHTPIN 8 // 8 è il pin di Arduino a cui collego il sensore di temperatura.
#define DHTTYPE DHT11 // DHT11 è il tipo di sensore che uso.

DHT dht(DHTPIN, DHTTYPE);
#define RS 2
#define EN 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7); // connessione display una vola definiti i pin.

void setup()
{
  lcd.begin(16, 2); // Definisci in pixel larghezza e altezza del tuo schermo.
  dht.begin(); // Attivo il sensore.
}
void loop()
{
  float t = dht.readTemperature();
  int h = dht.readHumidity();
  lcd.clear();

  lcd.setCursor(0, 0); // imposto la riga dove stamperà il dato.
  lcd.print(" Gradi: " + String(t) + char(0xDF) + "C");
  lcd.setCursor(0, 1); // imposto la riga dove stamperà il dato.
  lcd.print(" Umidita': " + String(h) + "%");
  delay(1000); // Attendi 1000 ms per poter riaggiornare i dati.
}
