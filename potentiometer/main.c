#define POT_PIN A0
#define LED 10

int potValue = 0;   // potentiometer reading
int brightness = 0; // brightness value

void setup()
{
    Serial.begin(9600);   // Initialize serial communication
    pinMode(LED, OUTPUT); // Set the LED pin as an output
}

void loop()
{
    potValue = analogRead(POT_PIN); // Read the potentiometer (0 to 1023)

    // Scale the 0-1023 value down to 0-255 for the LED
    brightness = map(potValue, 0, 1023, 0, 255);

    analogWrite(LED, brightness); // Change the LED brightness

    Serial.print("Pot: ");
    Serial.print(potValue);
    Serial.print(" -> Brightness: ");
    Serial.println(brightness);

    delay(10);
}