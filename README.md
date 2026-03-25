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
| 1 000            | 0.0033683              | 0.0045043            | 0.003581              |
| 10 000           | 0.0332899              | 0.0441353            | 0.0357364             |
| 100 000          | 0.316732               | 0.518383             | 0.357291              |
| 1 000 000        | 12.47667               | 26.27343             | 18.68001              |
| 10 000 000       | 120.9164               | 263.7273             | 181.5412              |

## Pakartotinų matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.0033868              | 0.0025857            | 0.003564              |
| 10 000           | 0.0343509              | 0.0437381            | 0.0339266             |
| 100 000          | 0.314891               | 0.419675             | 0.338495              |
| 1 000 000        | 12.59094               | 26.27369             | 18.69661              |
| 10 000 000       | 121.0477               | 263.9848             | 182.5063              |

## Laiko matavimų vidurkis

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.00337755             | 0.004545             | 0.0035725             |
| 10 000           | 0.0338204              | 0.0439367            | 0.0348315             |
| 100 000          | 0.3158115              | 0.5160365            | 0.347893              |
| 1 000 000        | 12.533805              | 26.27356             | 18.68831              |
| 10 000 000       | 120.98205              | 263.85605            | 181.42375             |

Pagal laiko matavimų rezultatus matosi, jog sparčiausiai programa veikė su std::vector tipo konteineriais, o lėčiausiai su std::list, nors teoriškai sparčiausias
turėjo būti std::vector, o lėčiausias std::list. Taip nutinka dėl konteinerių skirtingos atminties panaudojimo. std::vector naudoja vientisą atmintį, std::deque -
blokinę atmintį, o std::list elementai pasiekiami per rodykles.

## Release v1.0
Po pradinio relese išleidimo buvo padarytas programos optimizavimas 3 skirtingomis strategijomis su fiksuotu konteneriu - std::vector. Lentelėje pateikiami
matavimų vidurkiai.

## 1 strategija (pateikiamas kelių testų laikų vidurkis)

| Failo dydis      | std::vector                   | std::list                | std::deque                        |
|------------------|-------------------------------|--------------------------|-----------------------------------|
| 1 000            | 0.0030354                     | 0.0023829                | 0.0039401                         |
| 10 000           | 0.0240486                     | 0.0324099                | 0.0570868                         |
| 100 000          | 0.28094                       | 0.332449                 | 0.538205                          |
| 1 000 000        | 12.72145                      | 26.55926                 | 18.5782                           |
| 10 000 000       | 120.6255                      | 261.365                  | 180.152                           |

std::vector yra greičiausias, nes naudoja vientisą atmintį ir pasižymi geriausia cache lokalizacija, std::deque - šiek tiek lėtesnis 
dėl segmentuotos atminties, std::list - lėčiausias, nes elementai saugomi per rodykles, o tai blogina cache panaudojimą. 

## 2 strategija (pateikiamas kelių testų laikų vidurkis)

| Failo dydis      | std::vector                   | std::list                | std::deque                        |
|------------------|-------------------------------|--------------------------|-----------------------------------|
| 1 000            | 0.0371157                     | 0.0032958                | 0.0209625                         |
| 10 000           | 3.45011                       | 0.0320269                | 2.27534                           |
| 100 000          | 385.784                       | 0.344122                 | 174.784                           |
| 1 000 000        | > 1 h (nebaigta)              | 3.73521                  | > 1 h (nebaigta)                  |
| 10 000 000       | > 1 h (nebaigta)              | 32.9376                  | > 1 h (nebaigta)                  |

Testavimas su std:: vector ir std::deque dideliems failams (1 000 000 ir 10 000 000 įrašų) nebuvo pilnai užbaigtas dėl labai ilgo vykdymo laiko (virš 1 
valandos). Tai rodo, kad ši strategija su šiuo konteineriu yra neefektyvi dideliems duomenų kiekiams.

Galima pastebėti, kad su std::list 2 strategija veikia greičiausiai, o pats lečiausias yra std::vector. std::list konteineryje elementų šalinimas vykdomas O(1) 
sudėtingumu, nes pakanka pakeisti rodykles į gretimus elementus, nereikia perkelti likusių duomenų. Tuo tarpu std::vector konteineryje erase operacija yra O(n), 
nes po kiekvieno pašalinimo visi sekantys elementai turi būti perstumti atmintyje. Kadangi šioje strategijoje šalinimo operacija atliekama daug kartų, bendras 
veikimo laikas stipriai išauga, ypač dirbant su dideliais duomenų kiekiais. std::deque konteineris šiuo atveju pasirodo geriau nei std::vector, tačiau vis tiek 
ženkliai atsilieka nuo std::list. Taip yra todėl, kad skirtingai nei std::vector, kuris naudoja vientisą atminties bloką, std::deque yra sudarytas iš kelių 
mažesnių atminties blokų (segmentų), sujungtų per indeksavimo mechanizmą, kas šiek tiek paspartina elementų perstumimą, lyginant su std::vector.

## 3 strategija (pateikiamas kelių testų laikų vidurkis)

| Failo dydis      | std::vector                   | std::list                | std::deque                        |
|------------------|-------------------------------|--------------------------|-----------------------------------|
| 1 000            | 0.0025987                     | 0.0034226                | 0.0046571                         |
| 10 000           | 0.0255509                     | 0.0374303                | 0.0391001                         |
| 100 000          | 0.276189                      | 0.351151                 | 0.55269                           |
| 1 000 000        | 3.0776                        | 4.90309                  | 3.80778                           |
| 10 000 000       | 33.412                        | 43.9702                  | 33.0299                           |

3 strategijoje naudojamas efektyvus STL algoritmas, kuris leidžia išvengti brangių šalinimo (erase) operacijų ir sumažinti kopijavimo kiekį. Elementai yra 
swap'inami tame pačiame konteineryje. std::vector čia buvo greičiausias, nes turi nuoseklią atmintį, std::deque naudoja segmentuotą atmintį, o partition metu 
vyksta daug perrikiavimų tarp segmentų, todėl blogiau panaudojamas cache.

Bendra išvada:

3 strategija yra efektyviausia, nes ji išvengia brangių šalinimo operacijų ir sumažina kopijavimo kiekį, naudodama optimizuotus STL algoritmus. Tuo tarpu 2 
strategija tampa neefektyvi dėl dažnų erase operacijų, o 1 strategija, nors ir paprasta, reikalauja papildomo kopijavimo ir atminties.

Nuotraukos, kad tyrimai įvyko:

<img width="628" height="293" alt="Ekrano kopija 2026-03-23 194906" src="https://github.com/user-attachments/assets/e939ed13-3195-457b-8df9-4aec73089b37" />
<img width="628" height="293" alt="Ekrano kopija 2026-03-23 195102" src="https://github.com/user-attachments/assets/7a0ce1bc-e794-499d-a64f-18a327bdae39" />
<img width="628" height="293" alt="Ekrano kopija 2026-03-23 195132" src="https://github.com/user-attachments/assets/0286e212-79ca-4fe3-b33d-36eaabd7ea2b" />


## Naudojimosi instrukcija

Įsitikinkite, kad turite įdiegtą CMake (minimali rekomenduojama versija yra 3.10). Atidarykite terminalą ir nueikite į projekto katalogą. 

**Programos paruošimas naudojimuisi:** (šituos žingsnius reikia daryti tik pirmą kartą leidžiant programą)
1. Paruoškite programą kompiliavimui su komanda: cmake .
4. Sukompiliuokite projektą: cmake --build .

**Programos paleidimas:**

Norėdami paleisti programą, terminale įveskite komandą: .\output\Debug\programa.exe
