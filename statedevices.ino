#include <SPI.h>
#include <Ethernet.h>
#include <PubNub.h>
#include <aJSON.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

char pubkey[] = "demo";
char subkey[] = "demo";
char channel[] = "statekeeper";

//setup 
void setup()
{

	Serial.begin(9600);
	Serial.println("Serial set up");

	while (!Ethernet.begin(mac)) {
		Serial.println("Ethernet setup error");
		delay(1000);
	}
	Serial.println("Ethernet set up");

	PubNub.begin(pubkey, subkey);
	Serial.println("PubNub set up");
}
aJsonObject *createJSON()
{
        aJsonObject *msg = aJson.createObject();
	aJson.addStringToObject(msg, "name", "Arduino");
	aJson.addNumberToObject(msg, "TemperatureOutside", 34);
        return msg;
}

// establishing internet connection to the Arduino and publishing the state

void loop()
{
	Ethernet.maintain();

	EthernetClient *client;
        aJsonObject *message = createJSON();
        char *msgstr = aJson.print(message);
        aJson.delete(message);
        
        msgstr = (char *)realloc(msgstr, strlen(msgstr)+1);
	
	client = PubNub.publish(channel, msgstr);
        free(msgstr);
	if (!client) {
		Serial.println("publishing error");
	} else {
		client->stop();
	}

	delay(5000);
}
