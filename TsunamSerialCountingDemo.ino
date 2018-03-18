#include <Tsunami.h>            // Include the Tsunami library header
Tsunami tsunami;                // Our Tsunami object

////
// Uses the demo files and basic setup from SparkFun Tsunami Hookup Guide.
// https://learn.sparkfun.com/tutorials/tsunami-hookup-guide

// Load the tsunami demo files onto the SD card.
// https://cdn.sparkfun.com/assets/learn_tutorials/6/2/2/tsunami-demo-files.zip

void setup() {
  
  // Serial monitor
  Serial.begin(9600);
 
  // We should wait for the Tsunami to finish reset before trying to send commands.
  delay(1000);

  // Tsunami startup at 57600
  tsunami.start();
  delay(10);
  
  // Send a stop-all command and reset the sample-rate offset, in case we have reset while the Tsunami was already playing.
  tsunami.stopAllTracks();
  tsunami.samplerateOffset(0, 0);
  
  // Enable track reporting from the Tsunami
  tsunami.setReporting(true);
  
  // Allow time for the Tsunami to respond with the version string and number of tracks.
  delay(1000);
  
}

void loop() {

  // Call update on the Tsunami to keep the track playing status current.
  tsunami.update();

  //tsunami.trackPlaySolo(1,0,false);
  
  int i=1;
  while(i <= 16){
    tsunami.trackPlayPoly(i,0,false);
    // Delay
    delay(1000);
    i++;
  }
}

