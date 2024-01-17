# Somma di una gaussiana e un'uniforme

Si scriva una macro in cui:

1. Si definiscono 2 istogrammi monodimensionali di 500 bin in un range da 0. a 5.;
2. Si riempie il primo istogramma con $10^6$ occorrenze generate esplicitamente e singolarmente secondo gaussiana con media 2.5 e deviazione standard 0.25;
3. Si riempie il secondo istogramma con $10^4$ occorrenze generate esplicitamente e singolarmente secondo una distribuzione uniforme nel range $[0,5]$;
4. Si fa la somma dei due istogrammi, e si effettua il fit dell'istogramma somma secondo una forma funzionale consistente di una gaussiana (3 parametri: ampiezza, media e deviazione standard) e un polinomio di grado 0 (1 parametro), per un totale di 4 parametri liberi.
5. Si stampa a schermo il valore dei parametri dopo il fit, con relativo errore, e il $\chi ^2$ ridotto.
