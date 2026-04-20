# Aprašymas

Ši programa skirta studentų duomenų valdymui.
Programos Student klasė saugo studento vardą, pavardę, namu darbų pažymius, egzamino pažymius bei apskaičiuoja
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
1. išvedimui į ekraną (cout)
2. išvedimui į failą (ofstream)

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
