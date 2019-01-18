int LEDblau = 3; // Farbe blau an Pin 3
int LEDrot = 4; // Farbe rot an Pin 5
int LEDgruen=6; // Farbe gruen an Pin 6
int p=5-000; // p ist eine Pause mit 1000ms also 1 Sekunde
int brightness1a = 150; // Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int brightness1b = 150; // Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int brightness1c = 150; // Zahlenwert zwischen 0 und 255 – gibt die Leuchtstärke der einzelnen Farbe an
int dunkel = 0; // Zahlenwert 0 bedeutet Spannung 0V – also LED aus

void setup()
{
pinMode(LEDblau, OUTPUT);
pinMode(LEDgruen, OUTPUT);
pinMode(LEDrot, OUTPUT);
}

void loop()
{
analogWrite(LEDgruen, brightness1c); // gruen und rot ein = gelb
analogWrite(LEDrot, brightness1b);
}
