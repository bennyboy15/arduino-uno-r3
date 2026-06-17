#include <LiquidCrystal.h>

enum Faces
{
    SMILE,
    SAD,
    WINK
};

// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

char* arr[3] = {"SMILE", "SAD", "WINK"};
int index = 0;
bool buttonWasPressed = false;

void happyFace()
{
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("I   I");
    lcd.setCursor(6, 1);
    lcd.print("\\");
    lcd.print("___/");
}

void sadFace()
{
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("I   I");
    lcd.setCursor(5, 1);
    lcd.print("_-```-_");
}

void winkFace()
{
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print("I   ~");
    lcd.setCursor(6, 1);
    lcd.print("____/");
}

void runSelectedFace(int face)
{
    switch (face)
    {
    case SMILE:
        happyFace();
        break;
    case SAD:
        sadFace();
        break;
    case WINK:
        winkFace();
        break;
    }
}

void setup()
{
    lcd.begin(16, 2);
    lcd.print("FACE PICKER!");
}

void loop()
{
    lcd.setCursor(0, 1);
    int buttonValue = analogRead(A0);

    // ANY BUTTON BEING PRESSED
    if (buttonValue < 800)
    {

        // ONLY TRIGGER IF BUTTON WAS ALREADY NOT BEING HELD DOWN
        if (!buttonWasPressed)
        {

            if (buttonValue < 60)
            {
                // RIGHT
                runSelectedFace(index);
            }
            else if (buttonValue < 200)
            {
                // UP
                index++;
                index = constrain(index, 0, 2);
            }
            else if (buttonValue < 400)
            {
                // DOWN
                lcd.print("Button: DOWN  ");
                index--;
                index = constrain(index, 0, 2);
            }
            else if (buttonValue < 600)
            {
                // LEFT
                lcd.print("Button: LEFT  ");
            }
            else if (buttonValue < 800)
            {
                // SELECT
                lcd.print("Button: SELECT");
            }

            // SET TO TRUE TO IGNORE THIS LOGIC UNTIL NEXT PRESSED & NOT HELD
            buttonWasPressed = true;

            delay(50);
        }
    }

    // IF NO BUTTONS PRESSED
    else
    {
        buttonWasPressed = false;
        lcd.setCursor(0, 0);
        lcd.print("FACE PICKER!    ");
        lcd.setCursor(0, 1);
        lcd.print("[" + String(index) + "]");
        lcd.print(arr[index]);
        lcd.print("                ");
    }
}