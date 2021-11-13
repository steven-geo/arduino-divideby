This code is a simple customisable divide by counter used to decrease the frequency from a flow sensor from something in the 100-200Hz range, back to 1-2Hz to allow a simple pulse counter for water flow.

Connect the Input to Arduino Pin 0 (Pin 5), and the output to Arduino pin 2 (Pin 7)

         +---\/---+
    n/c  |1*     8|  VCC
    n/c  |2      7|  OUTPUT
    n/c  |3      6|  n/c
    GND  |4      5|  INPUT
         +--------+
