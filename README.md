# GraphToTxt - Konwersja plików `.csrrg` na tekst  

## Opis  
GraphToTxt to narzędzie do przetwarzania plików `.csrrg`, generujące ich reprezentację w postaci opisu macierzowego grafu oraz listy krawędzi w czytelnym formacie `.txt`. Program automatycznie analizuje wszystkie pliki `.csrrg` w katalogu `graphs/` i zapisuje wyniki w katalogu `output/`.  

## Kompilacja
Skompiluj program a pomocą Makefile.

## Użycie  
Automatyczna konwersja plików `.csrrg`:  
1. Umieść pliki `.csrrg` w katalogu `graphs/`.  
2. Uruchom program w systemie wpisując `./graphtotxt`
3. Pliki wynikowe `.txt` zostaną zapisane w katalogu `output/` pod tymi samymi nazwami co wejściowe `.csrrg`.  

Przykład:  
- `graphs/sample.csrrg` → `output/sample.txt`  

Struktura pliku wyjściowego zawiera:  
1. Opis macierzowy grafu:  
   [0 1 0 0 1]  
   [1 0 1 0 0]  
   [0 1 0 1 1]  

2. Listę krawędzi:  
   0 - 1  
   1 - 2  
   2 - 3  

## Czyszczenie plików  
Aby usunąć skompilowane pliki i wyniki w `output/`, użyj komendy:  
`make clean`.  
Spowoduje to usunięcie pliku `graphtotxt.exe`, plików `.o` oraz wszystkich wynikowych plików `.txt`.  

## Zadanie
Dane będace wynikami eksperymentu zostały zareprezentowane jako graf, w którym wierzchołki odpowiadają wartością, a krawędzie — połączeniami. Na tych wartościach miają być przeprowadzane różne obliczenie, które chcemy rozdzielić między 5 procesorami. Każdy procesor ma przetwarzać jeden fragment danych.

Twoim zadaniem jest:

    Wczytać graf z pliku w postaci listy krawędzi, przekształcić go do reprezentacji macierzowej i listowej.
    Podzielić graf na 5 części, tak aby każdy procesor miał zbliżoną liczbę wierzchołków, a liczba połączeń między partycjami była możliwie najmniejsza.
