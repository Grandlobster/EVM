#include<iostream>
#include<string>
#include<./timer/time.h>
// #include<./blockchain_db/bcdb.cpp>
// this is still in development 

#include "MFRC522.h" // Include the library for the RFID reader

// Define GPIO pins for SPI (adjust based on your wiring)
#define RST_PIN 22  // Reset pin
#define SS_PIN 24   // Slave Select pin

MFRC522 rfid(SS_PIN, RST_PIN);
using namespace std;
class card{
	long int rfid;
}
class candidate{
public:
	string name;
	char symbol;
private:
	global int position;
	global float rank;
	
}
}
main(){
	// from main program call the bool value
	// flag variable has to modified in the timer.cpp file and timer.h file to 
	int type=0;
	while(flag){
		// Initialize wiringPi and the RFID reader
    if (wiringPiSetup() == -1) {
        std::cerr << "Error setting up wiringPi." << std::endl;
        return -1;
    }
    rfid.PCD_Init();

    std::cout << "Place an RFID card near the reader..." << std::endl;

    while (true) {
        // Look for new cards
        if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) {
            delay(100); // Wait for a moment
            continue;
        }

        // Read the RFID card ID
        std::string cardID;
        for (byte i = 0; i < rfid.uid.size; i++) {
            cardID += (i == 0 ? "" : ":") + 
                      (ostringstream() << hex << std::setw(2) << setfill('0') 
                      << (int)rfid.uid.uidByte[i]).str();
        }

        cout << "RFID Card ID: " << cardID << endl;
		
		//
		
		
}
	