#include "button.h"

void button_init(int pin)
{
pinMode(pin, INPUT_PULLUP);
}

// pas pertinent       next... find a way of button init qui cree tout last state digital read stocker dans une variable

// next faire aussi une fonction button is pressed qui retourne true si appuye et false sinon, en utilisant le last state pour eviter les rebonds

