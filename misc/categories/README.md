## Categorie

Si scriva la parte rilevante ed autoconsistente del codice di una macro di ROOT in cui:

1. Si definisce un istogramma monodimensionale di 4 bin in un range da 0 a 4.
2. Si generi una popolazione di $10^6$ elementi appartenenti a 4 categorie distinte, con rispettive probabilità di occorrenza:
    - Caso 0: 60\%
    - Caso 1: 30\%
    - Caso 2: 9\%
    - Caso 3: 1\%
3. Si stampi a schermo il contenuto dei 4 bin dell'istogramma e relativa incertezza usando i metodi espliciti degli istogrammi `GetBinContent()` e `GetBinError()`.
