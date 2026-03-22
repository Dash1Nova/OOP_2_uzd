# Aprašymas
Ši programa skaičiuoja studentų galutinius pažymius pagal suvestus ranka arba sugeneruotus namų darbų pažymius bei egzamino įvertinimus.

## Release v.pradinė
Sukurtas pagrindinis programos funkcionalumas: programa leidžia įvesti studentų vardus, pavardes, namų darbų rezultatus ir egzamino balą. Galutinis balas 
skaičiuojamas pagal namų darbų vidurkį arba medianą (vartotojas gali pasirinkti). Rezultatai pateikiami dviejų skaičių po kablelio tikslumu. Vieno studento 
duomenys saugomi struktūroje.

## Release v0.1
Programa papildyta ir veikia su nežinomu studentų ir namų darbų skaičiumi prieš įvedimą. Yra dvi versijos: viena realizuota su C masyvais, kita - su std::vector.
Pridėta galimybė atsitiktinai generuoti namų darbų ir egzamino įvertinimus. Sukurtas meniu skirtingiems programos vykdymo variantams: galima įvesti viską ranka,
generuoti tik pažymius, generuoti studentų vardus, pavardes ir pažymius, baigti darbą.

## Release v0.2
Programa papildyta, kad vartotojas galėtų nuskaityti studentų duomenis iš failo (tik std::vector versija). Programa leidžia pasirinkti duomenų rūšiavimo būdą: 
pagal vardą, pavardę arba galutinį pažymį (vidurkį arba medianą). Išvedimas galimas tiek terminale, tiek faile, išvestis išlygiuota.

## Release v0.3
Funkcijų deklaracijos ir structūra perkelti į atskirus antraštinius (*.h) failus. Programa padalinta į kelis *.cpp failus pagal funkcionalumą, kad būtų lengviau 
peržiūrėti ir pildyti kodą. Pridėtas klaidų gaudymo metodas (Eception Handling): gaudomos failų atidarymo klaidos, tikrinama įvestis, kad vartotojas negalėtų 
įvesti neleistinų reikšmių, visi pranešimai išvedami lietuvių kalba.

## Release v0.4
Sukurta funkcija, kuri generuoja studentų failus pagal nurodytą įrašų skaičių. Vardai ir pavardės generuojami šabloniškai. Studentai su galutiniu balu < 5.0 
perkeliami į failą „vargšiukai“, studentai su galutiniu balu >= 5.0 perkeliami į failą „kietiakai“. Buvo atlikti du tyrimai: buvo matuojama, kiek užtrunka 
sugeneruoti failą su nurodytu įrašų skaičiumi bei matuojamas duomenų apdorojimos laikas: failo nuskaitymas, studentų rūšiavimas į dvi grupes, išvedimas į failus,
bendras programos vykdymo laikas. Tyrimų rezultatai užfiksuoti ir pateikti lentelėse README.md faile v0.4 šakoje su komentarais.

## Release v1.0-initial
Po v0.4 versijos programos pritaikymo naudojimui su 3 skirtingų tipų konteineriais (vector, list, deque), buvo atliktas papildomas programos veikimo spartos 
tyrimas, kuriuo buvo siekiama įvertinti, kaip keičiasi programos našumas naudojant skirtingus C++ standartinės bibliotekos konteinerius. Kadangi failų kūrimo
bei rezultatų išvedimo į failus sparta nepriklauso nuo naudojamo kontenerio tipo, šio tyrimo metu buvo matuojamas tik šių dalių įvykdymo sparta: duomenų 
nuskaitymas iš failo į pasirinktą konteinerį, studentų rūšiavimas didėjimo tvarka konteneryje, studentų skirstymas į dvi grupes. Tyrimo patikimumui visi testai
buvo atliekami su tais pačiais failais 5 skirtingų dydžių: 1000, 10000, 100000, 1000000 ir 10000000 įrašų apimties.

Lentelėse pateikiamas bendras šių trijų operacijų vykdymo laikas.

## Testavimo sistemos parametrai:
• CPU: AMD Ryzen 7 7730U with Radeon Graphics;  
• RAM: 16 GB DDR4;  
• Diskas: SSD 512 GB.

## Laiko matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.0033683              | 0.0025043            | 0.003581              |
| 10 000           | 0.0332899              | 0.0241353            | 0.0357364             |
| 100 000          | 0.316732               | 0.218383             | 0.357291              |
| 1 000 000        | 3.47667                | 2.27343              | 3.68001               |
| 10 000 000       | 38.9164                | 33.7273              | 43.5412               |

## Pakartotinų matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.0033868              | 0.0025857            | 0.003564              |
| 10 000           | 0.0343509              | 0.0237381            | 0.0339266             |
| 100 000          | 0.314891               | 0.219675             | 0.338495              |
| 1 000 000        | 3.59094                | 2.27369              | 3.69661               |
| 10 000 000       | 39.0477                | 33.9848              | 43.5063               |

## Laiko matavimų vidurkis

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.00337755             | 0.002545             | 0.0035725             |
| 10 000           | 0.0338204              | 0.0239367            | 0.0348315             |
| 100 000          | 0.3158115              | 0.2160365            | 0.347893              |
| 1 000 000        | 3.533805               | 2.27356              | 3.68831               |
| 10 000 000       | 38.98205               | 33.85605             | 43.42375              |

Pagal laiko matavimų rezultatus matosi, jog sparčiausiai programa veikė su std::list tipo konteineriais, o lėčiausiai su std::deque, nors teoriškai sparčiausias
turėjo būti std::vector, o lėčiausias std::list. Taip galėjo nutikti dėl kelių priežasčių: 
1. naudojamoje Student struktūroje yra dinaminės atminties objektų (std::vector), todėl rūšiavimo ir kopijavimo metu gali atsirasti papildomos atminties valdymo
   sąnaudos;
2. std::list konteineris rūšiuodamas naudoja savo merge sort algoritmą, kuris perjungia elementų rodykles, o ne perkelia pačius objektus;
3. matavimo rezultatus taip pat gali paveikti kompiuterio architektūra, atminties talpyklos (cache) veikimas, kompiliatoriaus optimizacijos.
Dėl šių priežasčių gauti praktiniai rezultatai galėjo ne visiškai sutapti su teorinėmis prielaidomis.

## Release v1.0
Po pradinio relese išleidimo buvo padarytas programos optimizavimas 3 skirtingomis strategijomis su fiksuotu konteneriu - std::vector. Lentelėje pateikiami
matavimų vidurkiai.

| Failo dydis      | 1 strategija (s) - for ciklas | 2 strategija (s) - erase | 3 strategija (s) - std::partition |
|------------------|-------------------------------|--------------------------|-----------------------------------|
| 1 000            | 0.0030354                     | 0.0371157                | 0.0025987                         |
| 10 000           | 0.0240486                     | 3.45011                  | 0.0255509                         |
| 100 000          | 0.28094                       | 385.784                  | 0.276189                          |
| 1 000 000        | 2.72145                       | 3617.46                  | 3.0776                            |
| 10 000 000       | 31.6804                       | 35117.1                  | 33.412                            |


## Naudojimosi instrukcija
Atsisiųskite repozitoriją ir išarchyvuokite zip katalogą. Jei dar neturite, įdiekite MinGW C/C++ kompiliatorių. Atidarykite katalogą pasirinktoje IDE. Atidarykite 
terminalą. Jei įdiegėte MinGW ir norite paleisti programą, terminale surinkite komandą mingw32-make run (priklausomai nuo MinGW diegimo versijos gali būti 
paleidimui reikalingos komandos mingw-make run arba make run). Dabar terminale matysite meniu. Perskaitykite jį, pasirinkę punktą, surinkite skaičių terminale ir 
spauskite Enter. Sekite meniu terminale.
