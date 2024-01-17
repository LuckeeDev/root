## Collezione di macro di [ROOT](https://root.cern)

Questa repo contiene una collezione di esercizi e macro realizzati con [ROOT](https://root.cern), il framework di analisi dati utilizzato durante il corso "Laboratorio di Meccanica e Termodinamica" presso l'Università di Bologna nell'A.A. 2022/2023.

#### Indice

-   Esami del primo anno
    -   [15/06/2023](exams/first_year/230615)
    -   [06/09/2022](exams/first_year/220906)
    -   [12/07/2022](exams/first_year/220712)
    -   [23/06/2021](exams/first_year/210623)
    -   [10/06/2019](exams/first_year/190610)
    -   [07/02/2019](exams/first_year/190207)
    -   [08/06/2018](exams/first_year/180608)
-   Esami del secondo anno
    -   [15/01/2018](exams/second_year/180115)
    -   [26/06/2018](exams/second_year/180626)
-   Altri esercizi
    -   [Somma di una gaussiana e un'uniforme](misc/gauss_uniform)
    -   [Hit or miss](misc/hit_or_miss)
-   Laboratori
    -   [Misura di G](lab/gravity)

#### Istruzioni

Per eseguire le macro presenti nella repository è necessario avere ROOT installato sul proprio sistema. Possono essere eseguite spostandosi nella directory d'interesse, lanciando ROOT ed eseguendo il comando `.x macro.C`.

Per far funzionare l'intellisense di Visual Studio Code è necessario modificare il file `.vscode/c_cpp_properties.json` e indicare al posto di `~/programs/root/include` la directory in cui si trovano gli header file di ROOT sul proprio sistema.
