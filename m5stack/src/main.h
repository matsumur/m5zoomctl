const char* SSID = "YOUR WIFI SSID";
const char* PASSWD = "YOUR WIFI PASSWORD";
const char* SERVER = "http://YOUR SERVER ADDRESS:5000";

const int AUDIO = 1;
const int VIDEO = 2;

void setup();
void loop();
void sendCmd(const char host[], int mode);
