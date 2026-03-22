# OOP-projects

## Pradinis release
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

| Failo dydis      | Programa su vector (s) | Programa su deque (s) | Programa su list (s)  |
|------------------|------------------------|-----------------------|-----------------------|
| 1 000            | 0.0025965              | 0.0038267               | 0.0045774             |
| 10 000           | 0.0240397              | 0.0348786               | 0.0399093             |
| 100 000          | 0.251026               | 0.391669                | 0.406059              |
| 1 000 000        | 2.69237                | 3.66061                 | 5.25595               |
| 10 000 000       | 28.6223                | 38.4407                 | 75.7796               |

## Pakartotinų matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su deque (s) | Programa su list (s)  |
|------------------|------------------------|-------------------------|-----------------------|
| 1 000            | 0.0021545              | 0.0038351               | 0.0042615             |
| 10 000           | 0.0244451              | 0.0352858               | 0.0406209             |
| 100 000          | 0.240826               | 0.33215                 | 0.409808              |
| 1 000 000        | 2.58996                | 3.44048                 | 5.09296               |
| 10 000 000       | 30.7998                | 40.8123                 | 75.8356               |

## Laiko matavimų vidurkis

| Failo dydis      | Programa su vector (s) | Programa su deque (s) | Programa su list (s)  |
|------------------|------------------------|-----------------------|-----------------------|
| 1 000            |              |              |              |
| 10 000           |               |             |              |
| 100 000          |               |             |               |
| 1 000 000        |                |               |                |
| 10 000 000       |                |              |               |

Pagal laiko matavimų rezultatus matosi, jog sparčiausiai programa veikė su std::list tipo konteineriais, o lėčiausiai su std::deque, nors teoriškai sparčiausias
turėjo būti std::vector, o lėčiausias std::list. Taip galėjo nutikti dėl kelių priežasčių: 
1. naudojamoje Student struktūroje yra dinaminės atminties objektų (pvz., std::vector ar std::string), todėl rūšiavimo ir kopijavimo metu gali atsirasti
   papildomos atminties valdymo sąnaudos;
2. std::list konteineris rūšiuodamas naudoja savo merge sort algoritmą, kuris perjungia elementų rodykles, o ne perkelia pačius objektus;
3. matavimo rezultatus taip pat gali paveikti kompiuterio architektūra, atminties talpyklos (cache) veikimas, kompiliatoriaus optimizacijos.
Dėl šių priežasčių gauti praktiniai rezultatai galėjo ne visiškai sutapti su teorinėmis prielaidomis.

## Galutinis release
Po pradinio relese išleidimo buvo padarytas programos optimizavimas 3 skirtingomis strategijomis su fiksuotu konteneriu - std::vector. 

| Failo dydis      | 1 strategija (s) - for ciklas | 2 strategija (s) - erase | 3 strategija (s) - std::partition |
|------------------|-------------------------------|--------------------------|-----------------------------------|
| 1 000            | 0.0030354                     | 0.0371157                | 0.0025987                         |
| 10 000           | 0.0240486                     | 3.45011                  | 0.0255509                         |
| 100 000          | 0.28094                       | 385.784                  | 0.276189                          |
| 1 000 000        | 2.72145                       |               | 3.0776                    |
| 10 000 000       | 31.6804                       |               | 33.412                    |
