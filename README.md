# OOP-projects

## Laiko matavimu lentele

Turint pilnai veikiančią pagal reikalavimus studentų duomenų apdorojimo programą, buvo atlikti du tyrimai programos veikimo spartos analizei. 
Pirmo tyrimo metu buvo tikrinama failų kūrimo ir uždarymo sparta. Antras tyrimas susidėjo iš 4 dalių, kurių metu buvo tikrinamas programos sparta atliekant
duomenų skaitymą iš failo, studentų rūšiavimą į du konteinerius, surūšiuotų studentų išvedimo greitis į du atskirus failus bei visos programos veikimo laikas.
Laikas buvo matuojamas naudojant C++ biblioteką <chrono>. Testai buvo vykdomi Release režime, kad kompiliatorius pritaikytų optimizacijas ir būtų gauti tikslesni programos 
veikimo spartos rezultatai.
Tokiu būdu matome, kiek laiko užtrunka kiekviena programos dalis, galime nustatyti, kurios dalys vykdomos lėčiausiai ir gerinti silpnas vietas.

| Failo dydis | Failo kūrimas (s) | Skaitymas (s) | Rūšiavimas į du konteinerius (s) | Rašymas į atskirus failus (s) | Visa programa (s) |
|-------------|-------------------|---------------|----------------------------------|-------------------------------|-------------------|
| 1 000       | 0.005767          | 0.0022894     | 0.0017352                        | 0.0042135                     | 1.17899           |
| 10 000      | 0.0275736         | 0.0171472     | 0.0275898                        | 0.0220545                     | 1.62863           |
| 100 000     | 0.259573          | 0.171621      | 0.26796                          | 0.184584                      | 1.84536           |
| 1 000 000   | 2.25835           | 1.62542       | 2.91679                          | 1.3267                        | 7.45874           |
| 10 000 000  | 20.7622           | 14.1653       | 27.4373                          | 12.8351                       | 55.7296           |

# Pakartotinu matavimu lentele

| Failo dydis | Failo kūrimas (s) | Skaitymas (s) | Rūšiavimas į du konteinerius (s) | Rašymas į atskirus failus (s) | Visa programa (s) |
|------------|-----------------|---------------|-------------------------------------|-------------------------------|-------------------|
| 1 000      | 0.0032826       | 0.0020931     | 0.0020865                           | 0.0046362                     | 1.35108           |
| 10 000     | 0.0352672       | 0.0256299     | 0.0224583                           | 0.017987                      | 1.90163           |
| 100 000    | 0.22428         | 0.177366      | 0.34176                             | 0.170665                      | 1.77632           |
| 1 000 000  | 2.728           | 1.60951       | 2.34987                             | 1.15905                       | 7.64221           |
| 10 000 000 | 23.8479         | 14.5513       | 26.6695                             | 13.2392                       | 55.324            |

# Laiko matavimu vidurkis

| Failo dydis | Failo kūrimas (s) | Skaitymas (s) | Rūšiavimas į du konteinerius (s) | Rašymas į atskirus failus (s) | Visa programa (s) |
|------------|-----------------|---------------|-------------------------------------|-------------------------------|-------------------|
| 1 000      | 0.0045248       | 0.00219125     | 0.00191085                           | 0.00442485                     | 1.265035           |
| 10 000     | 0.0314204       | 0.02138855     | 0.02502405                           | 0.02002075                      | 1.76513           |
| 100 000    | 0.2419265       | 0.1744935      | 0.30486                             | 0.1776245                      | 1.81084           |
| 1 000 000  | 2.483175        | 1.617465       | 2.63333                             | 1.242875                       | 7.550475           |
| 10 000 000 | 22.30505        | 14.3583       | 27.0534                             | 13.03715                       | 55.5268            |

Patvirtinimai, kad testavimai tikrai įvyko:

<img width="618" height="293" alt="Ekrano kopija 2026-03-13 002107" src="https://github.com/user-attachments/assets/bcca40cd-4ecb-4a6d-995b-3bc8bf87f058" />
<img width="621" height="297" alt="Ekrano kopija 2026-03-13 002228" src="https://github.com/user-attachments/assets/5c905760-de15-48c0-9e21-3d155148fcc9" />
<img width="641" height="302" alt="Ekrano kopija 2026-03-13 002439" src="https://github.com/user-attachments/assets/ff958a9b-b3e8-4d21-a57b-64662779376e" />
<img width="708" height="278" alt="Ekrano kopija 2026-03-13 002346" src="https://github.com/user-attachments/assets/b58556d1-7831-4e1e-9d82-649d08a0e0c1" />
