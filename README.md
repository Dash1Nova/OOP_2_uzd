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
