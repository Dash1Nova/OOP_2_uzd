# OOP-projects

Po pilnai veikiančios pagal reikalavimus studentų duomenų apdorojimo programos paruošimo buvo atlikti du tyrimai programos veikimo spartos analizei. 
Pirmo tyrimo metu buvo tikrinama failų kūrimo ir uždarymo sparta. Antras tyrimas susidėjo iš 4 dalių, kurių metu buvo tikrinamas programos sparta atliekant
duomenų skaitymą iš failo, studentų rūšiavimą į du konteinerius, surūšiuotų studentų išvedimo greitis į du atskirus failus bei visos programos veikimo laikas.
Laikas buvo matuojamas naudojant C++ biblioteką <chrono>. Testai buvo vykdomi Release režime, kad kompiliatorius pritaikytų optimizacijas ir būtų gauti tikslesni 
programos veikimo spartos rezultatai.
Tokiu būdu matome, kiek laiko užtrunka kiekviena programos dalis, galime nustatyti, kurios dalys vykdomos lėčiausiai ir gerinti silpnas vietas.

## Laiko matavimų lentelė

| Failo dydis      | Failo kūrimas (s) | Skaitymas (s) | Rūšiavimas į du konteinerius (s) | Rašymas į atskirus failus (s) | Visa programa (s) |
|------------------|-------------------|---------------|----------------------------------|-------------------------------|-------------------|
| 1 000            | 0.005767          | 0.0028718     | 0.002425                         | 0.0210852                     | 1.2998            |
| 10 000           | 0.0275736         | 0.0207353     | 0.0292446                        | 0.0202617                     | 1.60032           |
| 100 000          | 0.259573          | 0.176036      | 0.333655                         | 0.193951                      | 1.93223           |
| 1 000 000        | 2.25835           | 1.77256       | 3.71253                          | 1.45557                       | 8.86409           |
| 10 000 000       | 20.7622           | 16.9433       | 34.345                           | 14.0868                       | 66.2593           |

## Pakartotinų matavimų lentelė

| Failo dydis     | Failo kūrimas (s) | Skaitymas (s) | Rūšiavimas į du konteinerius (s) | Rašymas į atskirus failus (s) | Visa programa (s) |
|-----------------|-----------------|---------------|-------------------------------------|-------------------------------|-------------------|
| 1 000           | 0.0032826       | 0.0021928     | 0.0030114                           | 0.0044149                     | 1.20001           |
| 10 000          | 0.0352672       | 0.0179211     | 0.0301482                           | 0.0169855                     | 1.52166           |
| 100 000         | 0.22428         | 0.180301      | 0.323114                            | 0.179897                      | 2.24484           |
| 1 000 000       | 2.728           | 1.60885       | 3.57436                             | 1.41626                       | 7.45123           |
| 10 000 000      | 23.8479         | 16.0669       | 33.94                               | 12.5137                       | 63.6776           |

## Laiko matavimų vidurkis

| Failo dydis     | Failo kūrimas (s) | Skaitymas (s) | Rūšiavimas į du konteinerius (s) | Rašymas į atskirus failus (s) | Visa programa (s) |
|-----------------|-----------------|---------------|-------------------------------------|-------------------------------|-------------------|
| 1 000           | 0.0045248       | 0.0025323     | 0.0027182                           | 0.01275005                    | 1.249905          |
| 10 000          | 0.0314204       | 0.0193282     | 0.0296964                           | 0.0186236                     | 1.56099           |
| 100 000         | 0.2419265       | 0.1781685     | 0.3283845                           | 0.186924                      | 2.088535          |
| 1 000 000       | 2.483175        | 2.25028       | 3.643445                            | 1.435915                      | 8.15766           |
| 10 000 000      | 22.30505        | 16.5051       | 34.1425                             | 13.30025                      | 64.96845          |

Patvirtinimai, kad testavimai tikrai įvyko:

<img width="618" height="293" alt="Ekrano kopija 2026-03-13 002107" src="https://github.com/user-attachments/assets/bcca40cd-4ecb-4a6d-995b-3bc8bf87f058" />
<img width="618" height="293" alt="Ekrano kopija 2026-03-13 002228" src="https://github.com/user-attachments/assets/5c905760-de15-48c0-9e21-3d155148fcc9" />
<img width="618" height="293" alt="Ekrano kopija 2026-03-13 002439" src="https://github.com/user-attachments/assets/ff958a9b-b3e8-4d21-a57b-64662779376e" />
<img width="618" height="293" alt="Ekrano kopija 2026-03-13 002346" src="https://github.com/user-attachments/assets/b58556d1-7831-4e1e-9d82-649d08a0e0c1" />
