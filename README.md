# OOP-projects

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
| 1 000            | 0.005767               | 0.0028718            | 0.002425              |
| 10 000           | 0.0275736              | 0.0207353            | 0.0292446             |
| 100 000          | 0.259573               | 0.176036             | 0.333655              |
| 1 000 000        | 2.25835                | 1.77256              | 3.71253               |
| 10 000 000       | 20.7622                | 16.9433              | 34.345                |

## Pakartotinų matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.005767               | 0.0028718            | 0.002425              |
| 10 000           | 0.0275736              | 0.0207353            | 0.0292446             |
| 100 000          | 0.259573               | 0.176036             | 0.333655              |
| 1 000 000        | 2.25835                | 1.77256              | 3.71253               |
| 10 000 000       | 20.7622                | 16.9433              | 34.345                |

## Laiko matavimų vidurkis

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.005767               | 0.0028718            | 0.002425              |
| 10 000           | 0.0275736              | 0.0207353            | 0.0292446             |
| 100 000          | 0.259573               | 0.176036             | 0.333655              |
| 1 000 000        | 2.25835                | 1.77256              | 3.71253               |
| 10 000 000       | 20.7622                | 16.9433              | 34.345                |
