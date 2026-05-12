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
| 1 000            | 0.0133683              | 0.0245043            | 0.013581              |
| 10 000           | 0.1332899              | 0.2441353            | 0.1357364             |
| 100 000          | 1.316732               | 2.518383             | 1.357291              |
| 1 000 000        | 12.47667               | 26.27343             | 18.68001              |
| 10 000 000       | 120.9164               | 263.7273             | 181.5412              |

## Pakartotinų matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.0133868              | 0.0225857            | 0.013564              |
| 10 000           | 0.1343509              | 0.2437381            | 0.1339266             |
| 100 000          | 1.314891               | 2.419675             | 1.338495              |
| 1 000 000        | 12.59094               | 26.27369             | 18.69661              |
| 10 000 000       | 121.0477               | 263.9848             | 182.5063              |

## Laiko matavimų vidurkis

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.01337755             | 0.024545             | 0.0135725             |
| 10 000           | 0.1338204              | 0.2439367            | 0.1348315             |
| 100 000          | 1.3158115              | 2.5160365            | 1.347893              |
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
| 1 000            | 0.0130354                     | 0.0223829                | 0.0139401                         |
| 10 000           | 0.1240486                     | 0.2324099                | 0.1570868                         |
| 100 000          | 1.28094                       | 2.332449                 | 1.538205                          |
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

## Versija 1.1.

Buvo ištirta programos veikimo sparta su dviem skirtingomis realizacijomis: struktūra Student ir klase Student. Testavimui buvo naudojami dviejų skirtingų dydžių 
failai - 1 000 000 ir 10 000 000 įrašų. Tyrimas buvo daromas su trimis skirtingo optimizavimo lygio vėliavėlėmis (-O1, -O2, -O3). Tokių būdu buvo dar patikrinta, 
kokios įtakos jie turi programos vykdymo spartai. Tyrimo rezultatai pateikti lentelėje.

## Laiko matavimų lentelė (pateikiamas kelių testų laikų vidurkis)

| Versija                  | Failo dydis          | O1 (s)                   | O2 (s)                   | O3 (s)                   |
|--------------------------|----------------------|--------------------------|--------------------------|--------------------------|
| Struktūra                | 1 000 000            | 1.39518                  | 1.14231                  | 1.41373                  |
| Struktūra                | 10 000 000           | 13.0076                  | 12.2371                  | 13.4431                  |
| Klasė                    | 1 000 000            | 1.30656                  | 1.28801                  | 1.30197                  |
| Klasė                    | 10 000 000           | 13.7888                  | 13.4625                  | 13.4954                  |

## exe failų dydžių lentelė

| Versija                  | exe failo dydis su O1 (KB)     | exe failo dydis su O2 (KB)    | exe failo dydis su O3 (KB)     |
|--------------------------|--------------------------------|-------------------------------|--------------------------------|
| Struktūra                | 459                            | 431                           | 429                            |
| Klasė                    | 459                            | 431                           | 438                            |

Išvada: Teoriškai -O3 optimizacija turėjo būti sparčiausia visais atvejais, tačiau praktiškai -O2 optimizavimas buvo sparčiausias, tiek su struktūra, tiek su klase
abiejų failų dydžių atveju, o -O3 optimizacija net pablogina veikimą. Tarp struktūros ir klasės pagal vykdymo greitį skirtumų beveik nėra. -O3 gali turėti labai 
daug instrukcijų, kurios netelpa į L1 cache atmintį, tad CPU tenka laukti instrukcijų iš šiek tiek lėtesnių L2/L3, dėl to optimizacija gali būti neefektyvi. Todėl 
efektyviausia optimizacija dažnai gali būti su -O2 vėliavėle.

## Versija 1.2.

Ši programa skirta studentų duomenų valdymui.
Programos Student klasė saugo studento vardą, pavardę, namų darbų pažymius, egzamino pažymius bei apskaičiuoja
galutinį įvertinimą pagal medianą ir vidurkį.

## Student klasės struktūra

| Kintamasis     | Tipas                | Aprašymas                  |
|----------------|----------------------|----------------------------|
| name_          | std::string          | Vardas                     |
| surname_       | std::string          | Pavardė                    |
| nd_            | std::vector<int>     | Namų darbų balai           |
| egz_           | int                  | Egzamino balas             |
| finalAvg_      | double               | Galutinis pagal vidurkį    |
| finalMed_      | double               | Galutinis pagal medianą    |

## Išvesties ir įvesties operatorių perdengimas

Klasės objektų naudojimosi patogumui buvo perdengti įvedimo ir išvedimo operatoriai.

Įvestis vykdoma per `std::istream`, todėl įvesties operatorius veikia su:
1. rankiniu įvedimu (`cin`)
2. automatiniu įvedimu (`stringstream`)
3. įvedimu iš failo (`ifstream`)

Išvestis vykdoma per std::ostream, todėl išvesties operatorius gali būti naudojamas:
1. išvedimui į ekraną (`cout`)
2. išvedimui į failą (`ofstream`)

Programa taip pat turi rankinius testus, kurie tikrina:
- konstruktorius
- kopijavimą
- move semantiką
- destruktorių
- getter'ius ir setter'ius
- įvesties ir išvesties operatorius
- skaičiavimo tikslumą

Fotografijos:

<img width="905" height="126" alt="Ekrano kopija 2026-04-20 235559" src="https://github.com/user-attachments/assets/35fb71c6-d68d-472f-bb04-2373aaf1f3d2" />
<img width="905" height="126" alt="Ekrano kopija 2026-04-20 235610" src="https://github.com/user-attachments/assets/550631cd-9a87-446f-a1a1-639ae8c7a6f9" />
<img width="905" height="300" alt="Ekrano kopija 2026-04-20 235700" src="https://github.com/user-attachments/assets/375c59d8-9eb8-432c-9e4f-f5748b166c43" />

## Versija 1.5.

Taip pat vėliau buvo pridėta abstrakti klasė Person.
Person klasė turi čiuos kintamuosius: 

| Kintamasis     | Tipas                | Aprašymas                  |
|----------------|----------------------|----------------------------|
| name_          | std::string          | Vardas                     |
| surname_       | std::string          | Pavardė                    |

Tada Student klasėje lieka tik šie keturi kintamieji:

| Kintamasis     | Tipas                | Aprašymas                  |
|----------------|----------------------|----------------------------|
| nd_            | std::vector<int>     | Namų darbų balai           |
| egz_           | int                  | Egzamino balas             |
| finalAvg_      | double               | Galutinis pagal vidurkį    |
| finalMed_      | double               | Galutinis pagal medianą    |

Kadangi ši klasė yra abstrakti, negalima sukurti šios klasės objektų. Tai pagrindžia šios klasės testas, kuris bando 
sukurti Person objektą, tačiau tuo atveju testavimų failas nesikompiliuoja. 

Fototgrafijos, įrodančios, kad taip tikrai yra:

<img width="1212" height="764" alt="Ekrano kopija 2026-04-21 220104" src="https://github.com/user-attachments/assets/7df3b2b9-effa-4096-9a66-33a738b8cfbf" />
<img width="1212" height="963" alt="Ekrano kopija 2026-04-21 220512" src="https://github.com/user-attachments/assets/7627a3ef-a043-4e03-b9f0-164dfc028167" />

Programa išliko veiksni po 1.2 versijos logikos įgyvendinimo:

<img width="1212" height="737" alt="Ekrano kopija 2026-04-21 224544" src="https://github.com/user-attachments/assets/2a8d77c2-0661-4967-8114-40cf61de36a0" />

## Versija 2.0.

Šioje projekto versijoje su Doxygen įrankiu buvo parengta dokumentacija HTML formatu ir PDF formatu per LaTex, kuri aprašo projekte sukurtą klasę. Taip pat buvo 
realizuoti automatiniai unit testai programos klasės copy konstruktoriui, copy priskirimo operatoriui, move konstruktoriui, move priskirimo operatoriui, 
getteriams, setteriams, skaičiavimo logikai, polimorfizmui, išvedimo ir įvedimo operatoriams su failais.
Projektui buvo sudarytas diegimo failas CMakeLists.txt, kuris atskirai generuoja paleidimo failus pačiai programai ir unit testams.

Visi Google unit testai (jų iš viso yra 12) buvo įvykdyti sėkmingai:

<img width="782" height="716" alt="Ekrano kopija 2026-04-27 230456" src="https://github.com/user-attachments/assets/921f8abd-4402-4621-99ca-2b42dd965fa0" />

Klasė ir visi Rule of Five komponentai veikia teisingai, failų I/O ir skaičiavimų logika taip pat yra teisinga. 

## Versija 3.0.

Vektoriaus funkcijų pavyzdžių aprašymai:
1. push_back()
   Prideda naują elementą į vector pabaigą. Jei dabartinė talpa (capacity) yra pilna, automatiškai išskiriama nauja atmintis ir talpa padidinama (dvigubinama).
   Pvz.:
   Vector<int> v;
   v.push_back(1);
   v.push_back(2);
   
2. erase()
   Pašalina elementą pagal indeksą. Visi elementai po pašalinto elemento yra perstumiami į kairę. Operacijos sudėtingumas yra O(n), nes reikia perkopijuoti
   likusius elementus.
   Pvz.:
   Vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);

   v.erase(1);
   
3. resize()
   Pakeičia vector dydį. Jei naujas dydis didesnis, pridedami nauji elementai su default reikšme. Jei mažesnis – pertekliniai elementai pašalinami.
   Pvz.:
   Vector<int> v;
   v.push_back(1);
   v.resize(5);
   
4. operator[]
   Leidžia tiesiogiai pasiekti elementą pagal indeksą be ribų tikrinimo. Greita, bet nesaugu operacija (gali sukelti undefined behavior jei indeksas neteisingas).
   Pvz.:
   Vector<int> v;
   v.push_back(10);
   v[0] = 100;
   
5. at()
   Veikia kaip operator[], bet su papildomu vektoriaus ribų tikrinimu. Jei elemento indeksas yra už ribų, išvedama std::out_of_range žinutė.
   Pvz.:
   Vector<int> v;
   v.push_back(10);
   int x = v.at(0);

std::vector ir Vector spartos palyginimas
Benchmark atliktas naudojant <chrono> biblioteka.  
Matuotas push_back() operacijos laikas, užpildant tuščius vektorius.  
Kiekvienas testas vykdytas atskirai, naudojant naujus (tuščius) vektorius.
Kompiliuojama buvo su -O2 vėliavėle.

| Elementų skaičius | std::vector (ms) | Vector (ms) | Skirtumas (ms)   |
|-------------------|------------------|-------------|------------------|
| 10 000            | 0                | 0           | 0                |
| 100 000           | 0                | 0           | 0                |
| 1 000 000         | 2                | 2           | 0                |
| 10 000 000        | 29               | 44          | 15               |
| 100 000 000       | 351              | 461         | 110              |

Rezultatų analizė: std::vector yra žymiai greitesnis už sukurtą Vector konteinerį. std::vector yra optimizuotas STL konteineris, kuris naudoja efektyvų atminties 
valdymą ir mažina reallocations skaičių. Sukurtas Vector naudoja paprastą new/delete ir rankinį kopijavimą, todėl yra lėtesnis. Didėjant elementų skaičiui, 
skirtumas tampa ryškesnis dėl dažnesnių atminties perskirstymų.

<img width="765" height="487" alt="Ekrano kopija 2026-05-12 013644" src="https://github.com/user-attachments/assets/a1700ce4-bc04-44cf-bed3-2c6625dae25e" />

Realokacijų skaičiaus analizė:
Buvo palygintas std::vector ir realizuoto Vector konteinerių atminties perskirstymų skaičius užpildant konteinerius 10000, 100000, 1000000, 10000000, 
100000000 elementų. Atminties perskirstymas buvo laikomas įvykusiu tada, kai konteinerio capacity() reikšmė pasikeisdavo po push_back() operacijos.

| Elementų skaičius    | std::vector laikas    | std::vector perskirstymai   | Vector laikas     | Vector perskirstymai    |
|----------------------|-----------------------|-----------------------------|-------------------|-------------------------|
| 10 000               | 0 ms                  | 15                          | 0 ms              | 15                      |
| 100 000              | 0 ms                  | 18                          | 0 ms              | 18                      |
| 1 000 000            | 2 ms                  | 21                          | 2 ms              | 21                      |
| 10 000 000           | 40 ms                 | 25                          | 49 ms             | 25                      |
| 100 000 000          | 380 ms                | 28                          | 422 ms            | 28                      |

Išvados: Tiek std::vector, tiek realizuotas Vector konteineriai atliko vienodą skaičių atminties perskirstymų visais testuotais dydžiais.
std::vector visais atvejais veikė šiek tiek greičiau nei realizuotas Vector.

std::vector ir sukurto konteinerio Vector spartos palyginimas:

| Failo dydis    | std::vector      | Vector          |
|----------------|------------------|-----------------|
| 100 000        | 0.25475 s        | 0.350412 s      |
| 1 000 000      | 2.64173 s        | 3.7302 s        |
| 10 000 000     | 29.3114 s        | 61.2496 s       |

Rezultatų analizė: Atlikus std::vector ir Vector realizacijos spartos palyginimą, matyti tendencija, kad visais testuotais atvejais std::vector yra greitesnis.
Skirtumas tampa ypač ryškus didėjant duomenų kiekiui: esant 100 000 įrašų, skirtumas dar nedidelis, tačiau prie 10 000 000 įrašų Vector jau yra daugiau nei 
dvigubai lėtesnis. Tai rodo, kad standartinė bibliotekos realizacija yra stipriai optimizuota (atminties valdymas, kopijavimas, alokacijų strategijos), 
o rankiniu būdu sukurta Vector versija, nors funkcionaliai teisinga, spartos atžvilgiu jai neprilygsta. std::vector yra efektyvesnis pasirinkimas dideliems 
duomenų kiekiams.

## Naudojimosi instrukcija

Įsitikinkite, kad turite įdiegtą CMake (minimali rekomenduojama versija yra 3.10). Atidarykite terminalą ir nueikite į projekto katalogą. 

**Programos paruošimas naudojimuisi:** (šituos žingsnius reikia daryti tik pirmą kartą leidžiant programą)
1. Paruoškite programą kompiliavimui: cmake -S . -B build
2. Suompiliuokite programą (jei kažką pakeotėte savo kode, prieš paleisdami programą būtinai pakartokite šią komandą (perkompiliuokite
   projektą)): cmake --build build --config Release
(jei kažką pakeitėte kode, prieš paleisdami programą būtinai ištrinkite pagrindiniame programos kataloge aplankalą build ir pakartokite visas komandas iš naujo)

**Programos paleidimas:**

Norėdami paleisti programą, terminale įveskite komandą: build\output\Release\programa.exe

Norėdami paleisti testus, terminale įveskite komandą (pasirinktinai vieną iš trijų, priklausomai nuo to, kurį testą norite paleisti): 
• build\Release\student_tests.exe
• build\Release\vector_tests.exe
• build\Release\benchmark_tests.exe
