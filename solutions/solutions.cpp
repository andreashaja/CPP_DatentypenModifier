/* ---------------------------------------------------------------------
 * The Fearless Engineer - Programmieren und Elektronik
 * Copyright (C) 2020, Dr. Andreas Haja.  
 *
 * Zweck : Übungsaufgaben zu elementaren Datentypen und Modifiern in C++
 *         MUSTERLÖSUNGEN
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

    // Hintergrund : 
    // 
    
    // Aufgabe : Gib aus, wenn die Funktion sin(angle) einen Nulldurchgang hat
    // Lernziel : Wird nicht jeder Nulldurchgang ausgegeben, überprüfe die if-Bedingung und passe sie an
    int cnt = 0;
    while (cnt <= 8)
    {
        double angle = cnt * M_PI_4;
        double result = sin(angle);
        if (result == 0.0)
        //double eps = 1e-3;
        //if( (result-eps)<=0.0 && (result+eps)>=0.0 )
        {
            printf("sin(%3.4f)=%3.4f)\n", angle, result);
        }
        cnt++;
    }

    /////////
    ///////// AUFGABE 2 ENDE /////////


    ///////// AUFGABE 3 START /////////
    /////////

    // Berechnungsmethode für Bildgröße in MByte, bei der Variablen für x, y, c genutzt werden
    // Aufgabe : Berechne die Größe eines Videos in MByte
    int res_x = 1920;       // Auflösung in x
    int res_y = 1080;       // Auflösung in y
    int color_channels = 3; // Anzahl der Farbkanäle
    int color_depth = 1;    // Farbtiefe in Byte
    int frame_rate = 30;    // Bildfrequenz
    int duration = 120;     // Länge des Videos in Sekunden
    int total_size = res_x * res_y * color_channels * color_depth * frame_rate * duration / (1024 * 1024);
    cout << "Größe des Videos in MByte = " << total_size << endl;

    /////////
    ///////// AUFGABE 3 ENDE /////////



    ///////// AUFGABE 4 START /////////
    /////////

    // Wertebereich mit Modifiern einstellen
    cout << RAND_MAX << endl; // Maximale Größe einer erzeugten Zufallszahl
    cnt = 0;
    int rand_large{0};                // Datentyp maßschneidern
    unsigned short int rand_small{0}; // Datentyp maßschneidern
    while (cnt < 50)
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