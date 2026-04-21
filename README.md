# Aprašymas
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
