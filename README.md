# Zestaw5
# Język C++ WFAIS.IF-A207.0
## Zestaw 5: Zadanie ASCII Renderer

### Opis projektu

Zaprojektuj i napisz program w języku C++, który tworzy obrazki w formie plików ASCII. Projekt składa się z kilku kroków, w których zaimplementujesz klasy reprezentujące "canvas" oraz różne kształty, a także umożliwisz rysowanie tych kształtów na canvasie. Dodatkowo, plik konfiguracyjny będzie sterować procesem rysowania, a wynikowy obrazek zostanie zapisany w formacie ASCII.

### Krok 1: Klasa Canvas
- Zaimplementuj abstrakcyjną klasę `Canvas` reprezentującą obszar rysowania.
- Dziedzicz po niej klasę `ASCIICanvas`.
- Klasa `Canvas` powinna umożliwiać zdefiniowanie wysokości i szerokości (liczba linii i liczba znaków w każdej linii).

### Krok 2: Klasa Figure i jej pochodne
- Zdefiniuj abstrakcyjną klasę `Figure`, z której będą dziedziczyć konkretne figury takie jak koło, kwadrat, prostokąt, trójkąt.
- Każda figura powinna posiadać współrzędne oraz wymiary, np. promień dla koła.
- Każda figura powinna posiadać metodę `draw(Canvas &c)`, która rysuje figurę na canvasie.
- Piksele obrazka powinny być wypełniane różnymi symbolami w zależności od tego, czy należą do figury, czy nie. Symbole te będą ustalane w pliku konfiguracyjnym.

### Krok 3: Plik konfiguracyjny
- Plik konfiguracyjny będzie zawierał:
  - Wymiary canvasu.
  - Nazwę pliku wyjściowego z obrazkiem.
  - Symbol oznaczający piksel nienależący do żadnej figury.
  - Listę figur do narysowania (nazwa figury, współrzędne, wymiary, symbol).
- Program powinien sparsować plik konfiguracyjny, stworzyć odpowiednie obiekty i wypełnić obrazek, zapisując go w pliku ASCII.

### Krok 4: Repozytorium na GitHub
- Projekt umieść w repozytorium na GitHubie.
- README.md dołączone do projektu powinno wyjaśniać, czego dotyczy projekt, jak go ściągnąć, jak go skompilować i jak go używać.
- Do repozytorium dołącz przykładowy plik konfiguracyjny.

### Podpunkt dodatkowy: Klasa Light
- Stwórz klasę `Light` reprezentującą punktowe źródło światła.
- Obiekt `Light` powinien rzucać cień na canvasie, a jego położenie i symbol cienia powinny być określone w pliku konfiguracyjnym.

### Przykład pliku konfiguracyjnego

```txt
canvas_width=20
canvas_height=10
output_file=output.txt
background_symbol= 
figures=[
  {
    type=square,
    x=2,
    y=2,
    size=2,
    symbol=#
  },
  {
    type=square,
    x=6,
    y=5,
    size=3,
    symbol=#
  }
]
