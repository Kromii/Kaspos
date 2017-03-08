#include "wapice.h"

using namespace libconfig;

void wapiceDeviceSpec(){

	//wapice user name is global std::string wapiceUser;
	//wapice user password is global std::string wapicePassword
	//device ID is global std::string wapiceDevID (wapice device id)

	Config wcfg;
	try {
		wcfg.readFile("config.cfg");
	}

	catch(const FileIOException &fioex){
		std::cerr << "I/O error while reading file." << std::endl;
		return;
	}

	catch(const ParseException &pex){
		std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - " << pex.getError() << std::endl;
		return;
	}

	const Setting& root = wcfg.getRoot();
	const Setting& wapice = root["wapice"];

	std::cout << "Roots set" << std::endl;

	wapice.lookupValue("user", wapiceUser);
	std::cout << "user" << wapiceUser << std::endl;
	wapice.lookupValue("password", wapicePassword);
	std::cout << "password" << wapicePassword << std::endl;
	wapice.lookupValue("deviceID", wapiceDevID);
	std::cout << "deviceID" << wapiceDevID << std::endl;
	wapice.lookupValue("url", wapiceUrl);
	std::cout << "url" << wapiceUrl << std::endl;

	if (wapiceUser.empty() || wapicePassword.empty() || wapiceUrl.empty()){
		std::cout << "Wapice information is missing something in config.cfg" << std::endl;
	}

	IOT_API regApi(wapiceUrl, wapiceUser, wapicePassword);

	//if no device ID, register and write config
	if (wapiceDevID.empty()){
		IOT_RegDevice dev;
		std::string deviceName;
		std::string manufacturer;
		const Setting& rpi = root["rpi"];
		rpi.lookupValue("deviceName", deviceName);
		std::cout << deviceName << std::endl;
		rpi.lookupValue("manufacturer", manufacturer);
		std::cout << manufacturer << std::endl;
		dev.SetName(deviceName);
		dev.SetManufacturer(manufacturer);

		if (regApi.RegisterDevice(dev, wapiceDevID) != IOTAPI::IOT_ERR_OK) {
			return;
		}
		Setting &setID = wcfg.lookup("wapice.deviceID");
		std::cout << "root.wapice.deviceid" << std::endl;
		setID = wapiceDevID;
		wcfg.writeFile("config.cfg");
		std::cout << "Registered device and wrote config, ID = " << wapiceDevID << std::endl;

	}

	return;
}


void wapiceSend(std::string name, std::string path, std::string type, float value){

	//Vector for wapice IOT_API, store data and send.
	std::vector<IOT_WriteData> dataVector;
	IOT_WriteData data;

	data.SetName(name);
	data.SetUnit(type);
	data.SetValue(value);
	data.SetPath(path);
	data.SetTimeToNow();

	dataVector.push_back(data);

	for (int i = 0; i < 2; i++){
		//Attempt to send data for 2 times
		IOT_API sendApi (wapiceUrl, wapiceUser, wapicePassword);
		if (sendApi.SendData(wapiceDevID, dataVector) != IOTAPI::IOT_ERR_OK) {
			std::cerr << "Failed to send data for "<< i + 1 << " times." << std::endl;
			std::cout << "Failed to send data for " << i + 1 << " times." << std::endl;
			wapicecounter = wapicecounter +1;
			i++;
		}
		else {
			i = 2;
		}
	}
	wapicecounter = wapicecounter - 1;
	dataVector.clear();

	return;
}
