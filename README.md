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

(Listaus saattaa olla keskeneräinen. Ohjelmaa kääntäessä puuttuvat kirjastot tulevat ilmi)

### Asentaminen

1. Kopioi ohjelma GitHubista (git clone https://github.com/kromii/kaspos)
2. Rakenna projekti juurikansiosta Kaspos (cmake ./)
3. Käännä projekti juurikansiosta Kaspos (make)
4. Käynnistä ohjelma ./Kaspos - Parametrit -t "1" antavat debug-ikkunan




