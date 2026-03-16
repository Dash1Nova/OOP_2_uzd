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
| 1 000            | 0.0039051              | 0.0028184            | 0.0040525             |
| 10 000           | 0.0462252              | 0.0288768            | 0.0523639             |
| 100 000          | 0.429439               | 0.274104             | 0.556682              |
| 1 000 000        | 4.77036                | 3.40731              | 4.76253               |
| 10 000 000       | 42.2489                | 31.9924              | 51.5385               |

## Pakartotinų matavimų lentelė

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.0039559              | 0.0024322            | 0.0031749             |
| 10 000           | 0.0405323              | 0.0230306            | 0.0375215             |
| 100 000          | 0.437907               | 0.244227             | 0.388238              |
| 1 000 000        | 4.6027                 | 3.45667              | 5.48064               |
| 10 000 000       | 44.4281                | 30.79                | 52.7474                |

## Laiko matavimų vidurkis

| Failo dydis      | Programa su vector (s) | Programa su list (s) | Programa su deque (s) |
|------------------|------------------------|----------------------|-----------------------|
| 1 000            | 0.0039305              |             | 0.0036137              |
| 10 000           | 0.04337875             |             | 0.0449427             |
| 100 000          | 0.433673               |              | 0.47246              |
| 1 000 000        | 4.68653                |               | 5.121585               |
| 10 000 000       | 43.3385                |               | 52.14295                |
