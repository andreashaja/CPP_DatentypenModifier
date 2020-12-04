/* ---------------------------------------------------------------------
 * The Fearless Engineer - Programmieren und Elektronik
 * Copyright (C) 2020, Dr. Andreas Haja.  
 *
 * Zweck : Übungsaufgaben zu elementaren Datentypen und Modifiern in C++
 *
 * Du solltest zusammen mit diesem Programm eine Kopie der MIT-Lizenz erhalten haben.
 * Falls nicht, sieh bitte hier nach: https://opensource.org/licenses/MIT.
 *
 * Das Begleitheft zum Modul E2_M3 kann hier geladen werden:
 * http://www.thefearlessengineer.com/cpp-kurs-e2
 * ----------------------------------------------------------------------
 */

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{

    ///////// AUFGABE 1 START /////////
    ///////// Numerische Ableitung

    // Hintergrund: 
    // Im nachfolgenden Code wird die Ableitung der Cosinus-Funktion an der Stelle 3/2 PI numerisch berechnet.
    // --> Infos zur Berechnung von Ableitungen https://www.mathe-online.at/mathint/diff1/i.html (Abschnitt "Berechnung der Ableitung")
    // Da der Abstand zwischen x1 und x2 aber mit 1e-5 relativ groß ist, wird die Ableitung nur ungenau berechnet.
    
    // Deine Aufgabe: 
    // Verkleinere dx auf 1e-10, damit das Ergebnis der Ableitung näher am wahren Wert ist. Weicht das Ergebnis von der Erwartung ab, überprüfe die einzelnen Schritte und passe ggf. den Code an
    
    float dx = 1e-5;
    float x1 = 1.5 * M_PI;
    float x2 = x1 + dx;
    float dy_dx = (cos(x2) - cos(x1)) / dx;
    cout << "Ergebnis der Ableitung = " << dy_dx << endl;

    /////////
    ///////// AUFGABE 1 ENDE /////////
    


    ///////// AUFGABE 2 START /////////
    ///////// Vergleich von Fließkommazahlen

    // Hintergrund : In der Praxis kommt es häufig vor, dass Fließkommazahlen mit einem vorgegebenen Wert verglichen werden sollen. 
    // Im nachstehenden Code soll z.B. immer dann, wenn die Sinus-Funktion einen Nulldurchgang hat, eine Ausgabe im Terminal erfolgen. 
    // Obwohl der von der while-Schleife überstrichene Wertebereich drei Nulldurchgänge abdeckt (bei 0, PI und 2*PI), wird nur einmal der Text innerhalb der if-Abfrage ausgegeben.

    // Deine Aufgabe: 
    // Passe die if-Abfrage so an, dass diese mit kleineren Abweichungen von 0.0 umgehen kann und insgesamt drei Ausgaben im Intervall 0..2*PI erfolgen.
    

    int cnt = 0;
    while (cnt <= 8)
    {
        double angle = cnt * M_PI_4;
        double result = sin(angle);
        
        if (result == 0.0)
        {
            printf("sin(%3.4f)=%3.4f\n", angle, result);
        }
        
        cnt++;
    }

    /////////
    ///////// AUFGABE 2 ENDE /////////


    ///////// AUFGABE 3 START /////////
    /////////

    // Hintergrund: 
    // Bei der Speicherung von Bildern und Videos ist es wichtig, den Datentyp so gut wie möglich an den Wertebereich der Daten anzupassen, damit kein Speicher verschwendet wird. 
    // Im nachstehenden Code wird die Größe eines Videos auf der Basis einiger typischer Parameter in MByte berechnet und ausgegeben. 

    // Deine Aufgabe: 
    // Berechne die Größe des Videos, wenn zur Speicherung der (nicht optimal gewählte) Datentyp "short int" gewählt wird und gib diese im Terminal aus.

    int res_x = 1920;       // Auflösung in x
    int res_y = 1080;       // Auflösung in y
    int color_channels = 3; // Anzahl der Farbkanäle
    int color_depth = 1;    // Farbtiefe in Byte
    int frame_rate = 30;    // Bildfrequenz
    int duration = 120;     // Länge des Videos in Sekunden
    int total_size = res_x * res_y * color_channels * color_depth * frame_rate * duration / (1024 * 1024);
    cout << "Größe des Videos in MByte = " << total_size << endl;

    int storage_size = 0; // Bitte hier deine Berechnung einfügen
    cout << "Größe des Videos in MByte bei Verwendung von 'short int' = " << storage_size << endl;

    /////////
    ///////// AUFGABE 3 ENDE /////////



    ///////// AUFGABE 4 START /////////
    /////////

    // Hintergrund: Die Berechnung von Zufallszahlen wird in der Praxis oft genutzt, um z.B. Elemente aus einer Liste auszuwählen. 
    // In C++ kann hierzu die Funktion rand() genutzt werden, die Zufallszahlen im Wertebereich zwischen 0 und RAND_MAX generiert. 
    // Soll der Wertebereich begrenzt werden, so kann mit der Modulo-Funktion (%) der kleinere Wertebereich erzeugt werden. 
    // Die Operation "rand() % 10" erzeugt z.B. Zufallszahlen im Wertebereich von 0 bis 9.

    // Deine Aufgabe: 
    // Im folgenden Code ist der Datentyp der beiden Variablen zur Speicherung von Zufallszahlen (rand_large und rand_small) nicht optimal gewählt. 
    // Welchen Datentyp (ggf. inkl. Modifier) musst du wählen, damit möglichst wenig Speicher verschwendet wird?

    // Wertebereich mit Modifiern einstellen
    cout << RAND_MAX << endl; // Maximale Größe einer erzeugten Zufallszahl
    cnt = 0;
    long rand_large{0}; // Bitte hier den Datentyp optimieren
    long rand_small{0}; // Bitte hier den Datentyp optimieren
    while (cnt < 10)
    {
        rand_large = rand();
        rand_small = rand_large % 65535; // Wertebereich der Zufallszahlen reduzieren
        cout << "rand_large = " << rand_large << ", rand_small = " << rand_small << endl;
        ++cnt;
    }
    cout << "Größe von rand_large im Speicher in Byte = " << sizeof(rand_large) << endl;
    cout << "Größe von rand_small im Speicher in Byte = " << sizeof(rand_small) << endl;

    /////////
    ///////// AUFGABE 4 ENDE /////////
}