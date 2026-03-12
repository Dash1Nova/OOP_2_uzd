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
