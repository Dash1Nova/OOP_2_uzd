# Aprašymas

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

| Versija                  | exe failo dydis su O1 (KB)     | exe failo dydis su O2 (KB)    | exe failo dydis su O3 (KB)     |
|--------------------------|--------------------------------|-------------------------------|--------------------------------|
| Struktūra                | 459                            | 431                           | 429                            |
| Klasė                    | 459                            | 431                           | 438                            |

Išvada: Teoriškai -O3 optimizacija turėjo būti sparčiausia visais atvejais, tačiau praktiškai -O2 optimizavimas buvo sparčiausias, tiek su struktūra, tiek su klase
abiejų failų dydžių atveju, o -O3 optimizacija net pablogina veikimą. Tarp struktūros ir klasės pagal vykdymo greitį skirtumų beveik nėra. -O3 gali turėti labai 
daug instrukcijų, kurios netelpa į L1 cache atmintį, tad CPU tenka laukti instrukcijų iš šiek tiek lėtesnių L2/L3, dėl to optimizacija gali būti neefektyvi. Todėl 
efektyviausia optimizacija dažnai gali būti su -O2 vėliavėle.
