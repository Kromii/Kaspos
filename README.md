# Kaspos

Tämä ohjelma on osa Tampereen ammattikorkeakoulun talotekniikan koulutuksen IoT-projektia, jossa rakennetaan olosuhdelaboratoriota ilmanlaadun tarkkailuun erilaisissa olosuhteissa. 
Ohjelma toimii konfiguroitavana tilakoneena, joka yhdistää erilaisia sensoreita useilla viestintätavoilla yhden laitteen hallintaan ja lähettää mitatun tiedon pilvipalveluun.

### Järjestelmävaatimukset

Ohjelma on suunniteltu Linux -käyttöjärjestelmälle, erityisesti Raspberry Pi:n Rasbian -alustalle. Projekti käyttää CMake:a ohjelman rakentamiseen. 
Ohjelma ei sisällä seuraavia kirjastoja, joten ne pitää asentaa ennen ohjelman rakentamista esim. apt-get pakettimanagerin kanssa:
libconfig++
libmosquitto
libmosquittopp
pkg-config
libmodbus
libcurl

IOT_API kirjasto on lisensoitu: The MIT License (MIT) Copyright (c) 2015 Wapice Ltd. (https://github.com/IoT-Ticket/) Projektissa käytetään IoT-LinuxCppClient -kirjastoa ja se rakennetaan projektin rakentamisen yhteydessä.

(Listaus saattaa olla keskeneräinen. Ohjelmaa kääntäessä puuttuvat kirjastot tulevat ilmi)

### Asentaminen

1. Kopioi ohjelma GitHubista (git clone https://github.com/kromii/kaspos)
2. Rakenna projekti juurikansiosta Kaspos (cmake ./)
3. Käännä projekti juurikansiosta Kaspos (make)
4. Käynnistä ohjelma ./Kaspos - Parametrit -t "1" antavat debug-ikkunan

### Käyttö

Ohjelma on kyseisessä versiossaan tarkoitettu käytettäväksi projektin sensoripuolen Arduino-ohjelman kanssa ( INSERT LINK)
Muokkaamalla konfigurointitiedostoa on mahdollista liittää ja hallita em. ohjelman mukaisia Arduino-sensori -yhdistelmiä kokonaisuuteen ja siirtää sensoridataa pilvipalveluun. Tuetut viestiprotokollat:
-MQTT valmiiksi ohjelmoidulla viestikehyksellä
	- Kyselytopic: "kysely"
    - Viestiformaatti 01 | 001 | 01 | 01 (Lähetettävä pyyntö on 010010101)
    - Viestikehystunnus 01 (2 numeroa) , tilakoneen sensoritunnista 001 (3 numeroa), arduinon ID 01 (2 numeroa), arduinon sensorin ID 01 (2 numeroa).
    
    - Vastaustopic: "vastaus"
    - Viestiformaatti 01 | 001 | 12345 (Lähetettävä vastaus on 0100112345)
    - Viestikehystunnus 01 (2 numeroa), tilakoneen sensoritunniste 001 (3 numeroa), sensorin AD-muunnettu lukema (1-10 numeroa)
    





